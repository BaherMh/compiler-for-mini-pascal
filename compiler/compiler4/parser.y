%{
	#include "ast.h"
	#include <iostream>
	
	using std::cout;
	using std::endl;
	extern int lin, col;
	Root* rt;
	extern int yylex();
	extern int yydebug;
	extern int yyerror(const char*);

	SymbolTable* symbolTable = new SymbolTable();
	bool para_lst = 0;
%}
%debug

%token BOOLEAN REAL INTEGER VAR ARRAY DIGIT
%token INTNUM REALNUM STRINGNUM IDENT
%token IF ELSE THEN WHILE DO OF RETURN
%token TRUE FALSE
%token AND OR NOT DIV
%token PROGRAM FUNCTION PROCEDURE BEG END ASSIGNMENT
%token LE LESS GE GREATER EQ NE 


%left OR
%left AND
%left NOT
%left NE EQ
%left LESS GREATER LE GE 
%left '+' '-'
%left '*' '/' DIV
 



 %union{
 Ident* tIdent;
 Identifier_list* tIdentifier_list;
 Declarations* tDeclarations;
 Type* tType;
 Root* tRoot;
 Standard_type* tStandard_type;

 Subprogram_declarations* tSubprogram_declarations;
 Subprogram_declaration* tSubprogram_declaration;
 Subprogram_head* tSubprogram_head;
 Arguments* tArguments;
 Parameter_list* tParameter_list;
 Compound_statement* tCompound_statement;
 Optional_statements* tOptional_statements;
 Statement_list* tStatement_list;
 Statement* tStatement;
 Variable* tVariable;
 Procedure_statement* tProcedure_statement;
 Expression_list* tExpression_list;
 Expression* tExpression;
 Unary_operator* tUnary_operator;
 Intnum* tIntnum;
 Realnum* tRealnum;
 }
 %type<tRoot> root;
 %type<tIdentifier_list> identifier_list;
 %type<tDeclarations> declarations;
 %type<tDeclarations> local_declarations;
 %type<tType> type;
 %type<tStandard_type> standard_type;
 %type<tSubprogram_declarations> subprogram_declarations;
 %type<tSubprogram_declaration> subprogram_declaration;
 %type<tSubprogram_head> subprogram_head_function;
 %type<tSubprogram_head> subprogram_head_procedure;
 %type<tArguments> arguments;
 %type<tParameter_list> parameter_list;
 %type<tCompound_statement> compound_statement;
 %type<tOptional_statements> optional_statements;
 %type<tStatement_list> statement_list;
 %type<tStatement> statement;
 %type<tVariable> variable;
 %type<tProcedure_statement> procedure_statement;
 %type<tExpression_list> expression_list;
 %type<tExpression> expression;
 %type<tUnary_operator> unary_operator;
 %token<tIdent> IDENT 
 %token<tIntnum> INTNUM;
 %token<tRealnum> REALNUM;

 %token<string> IF;
 %token<string> THEN;
 %nonassoc "ifelse"
%nonassoc "then"

%nonassoc ELSE
%nonassoc "unary"
%%


root : PROGRAM IDENT ';' declarations {symbolTable->add_declarations($4);} subprogram_declarations compound_statement
		{
			$$ = new Root(lin, col, $2, $4, $6, $7);
			rt = $$;
			

		}
;
identifier_list : IDENT
					{
						$$ = new Identifier_list(lin, col, $1);
					}
				| identifier_list ',' IDENT
					{
						$1->add_ident($3);
						$$ = $1;
					}
;

declarations :  declarations VAR identifier_list ':' type ';'
					{
						symbolTable->current = symbolTable->scopes->at(0);
						pair<Identifier_list*, Type*>* p = new pair<Identifier_list*, Type*>;
						p->first = $3;
						p->second = $5;
						$1->add_declaration(p);
						$$ = $1;
					}
			 | 
					 {
						$$ = new Declarations(lin, col);
					 }
;
type : standard_type
			{
				$$ = new Type_standard_type(lin, col, $1);
			}
		| ARRAY '[' INTNUM ',' ',' INTNUM ']' OF standard_type
			{
				$$ = new Type_array(lin, col, $3, $6, $9);
			}
		;
standard_type : INTEGER
					{
						$$ = new Standard_type_integer(lin, col);
					}
				| REAL
					{
						$$ = new Standard_type_real(lin, col);
					}
				| BOOLEAN
					{
						$$ = new Standard_type_boolean(lin, col);
					}
				| STRINGNUM
					{
						$$ = new Standard_type_string(lin, col);
					}
;
subprogram_declarations : subprogram_declarations subprogram_declaration ';'
							{
								$1->add_subprogram_declaration($2);

								$$ = $1;
							}
						| 
							{
								$$ = new Subprogram_declarations(lin, col);
							}
						;
subprogram_declaration : subprogram_head_function local_declarations {symbolTable->add_local_declarations($2);} compound_statement RETURN expression
							{
								$$ = new Subprogram_declaration(lin, col, $1, $2, $4);
								symbolTable->add_subprogram($$);
								
							}
							|
							subprogram_head_procedure local_declarations {symbolTable->add_local_declarations($2);} compound_statement
							{
								$$ = new Subprogram_declaration(lin, col, $1, $2, $4);
								symbolTable->add_subprogram($$);
								
							}

;

local_declarations : local_declarations VAR identifier_list ':' type ';'
						{
						pair<Identifier_list*, Type*>* p = new pair<Identifier_list*, Type*>;
						p->first = $3;
						p->second = $5;
						$1->add_declaration(p);
						$$ = $1;
						
						}
					| 
						{
							$$ = new Declarations(lin, col);
						}

subprogram_head_function : FUNCTION IDENT {symbolTable->new_scope();} arguments ':' standard_type ';'
					{
						$$ = new Subprogram_head_fucntion(lin, col, $2, $4, $6);
						
					}
subprogram_head_procedure : PROCEDURE IDENT {symbolTable->new_scope();} arguments  ';'
					{
						$$ = new Subprogram_head_procedure(lin, col, $2, $4);
					}
;
arguments : '(' parameter_list ')'
				{
					$$ = new Arguments(lin, col, $2);
					symbolTable->add_parameter_list($2);

				}
			| 
				{
					$$ = new Arguments(lin, col);
				}
			;
parameter_list : identifier_list ':' type
					{
						pair<Identifier_list*, Type*>* p = new pair<Identifier_list*, Type*>;
						p->first = $1;
						p->second = $3;
						$$ = new Parameter_list(lin, col, p);
						
					}
				| parameter_list ';' identifier_list ':' type
					{
						pair<Identifier_list*, Type*>* p = new pair<Identifier_list*, Type*>;
						p->first = $3;
						p->second = $5;
						$1->add_parameter(p);
						$$ = $1;
					}
				;
compound_statement : BEG optional_statements END {symbolTable->close_scope();}
						{
							$$ = new Compound_statement(lin, col, $2);

						}
;
optional_statements : statement_list
						{
							$$ = new Optional_statements_list(lin, col, $1);
						}
					| 
						{
							$$ = new Optional_statements_empty(lin, col);
						}
					;
statement_list : statement
					{
						$$ = new Statement_list(lin, col, $1);
					}
			   | statement_list ';' statement
					{
						$1->add_statement($3);
						$$ = $1;
					}
			   ;

statement : variable ASSIGNMENT expression
				{
					$$ = new Statement_assigment(lin, col, $1, $3);
				}
		  | procedure_statement
				{
					$$ = new Statement_procedure(lin, col, $1);
				}
		  | compound_statement
				{
					$$ = new Statement_compound(lin, col, $1);
				}
		  | IF expression THEN statement %prec "then"
				{
					$$ = new Statement_if(lin, col, $2, $4);
				}
		  | IF expression THEN statement ELSE statement %prec"ifelse"
				{
					$$ = new Statement_if_else(lin, col, $2, $4, $6);
				}
		  | WHILE expression DO statement
				{
					$$ = new Statement_while(lin, col, $2, $4);
				}
		  ;

variable : IDENT
			{
				$$ = new Variable_ident(lin, col, $1);
				symbolTable->lookup_symbol($1);
			}
		 | IDENT '[' expression_list ']'
			{
				$$ = new Variable_expression_list(lin, col, $1, $3);
				symbolTable->lookup_symbol($1);
				cout << "vaaaaaaaaaaaaaaaaaaaaaaaaa\n";
			}
		 ;

procedure_statement : IDENT
						{
							$$ = new Procedure_statement_ident(lin, col, $1);
						}
					| IDENT '(' expression_list ')'
						{
							$$ = new Procedure_statement_expression_list(lin, col, $1, $3);
						}
					;

expression_list : expression
					{
						$$ = new Expression_list(lin, col, $1);
					}
				| expression_list ',' expression
					{
						$1->add_expression($3);
						$$ = $1;
					}
				;
expression : IDENT
				{
					$$ = new Expression_ident(lin, col, $1);
					symbolTable->lookup_symbol($1);
				}
		   | INTNUM
				{
					$$ = new Expression_intnum(lin, col, $1);
				}
		   | REALNUM
				{
					$$ = new Expression_realnum(lin, col, $1);
				}
		   | TRUE
				{
					$$ = new Expression_true(lin, col);
				}
		   | FALSE
				{
					$$ = new Expression_false(lin, col);
				}
		   | IDENT '(' expression_list ')'
				{
					$$ = new Expression_expression_list(lin, col, $1, $3);
					symbolTable->lookup_symbol($1);
				}
		   | '(' expression ')'
				{
					$$ = new Expression_expression(lin, col, $2);
				}
		   | expression unary_operator expression  %prec "unary"
				{
					$$ = new Expression_unary(lin, col, $1, $3, $2);
				}
		   | NOT expression
				{
					$$ = new Expression_not(lin, col, $2);
				}
		   ;
unary_operator : '+'
				{
					$$ = new Unary_operator_plus(lin, col);
				}
			   | '-'
				{
					$$ = new Unary_operator_minus(lin, col);
				}
			   | '*'
				{
					$$ = new Unary_operator_multiply(lin, col);
				}
			   | '/'
				{
					$$ = new Unary_operator_divide(lin, col);
				}
			   | DIV
				{
					$$ = new Unary_operator_div(lin, col);
				}
			   | GE
				{
					$$ = new Unary_operator_ge(lin, col);
				}
			   | LE
				{
					$$ = new Unary_operator_le(lin, col);
				}
			   | GREATER
				{
					$$ = new Unary_operator_greater(lin, col);
				}
			   | LESS
				{
					$$ = new Unary_operator_less(lin, col);
				}
			   | EQ
				{
					$$ = new Unary_operator_eq(lin, col);
				}
			   | NE
				{
					$$ = new Unary_operator_ne(lin, col);
				}
			   | NOT
				{
					$$ = new Unary_operator_not(lin, col);
				}
			   | OR
				{
					$$ = new Unary_operator_or(lin, col);
				}
			   | AND
				{
					$$ = new Unary_operator_and(lin, col);
				}
			   ;

%%
int yyerror(const char* s)
{
	cout << "OOPs, syntax error" << lin << ' ' << col;
	return 1;
}

int main()
{
	yyparse();
	Visitor* print_visitor = new Print_visitor;
	Visitor* type_visitor = new Type_visitor;
	Visitor* code_visitor = new Code_visitor;

	rt->accept(type_visitor);
	rt->accept(code_visitor);
	return 0;
}



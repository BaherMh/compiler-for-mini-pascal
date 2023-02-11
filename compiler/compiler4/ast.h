#pragma once
#pragma once
#include <iostream>
#include <typeinfo>
#include <vector>;
#include "hash_fun.h";
#include "hash_table.h";
#include<fstream>
#include <iomanip>
using namespace std;
using std::ios;
using std::ofstream;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::pair;

static ofstream vout("vm2.txt", ios::out);

class Node;
class Root;
class Ident;
class Declarations;
class Subprogram_declarations;
class Compound_statement;
class Identifier_list;
class Type;
class Standard_type;
class Intnum;
class Realnum;
class Subprogram_declaration;
class Subprogram_head;
class Arguments;
class Parameter_list;
class Optional_statements;
class Optional_statements_empty;
class Optional_statements_list;
class Statement;
class Statement_list;
class Variable;
class Expression;
class Procedure_statement;
class Expression_list;
class Unary_operator;
class Unary_operator_plus;
class Unary_operator_minus;
class Unary_operator_multiply;
class Unary_operator_divide;
class Unary_operator_div;
class Unary_operator_ge;
class Unary_operator_le;
class Unary_operator_greater;
class Unary_operator_less;
class Unary_operator_eq;
class Unary_operator_ne;
class Unary_operator_not;
class Unary_operator_or;
class Unary_operator_and;
class Visitor;
class Print_visitor;


class Type_standard_type;
class Type_array;
class Subprogram_head_fucntion;
class Subprogram_head_procedure;
class Statement_assigment;
class Statement_procedure;
class Procedure_statement_expression_list;
class Procedure_statement_ident;
class Statement_compound;
class Statement_if;
class Statement_if_else;
class Statement_while;
class Variable_ident;
class Variable_expression_list;
class Expression_ident;
class Expression_intnum;
class Expression_realnum;
class Expression_true;
class Expression_false;
class Expression_expression_list;
class Expression_expression;
class Expression_unary;
class Expression_not;


class Symbol;
typedef CHashTable<Symbol> HashTab;

class Node
{
public:
	int line;
	int column;
	Node* father;
	Node(int, int);
	virtual void accept(Visitor*);
};

class Root : public Node
{
public:
	Ident* ident;
	Declarations* declarations;
	Subprogram_declarations* subprogram_declarations;

	Compound_statement* compound_statement;
	Root(int, int, Ident*, Declarations*, Subprogram_declarations*, Compound_statement*);
	virtual void accept(Visitor*);
};

class Ident : public Node
{
public:
	string name;
	Symbol* symbol;
	Ident(int, int, string name);
	virtual void accept(Visitor*);
};




class Declarations : public Node
{
public:
	vector <pair<Identifier_list*, Type*>*>* decs;
	Declarations(int, int);
	Declarations(int, int, pair<Identifier_list*, Type*>*);
	void add_declaration(pair<Identifier_list*, Type*>*);
	virtual void accept(Visitor*);
};
class Identifier_list : public Node
{
public:
	vector<Ident*>* idents;
	Identifier_list(int, int, Ident*);
	void add_ident(Ident*);
	virtual void accept(Visitor*);
};
class Type : public Node
{
public:
	Type(int, int);
	virtual string get_type() = 0;
	virtual void accept(Visitor*);
};

class Type_standard_type : public Type
{
public:
	Standard_type* standard_type;
	Type_standard_type(int, int, Standard_type*);
	virtual string get_type();
	virtual void accept(Visitor*);
};



class Type_array : public Type
{
public:
	Intnum* left;
	Intnum* right;
	Standard_type* type;
	Type_array(int, int, Intnum*, Intnum*, Standard_type*);
	virtual string get_type();
	virtual void accept(Visitor*);
};


class Standard_type : public Node
{
public:
	string name;
	Standard_type(int, int, string);
	virtual void accept(Visitor*) = 0;
	virtual void initialize(Ident*, string) = 0;
	virtual void push_ident(Ident*, string) = 0;
	virtual void unary(string) = 0;
};

class Standard_type_integer : public Standard_type
{
public:
	Standard_type_integer(int, int);
	virtual void accept(Visitor*);
	void initialize(Ident*, string);
	void push_ident(Ident*, string);
	void unary(string);
};
class Standard_type_void : public Standard_type
{
public:
	Standard_type_void(int, int);
	virtual void accept(Visitor*);
	void initialize(Ident*, string);
	void push_ident(Ident*, string);
	void unary(string);
};


class Standard_type_real : public Standard_type
{
public:
	Standard_type_real(int, int);
	virtual void accept(Visitor*);
	void initialize(Ident*, string);
	void push_ident(Ident*, string);
	void unary(string);
};

class Standard_type_boolean : public Standard_type
{
public:
	Standard_type_boolean(int, int);
	virtual void accept(Visitor*);
	void initialize(Ident*, string);
	void push_ident(Ident*, string);
	void unary(string);
};

class Standard_type_string : public Standard_type
{
public:
	Standard_type_string(int, int);
	virtual void accept(Visitor*);
	void initialize(Ident*, string);
	void push_ident(Ident*, string);
	void unary(string);
};

class Subprogram_declarations : public Node
{
public:
	vector<Subprogram_declaration*>* sub_decs;
	Subprogram_declarations(int, int, Subprogram_declaration*);
	Subprogram_declarations(int, int);
	void add_subprogram_declaration(Subprogram_declaration*);

	virtual void accept(Visitor*);
};

class Subprogram_declaration : public Node
{
public:
	Subprogram_head* sh;
	Compound_statement* cs;
	Declarations* local_decs;
	Subprogram_declaration(int, int, Subprogram_head*, Declarations*, Compound_statement*);

	virtual void accept(Visitor*);
};


class Intnum : public Node
{
public:
	int num;
	Intnum(int, int, int);
	virtual void accept(Visitor*);
};


class Realnum : public Node
{
public:
	double num;
	Realnum(int, int, double);
	virtual void accept(Visitor*);
};

class Subprogram_head : public Node
{
public:

	Subprogram_head(int, int);

	Standard_type* type;
	string label;
	Ident* ident;
	Arguments* args;

	virtual void accept(Visitor*);
};

class Subprogram_head_fucntion : public Subprogram_head
{
public:


	Subprogram_head_fucntion(int, int, Ident*, Arguments*, Standard_type*);
	virtual void accept(Visitor*);
};


class Subprogram_head_procedure : public Subprogram_head
{
public:

	Subprogram_head_procedure(int, int, Ident*, Arguments*);
	virtual void accept(Visitor*);
};

class Arguments : public Node
{
public:

	Parameter_list* paras;
	Arguments(int, int, Parameter_list*);
	Arguments(int, int);
	virtual void accept(Visitor*);
};

class Parameter_list : public Node
{
public:

	vector<pair<Identifier_list*, Type*>*>* paras;
	Parameter_list(int, int, pair<Identifier_list*, Type*>*);
	void add_parameter(pair<Identifier_list*, Type*>*);
	virtual void accept(Visitor*);
};

class Compound_statement : public Node
{
public:

	Optional_statements* optional_statement;
	Compound_statement(int, int, Optional_statements*);
	virtual void accept(Visitor*);
};

class Optional_statements : public Node
{
public:

	Optional_statements(int, int);
	virtual void accept(Visitor*);
};

class Optional_statements_list : public Optional_statements
{
public:

	Statement_list* statement_list;
	Optional_statements_list(int, int);
	Optional_statements_list(int, int, Statement_list*);
	virtual void accept(Visitor*);
};

class Optional_statements_empty : public Optional_statements
{
public:

	Optional_statements_empty(int, int);
	virtual void accept(Visitor*);
};

class Statement_list : public Node
{
public:

	vector<Statement*>* statements;
	Statement_list(int, int, Statement*);
	void add_statement(Statement*);
	virtual void accept(Visitor*);
};


class Statement : public Node
{
public:

	Statement(int, int);
	virtual void accept(Visitor*);
};


class Statement_assigment : public Statement
{
public:

	Variable* variable;
	Expression* expression;
	Statement_assigment(int, int, Variable*, Expression*);
	virtual void accept(Visitor*);
};


class Statement_procedure : public Statement
{
public:

	Procedure_statement* procedure_statement;

	Statement_procedure(int, int, Procedure_statement*);
	virtual void accept(Visitor*);
};

class Procedure_statement : public Node
{
public:
	Procedure_statement(int, int);
	virtual void accept(Visitor*);
};

class Procedure_statement_expression_list : public Procedure_statement
{
public:

	Ident* ident;
	Expression_list* expression_list;
	Procedure_statement_expression_list(int, int, Ident*, Expression_list*);
	virtual void accept(Visitor*);
};

class Procedure_statement_ident : public Procedure_statement
{
public:
	Ident* ident;
	Procedure_statement_ident(int, int, Ident*);
	virtual void accept(Visitor*);
};

class Statement_compound : public Statement {
public:

	Compound_statement* compound_statement;
	Statement_compound(int, int, Compound_statement*);
	virtual void accept(Visitor*);
};
class Statement_if : public Statement {
public:

	Expression* expression;
	Statement* statement;
	Statement_if(int, int, Expression*, Statement*);
	virtual void accept(Visitor*);
};
class Statement_if_else : public Statement {
public:

	Expression* expression;
	Statement* statement1;
	Statement* statement2;
	Statement_if_else(int, int, Expression*, Statement*, Statement*);
	virtual void accept(Visitor*);
};

class Statement_while : public Statement {
public:
	Expression* expression;
	Statement* statement;
	Statement_while(int, int, Expression*, Statement*);
	virtual void accept(Visitor*);
};

class Variable : public Node {
public:
	string kind;
	Variable(int, int);
	virtual void accept(Visitor*);
};


class Variable_ident : public Variable {
public:
	Ident* ident;
	Variable_ident(int, int, Ident*);
	virtual void accept(Visitor*);
};

class Variable_expression_list : public Variable {
public:
	Ident* ident;
	Expression_list* expression_list;
	Variable_expression_list(int, int, Ident*, Expression_list*);
	virtual void accept(Visitor*);
};



class Expression_list : public Node {
public:
	vector <Expression*>* expressions;
	Expression_list(int, int, Expression*);
	void add_expression(Expression*);
	virtual void accept(Visitor*);
};


class Expression : public Node
{
public:
	Expression(int, int);
	Type* type;
	virtual void accept(Visitor*);
};

class Expression_ident : public Expression {
public:
	Ident* ident;
	Expression_ident(int, int, Ident*);
	virtual void accept(Visitor*);
};

class Expression_intnum : public Expression
{
public:
	Intnum* intnum;
	Expression_intnum(int, int, Intnum*);
	virtual void accept(Visitor*);
};


class Expression_realnum : public Expression
{
public:
	Realnum* realnum;
	Expression_realnum(int, int, Realnum*);
	virtual void accept(Visitor*);
};

class Expression_true : public Expression
{
public:
	bool b;
	Expression_true(int, int);
	virtual void accept(Visitor*);
};

class Expression_false : public Expression
{
public:
	bool b;
	Expression_false(int, int);
	virtual void accept(Visitor*);
};

class Expression_expression_list : public Expression {
public:
	Ident* ident;
	Expression_list* expression_list;
	Expression_expression_list(int, int, Ident*, Expression_list*);
	virtual void accept(Visitor*);
};

class Expression_expression : public Expression
{
public:
	Expression* expression;
	Expression_expression(int, int, Expression*);
	virtual void accept(Visitor*);
};

class Expression_unary : public Expression
{
public:
	Expression* expression1;
	Expression* expression2;
	Unary_operator* unary_operator;
	Expression_unary(int, int, Expression*, Expression*, Unary_operator*);
	virtual void accept(Visitor*);
};

class Expression_not : public Expression
{
public:
	Expression* expresssion;
	Expression_not(int, int, Expression*);
	virtual void accept(Visitor*);
};


class Unary_operator : public Node
{
public:
	Unary_operator(int, int);
	string kind;
	virtual void accept(Visitor*);
};

class Unary_operator_plus : public Unary_operator
{
public:

	Unary_operator_plus(int, int);
	virtual void accept(Visitor*);
};

class Unary_operator_minus : public Unary_operator
{
public:

	Unary_operator_minus(int, int);
	virtual void accept(Visitor*);
};


class Unary_operator_multiply : public Unary_operator
{
public:

	Unary_operator_multiply(int, int);
	virtual void accept(Visitor*);
};


class Unary_operator_divide : public Unary_operator
{
public:

	Unary_operator_divide(int, int);
	virtual void accept(Visitor*);
};



class Unary_operator_div : public Unary_operator
{
public:

	Unary_operator_div(int, int);
	virtual void accept(Visitor*);
};



class Unary_operator_ge : public Unary_operator
{
public:

	Unary_operator_ge(int, int);
	virtual void accept(Visitor*);
};


class Unary_operator_le : public Unary_operator
{
public:

	Unary_operator_le(int, int);
	virtual void accept(Visitor*);
};

class Unary_operator_greater : public Unary_operator
{
public:

	Unary_operator_greater(int, int);
	virtual void accept(Visitor*);
};


class Unary_operator_less : public Unary_operator
{
public:

	Unary_operator_less(int, int);
	virtual void accept(Visitor*);
};

class Unary_operator_eq : public Unary_operator
{
public:

	Unary_operator_eq(int, int);
	virtual void accept(Visitor*);
};

class Unary_operator_ne : public Unary_operator
{
public:

	Unary_operator_ne(int, int);
	virtual void accept(Visitor*);
};

class Unary_operator_not : public Unary_operator
{
public:

	Unary_operator_not(int, int);
	virtual void accept(Visitor*);
};

class Unary_operator_or : public Unary_operator
{
public:

	Unary_operator_or(int, int);
	virtual void accept(Visitor*);
};


class Unary_operator_and : public Unary_operator
{
public:

	Unary_operator_and(int, int);
	virtual void accept(Visitor*);
};


class Visitor
{
public:

	virtual void visit(Node*) = 0;
	virtual void visit(Root*) = 0;
	virtual void visit(Ident*) = 0;
	virtual void visit(Declarations*) = 0;
	virtual void visit(Subprogram_declarations*) = 0;
	virtual void visit(Compound_statement*) = 0;
	virtual void visit(Identifier_list*) = 0;
	virtual void visit(Type*) = 0;
	virtual void visit(Standard_type*) = 0;
	virtual void visit(Intnum*) = 0;
	virtual void visit(Realnum*) = 0;
	virtual void visit(Subprogram_declaration*) = 0;
	virtual void visit(Subprogram_head*) = 0;
	virtual void visit(Arguments*) = 0;
	virtual void visit(Parameter_list*) = 0;
	virtual void visit(Optional_statements*) = 0;
	virtual void visit(Optional_statements_list*) = 0;
	virtual void visit(Optional_statements_empty*) = 0;
	virtual void visit(Statement*) = 0;
	virtual void visit(Statement_list*) = 0;
	virtual void visit(Variable*) = 0;
	virtual void visit(Expression*) = 0;
	virtual void visit(Procedure_statement*) = 0;
	virtual void visit(Expression_list*) = 0;
	virtual void visit(Unary_operator*) = 0;
	virtual void visit(Unary_operator_plus*) = 0;
	virtual void visit(Unary_operator_minus*) = 0;
	virtual void visit(Unary_operator_multiply*) = 0;
	virtual void visit(Unary_operator_divide*) = 0;
	virtual void visit(Unary_operator_div*) = 0;
	virtual void visit(Unary_operator_ge*) = 0;
	virtual void visit(Unary_operator_le*) = 0;
	virtual void visit(Unary_operator_greater*) = 0;
	virtual void visit(Unary_operator_less*) = 0;
	virtual void visit(Unary_operator_eq*) = 0;
	virtual void visit(Unary_operator_ne*) = 0;
	virtual void visit(Unary_operator_not*) = 0;
	virtual void visit(Unary_operator_or*) = 0;
	virtual void visit(Unary_operator_and*) = 0;


	virtual void visit(Type_standard_type*) = 0;
	virtual void visit(Type_array*) = 0;
	virtual void visit(Subprogram_head_fucntion*) = 0;
	virtual void visit(Subprogram_head_procedure*) = 0;
	virtual void visit(Statement_assigment*) = 0;
	virtual void visit(Statement_procedure*) = 0;
	virtual void visit(Procedure_statement_expression_list*) = 0;
	virtual void visit(Procedure_statement_ident*) = 0;
	virtual void visit(Statement_compound*) = 0;
	virtual void visit(Statement_if*) = 0;
	virtual void visit(Statement_if_else*) = 0;
	virtual void visit(Statement_while*) = 0;
	virtual void visit(Variable_ident*) = 0;
	virtual void visit(Variable_expression_list*) = 0;
	virtual void visit(Expression_ident*) = 0;
	virtual void visit(Expression_intnum*) = 0;
	virtual void visit(Expression_realnum*) = 0;
	virtual void visit(Expression_true*) = 0;
	virtual void visit(Expression_false*) = 0;
	virtual void visit(Expression_expression_list*) = 0;
	virtual void visit(Expression_expression*) = 0;
	virtual void visit(Expression_unary*) = 0;
	virtual void visit(Expression_not*) = 0;



};


class Print_visitor : public Visitor
{
public:

	virtual void visit(Node*);
	virtual void visit(Root*);
	virtual void visit(Ident*);
	virtual void visit(Declarations*);
	virtual void visit(Subprogram_declarations*);
	virtual void visit(Compound_statement*);
	virtual void visit(Identifier_list*);
	virtual void visit(Type*);
	virtual void visit(Standard_type*);
	virtual void visit(Standard_type_integer*);
	virtual void visit(Standard_type_real*);
	virtual void visit(Standard_type_boolean*);
	virtual void visit(Standard_type_string*);
	virtual void visit(Intnum*);
	virtual void visit(Realnum*);
	virtual void visit(Subprogram_declaration*);
	virtual void visit(Subprogram_head*);
	virtual void visit(Arguments*);
	virtual void visit(Parameter_list*);
	virtual void visit(Optional_statements*);
	virtual void visit(Optional_statements_list*);
	virtual void visit(Optional_statements_empty*);
	virtual void visit(Statement*);
	virtual void visit(Statement_list*);
	virtual void visit(Variable*);
	virtual void visit(Expression*);
	virtual void visit(Procedure_statement*);
	virtual void visit(Expression_list*);
	virtual void visit(Unary_operator*);
	virtual void visit(Unary_operator_plus*);
	virtual void visit(Unary_operator_minus*);
	virtual void visit(Unary_operator_multiply*);
	virtual void visit(Unary_operator_divide*);
	virtual void visit(Unary_operator_div*);
	virtual void visit(Unary_operator_ge*);
	virtual void visit(Unary_operator_le*);
	virtual void visit(Unary_operator_greater*);
	virtual void visit(Unary_operator_less*);
	virtual void visit(Unary_operator_eq*);
	virtual void visit(Unary_operator_ne*);
	virtual void visit(Unary_operator_not*);
	virtual void visit(Unary_operator_or*);
	virtual void visit(Unary_operator_and*);


	virtual void visit(Type_standard_type*);
	virtual void visit(Type_array*);
	virtual void visit(Subprogram_head_fucntion*);
	virtual void visit(Subprogram_head_procedure*);
	virtual void visit(Statement_assigment*);
	virtual void visit(Statement_procedure*);
	virtual void visit(Procedure_statement_expression_list*);
	virtual void visit(Procedure_statement_ident*);
	virtual void visit(Statement_compound*);
	virtual void visit(Statement_if*);
	virtual void visit(Statement_if_else*);
	virtual void visit(Statement_while*);
	virtual void visit(Variable_ident*);
	virtual void visit(Variable_expression_list*);
	virtual void visit(Expression_ident*);
	virtual void visit(Expression_intnum*);
	virtual void visit(Expression_realnum*);
	virtual void visit(Expression_true*);
	virtual void visit(Expression_false*);
	virtual void visit(Expression_expression_list*);
	virtual void visit(Expression_expression*);
	virtual void visit(Expression_unary*);
	virtual void visit(Expression_not*);


};



/////////////////////////////////////// Symbol Table ///////////////////////////////////////


class Symbol {
public:
	string name;
	string kind;
	Type* type;
	int location;
	string label;
	bool visited;
	Subprogram_declaration* sd;

	Symbol(string, string, Type*);
};

class Scope {
public:
	HashTab* hashTab;
	Scope();
};

class SymbolTable {
public:
	vector<Scope*>* scopes;
	Scope* current;
	SymbolTable();
	bool add_symbol(Ident*, string, Type*);
	bool add_parameter_list(Parameter_list*);
	bool add_declarations(Declarations*);
	bool add_subprogram(Subprogram_declaration*);
	bool add_local_declarations(Declarations*);
	//bool add_function(Subprogram_head*, Declarations *, Compound_statement*);
	//bool add_procedeure(Subprogram_head*, Declarations *, Compound_statement*);
	Symbol* lookup_symbol(Ident*);
	Symbol* lookup_function(Ident*, Expression_list*);
	void close_scope();
	void new_scope();
};


////////////////////////////////////////// TYPE CHECKING ///////////////////////////////

class Type_visitor : public Visitor
{
public:

	virtual void visit(Node*);
	virtual void visit(Root*);
	virtual void visit(Ident*);
	virtual void visit(Declarations*);
	virtual void visit(Subprogram_declarations*);
	virtual void visit(Compound_statement*);
	virtual void visit(Identifier_list*);
	virtual void visit(Type*);
	virtual void visit(Standard_type*);
	virtual void visit(Standard_type_integer*);
	virtual void visit(Standard_type_real*);
	virtual void visit(Standard_type_boolean*);
	virtual void visit(Standard_type_string*);
	virtual void visit(Intnum*);
	virtual void visit(Realnum*);
	virtual void visit(Subprogram_declaration*);
	virtual void visit(Subprogram_head*);
	virtual void visit(Arguments*);
	virtual void visit(Parameter_list*);
	virtual void visit(Optional_statements*);
	virtual void visit(Optional_statements_list*);
	virtual void visit(Optional_statements_empty*);
	virtual void visit(Statement*);
	virtual void visit(Statement_list*);
	virtual void visit(Variable*);
	virtual void visit(Expression*);
	virtual void visit(Procedure_statement*);
	virtual void visit(Expression_list*);
	virtual void visit(Unary_operator*);
	virtual void visit(Unary_operator_plus*);
	virtual void visit(Unary_operator_minus*);
	virtual void visit(Unary_operator_multiply*);
	virtual void visit(Unary_operator_divide*);
	virtual void visit(Unary_operator_div*);
	virtual void visit(Unary_operator_ge*);
	virtual void visit(Unary_operator_le*);
	virtual void visit(Unary_operator_greater*);
	virtual void visit(Unary_operator_less*);
	virtual void visit(Unary_operator_eq*);
	virtual void visit(Unary_operator_ne*);
	virtual void visit(Unary_operator_not*);
	virtual void visit(Unary_operator_or*);
	virtual void visit(Unary_operator_and*);


	virtual void visit(Type_standard_type*);
	virtual void visit(Type_array*);
	virtual void visit(Subprogram_head_fucntion*);
	virtual void visit(Subprogram_head_procedure*);
	virtual void visit(Statement_assigment*);
	virtual void visit(Statement_procedure*);
	virtual void visit(Procedure_statement_expression_list*);
	virtual void visit(Procedure_statement_ident*);
	virtual void visit(Statement_compound*);
	virtual void visit(Statement_if*);
	virtual void visit(Statement_if_else*);
	virtual void visit(Statement_while*);
	virtual void visit(Variable_ident*);
	virtual void visit(Variable_expression_list*);
	virtual void visit(Expression_ident*);
	virtual void visit(Expression_intnum*);
	virtual void visit(Expression_realnum*);
	virtual void visit(Expression_true*);
	virtual void visit(Expression_false*);
	virtual void visit(Expression_expression_list*);
	virtual void visit(Expression_expression*);
	virtual void visit(Expression_unary*);
	virtual void visit(Expression_not*);


};


///////////////////////////////////////// Code Visitor ///////////////////////////////

class Code_visitor : public Visitor
{
public:

	virtual void visit(Node*);
	virtual void visit(Root*);
	virtual void visit(Ident*);
	virtual void visit(Declarations*);
	virtual void visit(Subprogram_declarations*);
	virtual void visit(Compound_statement*);
	virtual void visit(Identifier_list*);
	virtual void visit(Type*);
	virtual void visit(Standard_type*);
	virtual void visit(Intnum*);
	virtual void visit(Realnum*);
	virtual void visit(Subprogram_declaration*);
	virtual void visit(Subprogram_head*);
	virtual void visit(Arguments*);
	virtual void visit(Parameter_list*);
	virtual void visit(Optional_statements*);
	virtual void visit(Optional_statements_list*);
	virtual void visit(Optional_statements_empty*);
	virtual void visit(Statement*);
	virtual void visit(Statement_list*);
	virtual void visit(Variable*);
	virtual void visit(Expression*);
	virtual void visit(Procedure_statement*);
	virtual void visit(Expression_list*);
	virtual void visit(Unary_operator*);
	virtual void visit(Unary_operator_plus*);
	virtual void visit(Unary_operator_minus*);
	virtual void visit(Unary_operator_multiply*);
	virtual void visit(Unary_operator_divide*);
	virtual void visit(Unary_operator_div*);
	virtual void visit(Unary_operator_ge*);
	virtual void visit(Unary_operator_le*);
	virtual void visit(Unary_operator_greater*);
	virtual void visit(Unary_operator_less*);
	virtual void visit(Unary_operator_eq*);
	virtual void visit(Unary_operator_ne*);
	virtual void visit(Unary_operator_not*);
	virtual void visit(Unary_operator_or*);
	virtual void visit(Unary_operator_and*);


	virtual void visit(Type_standard_type*);
	virtual void visit(Type_array*);
	virtual void visit(Subprogram_head_fucntion*);
	virtual void visit(Subprogram_head_procedure*);
	virtual void visit(Statement_assigment*);
	virtual void visit(Statement_procedure*);
	virtual void visit(Procedure_statement_expression_list*);
	virtual void visit(Procedure_statement_ident*);
	virtual void visit(Statement_compound*);
	virtual void visit(Statement_if*);
	virtual void visit(Statement_if_else*);
	virtual void visit(Statement_while*);
	virtual void visit(Variable_ident*);
	virtual void visit(Variable_expression_list*);
	virtual void visit(Expression_ident*);
	virtual void visit(Expression_intnum*);
	virtual void visit(Expression_realnum*);
	virtual void visit(Expression_true*);
	virtual void visit(Expression_false*);
	virtual void visit(Expression_expression_list*);
	virtual void visit(Expression_expression*);
	virtual void visit(Expression_unary*);
	virtual void visit(Expression_not*);


};




//////////////////////////////Unary Checker/////////////////////////////////////
class Checker {
public:
	static Type* unary_check(Expression*, Expression*);
	static bool check_boolean(Expression*);
};



//////////////////////////////////// Code Generator ////////////////////////////////

class Generator {
public:
	static int fp;
	static int gp;
	static int if_num;
	static int while_num;
	static void initialize(Ident* ident, Standard_type* st, string kind);
	static void initialize_type(Ident* ident, Standard_type_integer* st, string kind);
	static void initialize_type(Ident* ident, Standard_type_real* st, string kind);
	static void initialize_type(Ident* ident, Standard_type_string* st, string kind);
	static void initialize_type(Ident* ident, Standard_type_boolean* st, string kind);

	static void push_ident(Ident* ident, Standard_type* st, string kind);
	static void push_ident_type(Ident* ident, Standard_type_integer* st, string kind);
	static void push_ident_type(Ident* ident, Standard_type_real* st, string kind);
	static void push_ident_type(Ident* ident, Standard_type_string* st, string kind);
	static void push_ident_type(Ident* ident, Standard_type_boolean* st, string kind);


	static void unary(Standard_type* st, string kind);
	static void unary_type(Standard_type_integer* st, string kind);
	static void unary_type(Standard_type_real* st, string kind);
	static void unary_type(Standard_type_string* st, string kind);
	static void unary_type(Standard_type_boolean* st, string kind);
	


	
};



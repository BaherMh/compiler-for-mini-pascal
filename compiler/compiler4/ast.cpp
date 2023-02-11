#include "ast.h";
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::pair;
#include <vector>;
#include <typeinfo>

Node::Node(int line, int column)
{
	this->line = line;
	this->column = column;
	this->father = NULL;

}

Root::Root(int l, int c, Ident* i, Declarations* d, Subprogram_declarations* s, Compound_statement* cm) : Node(l, c)
{
	this->ident = i;
	this->declarations = d;
	this->subprogram_declarations = s;
	this->compound_statement = cm;
	d->father = this;
	i->father = this;
	s->father = this;
	cm->father = this;


}


Ident::Ident(int l, int c, string name) : Node(l, c)
{
	this->name = name;
}


Declarations::Declarations(int l, int c, pair<Identifier_list*, Type*>* p) : Node(l, c)
{
	this->decs = new vector <pair<Identifier_list*, Type*>*>;
	this->add_declaration(p);
}

Declarations::Declarations(int l, int c) : Node(l, c)
{
	this->decs = new vector <pair<Identifier_list*, Type*>*>;
}

void Declarations::add_declaration(pair<Identifier_list*, Type*>* p)
{
	this->decs->push_back(p);
	p->first->father = this;
	p->second->father = this;

}
Identifier_list::Identifier_list(int l, int c, Ident* ident) :Node(l, c)
{
	this->idents = new vector<Ident*>;
	this->add_ident(ident);

}

void Identifier_list::add_ident(Ident* ident)
{
	this->idents->push_back(ident);
}

Type::Type(int l, int c) : Node(l, c)
{

}
Type_standard_type::Type_standard_type(int l, int c, Standard_type* standard_type) : Type(l, c)
{
	this->standard_type = standard_type;
}

string Type_standard_type::get_type()
{
	return this->standard_type->name;
}

string Type_array::get_type()
{
	return "array";
}

Type_array::Type_array(int l, int c, Intnum* left, Intnum* right, Standard_type* type) : Type(l, c)
{
	this->left = left;
	this->right = right;
	this->type = type;
	type->father = this;
}

Standard_type::Standard_type(int l, int c, string name) : Node(l, c)
{
	this->name = name;
}

Standard_type_integer::Standard_type_integer(int l, int c) : Standard_type(l, c, "integer")
{
	
}
Standard_type_void::Standard_type_void(int l, int c) : Standard_type(l, c, "void")
{
	
}


void Standard_type_integer::initialize(Ident* ident, string kind)
{
	Generator::initialize_type(ident, this, kind);
}

void Standard_type_real::initialize(Ident* ident, string kind)
{
	Generator::initialize_type(ident, this, kind);
}
void Standard_type_void::initialize(Ident* ident, string kind)
{

}

void Standard_type_boolean::initialize(Ident* ident, string kind)
{
	Generator::initialize_type(ident, this, kind);
}

void Standard_type_string::initialize(Ident* ident, string kind)
{
	Generator::initialize_type(ident, this, kind);
}
void Standard_type_integer::push_ident(Ident* ident, string kind)
{
	Generator::push_ident_type(ident, this, kind);
}
void Standard_type_void::push_ident(Ident* ident, string kind)
{

}
void Standard_type_real::push_ident(Ident* ident, string kind)
{
	Generator::push_ident_type(ident, this, kind);
}

void Standard_type_boolean::push_ident(Ident* ident, string kind)
{
	Generator::push_ident_type(ident, this, kind);
}

void Standard_type_string::push_ident(Ident* ident, string kind)
{
	Generator::push_ident_type(ident, this, kind);
}



void Standard_type_integer::unary(string kind)
{
	Generator::unary_type(this, kind);
}
void Standard_type_void::unary(string kind)
{

}
void Standard_type_real::unary(string kind)
{
	Generator::unary_type(this, kind);
}

void Standard_type_boolean::unary(string kind)
{
	Generator::unary_type(this, kind);
}

void Standard_type_string::unary(string kind)
{
	Generator::unary_type(this, kind);
}




Standard_type_real::Standard_type_real(int l, int c) : Standard_type(l, c, "real")
{

}

Standard_type_boolean::Standard_type_boolean(int l, int c) : Standard_type(l, c, "boolean")
{

}

Standard_type_string::Standard_type_string(int l, int c) : Standard_type(l, c, "string")
{

}

Subprogram_declarations::Subprogram_declarations(int l, int c, Subprogram_declaration* s) : Node(l, c)
{
	this->sub_decs = new vector<Subprogram_declaration*>;
	this->add_subprogram_declaration(s);

}

Subprogram_declarations::Subprogram_declarations(int l, int c) : Node(l, c)
{
	this->sub_decs = new vector<Subprogram_declaration*>;
}

void Subprogram_declarations::add_subprogram_declaration(Subprogram_declaration* s)
{
	this->sub_decs->push_back(s);
}




Subprogram_declaration::Subprogram_declaration(int l, int c, Subprogram_head* sh, Declarations* local_decs, Compound_statement* cs) : Node(l, c)
{
	this->sh = sh;
	this->cs = cs;
	this->local_decs = local_decs;
	sh->father = this;
	cs->father = this;
}

Subprogram_head::Subprogram_head(int l, int c) : Node(l, c)
{

}


Subprogram_head_fucntion::Subprogram_head_fucntion(int l, int c, Ident* ident, Arguments* args, Standard_type* type) : Subprogram_head(l, c)
{
	this->ident = ident;
	this->args = args;
	this->type = type;
	this->label = "none";
}


Subprogram_head_procedure::Subprogram_head_procedure(int l, int c, Ident* ident, Arguments* args) : Subprogram_head(l, c)
{
	this->ident = ident;
	this->args = args;
	this->type = new Standard_type_void(l, c);
	this->label = "none";

}

Arguments::Arguments(int l, int c, Parameter_list* paras) : Node(l, c)
{
	this->paras = paras;
}

Arguments::Arguments(int l, int c) : Node(l, c)
{

}

Parameter_list::Parameter_list(int l, int c, pair<Identifier_list*, Type*>* parameter) : Node(l, c)
{
	this->paras = new vector <pair<Identifier_list*, Type*>*>;
	this->add_parameter(parameter);
}

void Parameter_list::add_parameter(pair<Identifier_list*, Type*>* parameter)
{
	this->paras->push_back(parameter);
}


Compound_statement::Compound_statement(int l, int c, Optional_statements* optional_statement) : Node(l, c)
{
	this->optional_statement = optional_statement;
}

Optional_statements::Optional_statements(int l, int c) : Node(l, c)
{

}
Optional_statements_list::Optional_statements_list(int l, int c, Statement_list* statement_list) : Optional_statements(l, c)
{
	this->statement_list = statement_list;
}
Optional_statements_list::Optional_statements_list(int l, int c) : Optional_statements(l, c)
{
	
}
Optional_statements_empty::Optional_statements_empty(int l, int c) : Optional_statements(l, c)
{

}
Intnum::Intnum(int l, int c, int num) : Node(l, c)
{
	this->num = num;
}

Realnum::Realnum(int l, int c, double num) : Node(l, c)
{
	this->num = num;
}

Statement_list::Statement_list(int l, int c, Statement* statement) : Node(l, c)
{
	this->statements = new vector<Statement*>;
	this->add_statement(statement);
}
void Statement_list::add_statement(Statement* statement)
{
	this->statements->push_back(statement);
}

Statement::Statement(int l, int c) : Node(l, c)
{

}

Statement_assigment::Statement_assigment(int l, int c, Variable* variable, Expression* expression) : Statement(l, c)
{
	this->variable = variable;
	this->expression = expression;
	variable->father = this;
	expression->father = this;
}
Statement_procedure::Statement_procedure(int l, int c, Procedure_statement* procedure_statement) : Statement(l, c)
{
	this->procedure_statement = procedure_statement;
	procedure_statement->father = this;
}


Statement_compound::Statement_compound(int l, int c, Compound_statement* compound_statement) : Statement(l, c)
{
	this->compound_statement = compound_statement;
	compound_statement->father = this;
}
Statement_if::Statement_if(int l, int c, Expression* expression, Statement* statement) : Statement(l, c)
{
	this->expression = expression;
	this->statement = statement;
	statement->father = this;
	expression->father = this;
}

Statement_if_else::Statement_if_else(int l, int c, Expression* expression, Statement* statement1, Statement* statement2) : Statement(l, c)
{
	this->expression = expression;
	this->statement1 = statement1;
	this->statement2 = statement2;
	statement1->father = this;
	statement2->father = this;
	expression->father = this;
}


Statement_while::Statement_while(int l, int c, Expression* expression, Statement* statement) : Statement(l, c)
{
	this->expression = expression;
	this->statement = statement;
	statement->father = this;
	expression->father = this;
}


Variable::Variable(int l, int c) : Node(l, c)
{

}

Variable_ident::Variable_ident(int l, int c, Ident* ident) : Variable(l, c)
{
	this->kind = "ident";
	this->ident = ident;
	ident->father = this;
}

Variable_expression_list::Variable_expression_list(int l, int c, Ident* ident, Expression_list* expression_list) : Variable(l, c)
{
	this->kind = "array";
	this->ident = ident;
	this->expression_list = expression_list;
	expression_list->father = this;
	ident->father = this;
}

Procedure_statement::Procedure_statement(int l, int c) : Node(l, c)
{

}

Procedure_statement_ident::Procedure_statement_ident(int l, int c, Ident* ident) : Procedure_statement(l, c)
{
	this->ident = ident;
	ident->father = this;
}

Procedure_statement_expression_list::Procedure_statement_expression_list(int l, int c, Ident* ident, Expression_list* expression_list) : Procedure_statement(l, c)
{
	this->ident = ident;
	this->expression_list = expression_list;
	expression_list->father = this;
	ident->father = this;
}

Expression_list::Expression_list(int l, int c, Expression* expression) : Node(l, c)
{
	this->expressions = new vector<Expression*>;
	this->add_expression(expression);
}

void Expression_list::add_expression(Expression* expression)
{
	this->expressions->push_back(expression);
	expression->father = this;

}


Expression::Expression(int l, int c) : Node(l, c)
{

}

Expression_ident::Expression_ident(int l, int c, Ident* ident) : Expression(l, c)
{
	this->ident = ident;
	ident->father = this;
}

Expression_intnum::Expression_intnum(int l, int c, Intnum* intnum) : Expression(l, c)
{
	this->intnum = intnum;
	intnum->father = this;
}

Expression_realnum::Expression_realnum(int l, int c, Realnum* realnum) : Expression(l, c)
{
	this->realnum = realnum;
}

Expression_true::Expression_true(int l, int c) : Expression(l, c)
{
	this->b = true;
}

Expression_false::Expression_false(int l, int c) : Expression(l, c)
{
	this->b = false;
}

Expression_expression_list::Expression_expression_list(int l, int c, Ident* ident, Expression_list* expression_list) : Expression(l, c)
{
	this->ident = ident;
	this->expression_list = expression_list;
	ident->father = this;
	expression_list->father = this;
}

Expression_expression::Expression_expression(int l, int c, Expression* expression) : Expression(l, c)
{
	this->expression = expression;
	expression->father = this;
}

Expression_unary::Expression_unary(int l, int c, Expression* expression1, Expression* expression2, Unary_operator* unary_operator) : Expression(l, c)
{
	this->expression1 = expression1;
	this->expression2 = expression2;
	this->unary_operator = unary_operator;
}



Expression_not::Expression_not(int l, int c, Expression* expression) : Expression(l, c)
{
	this->expresssion = expression;
}

Unary_operator::Unary_operator(int l, int c) : Node(l, c)
{

}

Unary_operator_plus::Unary_operator_plus(int l, int c) : Unary_operator(l, c)
{
	kind = "+";
}

Unary_operator_minus::Unary_operator_minus(int l, int c) : Unary_operator(l, c)
{
	kind = "-";
}

Unary_operator_multiply::Unary_operator_multiply(int l, int c) : Unary_operator(l, c)
{
	kind = "*";
}

Unary_operator_divide::Unary_operator_divide(int l, int c) : Unary_operator(l, c)
{
	kind = "/";
}

Unary_operator_div::Unary_operator_div(int l, int c) : Unary_operator(l, c)
{
	kind = "div";
}

Unary_operator_ge::Unary_operator_ge(int l, int c) : Unary_operator(l, c)
{
	kind = "ge";
}

Unary_operator_le::Unary_operator_le(int l, int c) : Unary_operator(l, c)
{
	kind = "le";
}

Unary_operator_greater::Unary_operator_greater(int l, int c) : Unary_operator(l, c)
{
	kind = "greater";
}

Unary_operator_less::Unary_operator_less(int l, int c) : Unary_operator(l, c)
{
	kind = "less";
}

Unary_operator_not::Unary_operator_not(int l, int c) : Unary_operator(l, c)
{
	kind = "not";
}

Unary_operator_or::Unary_operator_or(int l, int c) : Unary_operator(l, c)
{
	kind = "or";
}

Unary_operator_and::Unary_operator_and(int l, int c) : Unary_operator(l, c)
{
	kind = "and";
}

Unary_operator_ne::Unary_operator_ne(int l, int c) : Unary_operator(l, c)
{
	kind = "ne";
}

Unary_operator_eq::Unary_operator_eq(int l, int c) : Unary_operator(l, c)
{
	kind = "eq";
}


/////////////////////////////////////////////// VISITOR ////////////////////////////////////////////////////////



void Print_visitor::visit(Node* var)
{
	cout << "this is Node" << '\n';
}
void Print_visitor::visit(Root* var)
{
	cout << "this is the root" << '\n';
	var->compound_statement->accept(this);
	cout << var->declarations->line;
	var->ident->accept(this);
	var->subprogram_declarations->accept(this);
	var->declarations->accept(this);

}
void Print_visitor::visit(Ident* var)
{
	cout << "this is Ident " << var->name;
	cout << '\n';

}
void Print_visitor::visit(Declarations* var)
{
	cout << "this is Declarations with size " << var->decs->size() << '\n';
	for (int i = 0; i < var->decs->size(); i++)
	{
		var->decs->at(i)->first->accept(this);
		var->decs->at(i)->second->accept(this);
	}
}
void Print_visitor::visit(Subprogram_declarations* var)
{
	cout << "this is subprogram_declarations with size " << var->sub_decs->size() << '\n';
	for (int i = 0; i < var->sub_decs->size(); i++)
	{
		var->sub_decs->at(i)->accept(this);
	}
}
void Print_visitor::visit(Compound_statement* var)
{
	cout << "this is compund_statement \n";
	var->optional_statement->accept(this);
}
void Print_visitor::visit(Identifier_list* var)
{
	cout << "this is identifier_list with size " << var->idents->size() << '\n';
	for (int i = 0; i < var->idents->size(); i++)
	{
		var->idents->at(i)->accept(this);
	}
}
void Print_visitor::visit(Type* var)
{
	cout << "this is type\n";
}
void Print_visitor::visit(Standard_type* var)
{
	cout << "this is standard_type " << var->name << '\n';

}
void Print_visitor::visit(Standard_type_integer* var)
{
	cout << "this is standard_type " << var->name << '\n';

}
void Print_visitor::visit(Standard_type_real* var)
{
	cout << "this is standard_type " << var->name << '\n';

}
void Print_visitor::visit(Standard_type_boolean* var)
{
	cout << "this is standard_type " << var->name << '\n';

}
void Print_visitor::visit(Standard_type_string* var)
{
	cout << "this is standard_type " << var->name << '\n';

}

void Print_visitor::visit(Intnum* var)
{
	cout << "this is intnum with value " << var->num << '\n';
}
void Print_visitor::visit(Realnum* var)
{
	cout << "this is real num with value " << var->num << '\n';
}
void Print_visitor::visit(Subprogram_declaration* var)
{
	cout << "this is Subprogram declarations " << '\n';
	var->cs->accept(this);
	var->sh->accept(this);
}
void Print_visitor::visit(Subprogram_head* var)
{
	cout << "this is Subprogram head " << '\n';

}

void Print_visitor::visit(Arguments* var)
{
	cout << "this is Arguments " << '\n';
	var->paras->accept(this);
}

void Print_visitor::visit(Parameter_list* var)
{
	cout << "this is parameter list with size " << var->paras->size() << '\n';
	for (int i = 0; i < var->paras->size(); i++)
	{
		var->paras->at(i)->first->accept(this);
		var->paras->at(i)->second->accept(this);
	}
}

void Print_visitor::visit(Optional_statements* var)
{
	cout << "this is optional statements\n";

	
}

void Print_visitor::visit(Optional_statements_list* var)
{
	cout << "this is optional statements\n";
	var->statement_list->accept(this);


}

void Print_visitor::visit(Optional_statements_empty* var)
{
	cout << "this is empty optional statements\n";


}

void Print_visitor::visit(Statement* var)
{
	cout << "this is statements\n";

}
void Print_visitor::visit(Statement_list* var)
{
	cout << "this is Statement_list" << '\n';
	for (int i = 0; i < var->statements->size(); i++)
	{
		var->statements->at(i)->accept(this);
	}
}
void Print_visitor::visit(Variable* var)
{
	cout << "this is variable" << '\n';

}
void Print_visitor::visit(Expression* var)
{
	cout << "this is Expression" << '\n';
}
void Print_visitor::visit(Procedure_statement* var)
{
	cout << "this is Procedure_statement" << '\n';

}
void Print_visitor::visit(Expression_list* var)
{
	cout << "this is Expression_list" << '\n';
	for (int i = 0; i < var->expressions->size(); i++)
	{
		var->expressions->at(i)->accept(this);
	}

}
void Print_visitor::visit(Unary_operator* var)
{
	cout << "this is Unary_operator" << '\n';
}
void Print_visitor::visit(Unary_operator_plus* var)
{
	cout << "this is Unary_operator_plus" << '\n';

}
void Print_visitor::visit(Unary_operator_minus* var)
{
	cout << "this is Unary_operator_minus" << '\n';

}
void Print_visitor::visit(Unary_operator_multiply* var)
{
	cout << "this is Unary_operator_multiply" << '\n';

}
void Print_visitor::visit(Unary_operator_divide* var)
{
	cout << "this is Unary_operator_divide" << '\n';

}
void Print_visitor::visit(Unary_operator_div* var)
{
	cout << "this is Unary_operator_div" << '\n';

}
void Print_visitor::visit(Unary_operator_ge* var)
{
	cout << "this is Unary_operator_ge" << '\n';

}
void Print_visitor::visit(Unary_operator_le* var)
{
	cout << "this is Unary_operator_le" << '\n';

}
void Print_visitor::visit(Unary_operator_greater* var)
{
	cout << "this is Unary_operator_greater" << '\n';

}
void Print_visitor::visit(Unary_operator_less* var)
{
	cout << "this is Unary_operator_less" << '\n';

}
void Print_visitor::visit(Unary_operator_eq* var)
{
	cout << "this is Unary_operator_eq" << '\n';

}
void Print_visitor::visit(Unary_operator_ne* var)
{
	cout << "this is Unary_operator_ne" << '\n';

}
void Print_visitor::visit(Unary_operator_not* var)
{
	cout << "this is Unary_operator_not" << '\n';

}
void Print_visitor::visit(Unary_operator_or* var)
{
	cout << "this is Unary_operator_or" << '\n';

}
void Print_visitor::visit(Unary_operator_and* var)
{
	cout << "this is Unary_operator_and" << '\n';

}


void Print_visitor::visit(Type_standard_type* var)
{
	cout << "this is Type_standard_type" << '\n';
	var->standard_type->accept(this);
}

void Print_visitor::visit(Type_array* var)
{
	cout << "this is Type_array" << '\n';
	var->type->accept(this);
	var->right->accept(this);
	var->type->accept(this);

}

void Print_visitor::visit(Subprogram_head_fucntion* var)
{
	cout << "this is Subprogram_head_fucntion" << '\n';
	var->type->accept(this);
	var->ident->accept(this);
	var->args->accept(this);
}

void Print_visitor::visit(Subprogram_head_procedure* var)
{
	cout << "this is Subprogram_head_procedure" << '\n';
	var->ident->accept(this);
	var->args->accept(this);

}

void Print_visitor::visit(Statement_assigment* var)
{
	cout << "this is Statement_assigment" << '\n';
	var->expression->accept(this);
	var->variable->accept(this);
}

void Print_visitor::visit(Statement_procedure* var)
{
	cout << "this is Statement_procedure" << '\n';
	var->procedure_statement->accept(this);
}

void Print_visitor::visit(Procedure_statement_expression_list* var)
{
	cout << "this is Procedure_statement_expression_list" << '\n';
	var->ident->accept(this);
	var->expression_list->accept(this);

}

void Print_visitor::visit(Procedure_statement_ident* var)
{
	cout << "this is Procedure_statement_ident" << '\n';
	var->ident->accept(this);
}

void Print_visitor::visit(Statement_compound* var)
{
	cout << "this is Procedure_statement_ident" << '\n';
	var->compound_statement->accept(this);

}

void Print_visitor::visit(Statement_if* var)
{
	cout << "this is Statement_if" << '\n';
	var->expression->accept(this);
	var->statement->accept(this);

}

void Print_visitor::visit(Statement_if_else* var)
{
	cout << "this is Statement_if_else" << '\n';
	var->expression->accept(this);
	var->statement1->accept(this);
	var->statement2->accept(this);

}

void Print_visitor::visit(Statement_while* var)
{
	cout << "this is Statement_while" << '\n';
	var->expression->accept(this);
	var->statement->accept(this);
}

void Print_visitor::visit(Variable_ident* var)
{
	cout << "this is Variable_ident" << '\n';
	var->ident->accept(this);
}

void Print_visitor::visit(Variable_expression_list* var)
{
	cout << "this is Variable_expression_list" << '\n';
	var->expression_list->accept(this);
	var->ident->accept(this);
}

void Print_visitor::visit(Expression_ident* var)
{
	cout << "this is Expression_ident" << '\n';
	var->ident->accept(this);
}

void Print_visitor::visit(Expression_intnum* var)
{
	cout << "this is Expression_intnum" << '\n';
	var->intnum->accept(this);
}

void Print_visitor::visit(Expression_realnum* var)
{
	cout << "this is Expression_realnum" << '\n';
	var->realnum->accept(this);
}

void Print_visitor::visit(Expression_true* var)
{
	cout << "this is Expression_true" << '\n';

}

void Print_visitor::visit(Expression_false* var)
{
	cout << "this is Expression_false" << '\n';

}

void Print_visitor::visit(Expression_expression_list* var)
{
	cout << "this is Expression_expression_list" << '\n';
	var->ident->accept(this);
	var->expression_list->accept(this);
}

void Print_visitor::visit(Expression_expression* var)
{
	cout << "this is Expression_expression" << '\n';
	var->expression->accept(this);
}

void Print_visitor::visit(Expression_unary* var)
{
	cout << "this is Expression_unary" << '\n';
	var->expression1->accept(this);
	var->unary_operator->accept(this);
	var->expression2->accept(this);
}

void Print_visitor::visit(Expression_not* var)
{
	cout << "this is Expression_unary" << '\n';
	var->expresssion->accept(this);
}



/////////////////////////////Print Visitor////////////////////////////////////////


void Node::accept(Visitor* v)
{
	v->visit(this);
}

void Root::accept(Visitor* v)
{
	v->visit(this);
}
void Ident::accept(Visitor* v)
{
	v->visit(this);
}
void Declarations::accept(Visitor* v)
{
	cout << this->column;
	v->visit(this);

}
void Subprogram_declarations::accept(Visitor* v)
{
	v->visit(this);
}
void Compound_statement::accept(Visitor* v)
{
	v->visit(this);
}
void Identifier_list::accept(Visitor* v)
{
	v->visit(this);
}

void Type::accept(Visitor* v)
{
	v->visit(this);
}
void Standard_type::accept(Visitor* v)
{
	v->visit(this);
}

void Intnum::accept(Visitor* v)
{
	v->visit(this);
}
void Realnum::accept(Visitor* v)
{
	v->visit(this);
}
void Subprogram_declaration::accept(Visitor* v)
{
	v->visit(this);
}
void Subprogram_head::accept(Visitor* v)
{
	v->visit(this);
}

void Arguments::accept(Visitor* v)
{
	v->visit(this);
}

void Parameter_list::accept(Visitor* v)
{
	v->visit(this);
}

void Optional_statements::accept(Visitor* v)
{
	v->visit(this);
}
void Optional_statements_list::accept(Visitor* v)
{
	v->visit(this);
}
void Optional_statements_empty::accept(Visitor* v)
{
	v->visit(this);
}
void Statement::accept(Visitor* v)
{
	v->visit(this);
}
void Statement_list::accept(Visitor* v)
{
	v->visit(this);
}
void Variable::accept(Visitor* v)
{
	v->visit(this);
}
void Expression::accept(Visitor* v)
{
	v->visit(this);
}
void Procedure_statement::accept(Visitor* v)
{
	v->visit(this);
}
void Expression_list::accept(Visitor* v)
{
	v->visit(this);
}
void Unary_operator::accept(Visitor* v)
{
	v->visit(this);
}
void Unary_operator_plus::accept(Visitor* v)
{
	v->visit(this);

}
void Unary_operator_minus::accept(Visitor* v)
{
	v->visit(this);
}
void Unary_operator_multiply::accept(Visitor* v)
{
	v->visit(this);
}
void Unary_operator_divide::accept(Visitor* v)
{
	v->visit(this);
}
void Unary_operator_div::accept(Visitor* v)
{
	v->visit(this);
}
void Unary_operator_ge::accept(Visitor* v)
{
	v->visit(this);
}
void Unary_operator_le::accept(Visitor* v)
{
	v->visit(this);
}
void Unary_operator_greater::accept(Visitor* v)
{
	v->visit(this);
}
void Unary_operator_less::accept(Visitor* v)
{
	v->visit(this);
}
void Unary_operator_eq::accept(Visitor* v)
{
	v->visit(this);
}
void Unary_operator_ne::accept(Visitor* v)
{
	v->visit(this);
}
void Unary_operator_not::accept(Visitor* v)
{
	v->visit(this);
}
void Unary_operator_or::accept(Visitor* v)
{
	v->visit(this);
}
void Unary_operator_and::accept(Visitor* v)
{
	v->visit(this);
}



void Type_standard_type::accept(Visitor* v)
{
	v->visit(this);
}
void Standard_type_integer::accept(Visitor* v)
{
	v->visit(this);
}
void Standard_type_void::accept(Visitor* v)
{
	v->visit(this);
}
void Standard_type_real::accept(Visitor* v)
{
	v->visit(this);
}
void Standard_type_boolean::accept(Visitor* v)
{
	v->visit(this);
}

void Standard_type_string::accept(Visitor* v)
{
	v->visit(this);
}

void Type_array::accept(Visitor* v)
{
	v->visit(this);
}
void Subprogram_head_fucntion::accept(Visitor* v)
{
	v->visit(this);
}
void Subprogram_head_procedure::accept(Visitor* v)
{
	v->visit(this);
}
void Statement_assigment::accept(Visitor* v)
{
	v->visit(this);
}
void Statement_procedure::accept(Visitor* v)
{
	v->visit(this);
}
void Procedure_statement_expression_list::accept(Visitor* v)
{
	v->visit(this);
}
void Procedure_statement_ident::accept(Visitor* v)
{
	v->visit(this);
}
void Statement_compound::accept(Visitor* v)
{
	v->visit(this);
}
void Statement_if::accept(Visitor* v)
{
	v->visit(this);
}
void Statement_if_else::accept(Visitor* v)
{
	v->visit(this);
}
void Statement_while::accept(Visitor* v)
{
	v->visit(this);
}
void Variable_ident::accept(Visitor* v)
{
	v->visit(this);
}
void Variable_expression_list::accept(Visitor* v)
{
	v->visit(this);
}
void Expression_ident::accept(Visitor* v)
{
	v->visit(this);
}
void Expression_intnum::accept(Visitor* v)
{
	v->visit(this);
}
void Expression_realnum::accept(Visitor* v)
{
	v->visit(this);
}
void Expression_true::accept(Visitor* v)
{
	v->visit(this);
}
void Expression_false::accept(Visitor* v)
{
	v->visit(this);
}
void Expression_expression_list::accept(Visitor* v)
{
	v->visit(this);
}
void Expression_expression::accept(Visitor* v)
{
	v->visit(this);
}
void Expression_unary::accept(Visitor* v)
{
	v->visit(this);
}
void Expression_not::accept(Visitor* v)
{
	v->visit(this);
}

/////////////////////////////// Symbol Table ///////////////////////////////


Symbol::Symbol(string name, string kind, Type* type)
{
	this->name = name;
	this->kind = kind;
	this->type = type;
	this->label = "none";
	this->visited = false;
}


Scope::Scope()
{
	this->hashTab = new HashTab;
}

SymbolTable::SymbolTable()
{
	this->scopes = new vector<Scope*>;
	this->scopes->push_back(new Scope());
	this->current = this->scopes->at(0);
}

bool SymbolTable::add_symbol(Ident* ident, string kind, Type* type)
{
	Symbol* sym = new Symbol(ident->name, kind, type);
	string key = kind + ident->name;
	Symbol* temp = this->current->hashTab->GetMember(key);
	if (temp == NULL)
	{
		this->current->hashTab->AddKey(key, sym);
		ident->symbol = sym;
		return true;
	}
	else
	{
		cout << "Redifinition " << ident->name << " at line " << ident->line << '\n';
		return false;
	}

}

bool SymbolTable::add_parameter_list(Parameter_list* parameter_list)
{
	for (int i = 0; i < parameter_list->paras->size(); i++)
	{
		Identifier_list* x = parameter_list->paras->at(i)->first;
		Type* y = parameter_list->paras->at(i)->second;
		for (int j = 0; j < x->idents->size(); j++)
		{
			bool is_true = this->add_symbol(x->idents->at(j), "a", y);
			if (is_true == false)
			{
				return false;
			}
		}
	}
	return true;
}

bool SymbolTable::add_declarations(Declarations* declarations)
{
	for (int i = 0; i < declarations->decs->size(); i++)
	{
		Identifier_list* x = declarations->decs->at(i)->first;
		Type* y = declarations->decs->at(i)->second;
		for (int j = 0; j < x->idents->size(); j++)
		{
			bool is_true = this->add_symbol(x->idents->at(j), "g", y);
			if (is_true == false)
			{
				return false;
			}
		}
	}
	return true;
}

bool SymbolTable::add_local_declarations(Declarations* declarations)
{
	for (int i = 0; i < declarations->decs->size(); i++)
	{
		Identifier_list* x = declarations->decs->at(i)->first;
		Type* y = declarations->decs->at(i)->second;
		for (int j = 0; j < x->idents->size(); j++)
		{
			bool is_true = this->add_symbol(x->idents->at(j), "l", y);
			if (is_true == false)
			{
				cout << "an error occured while declaring " << x->idents->at(j)->name << " at line " << x->idents->at(j)->line  << '\n';
				return false;
			}
		}
	}
	return true;
}
/*

bool SymbolTable::add_function(Subprogram_head* sh, Declarations* dec, Compound_statement* cs)
{
	string key = "f" + sh->ident->name;
	Subprogram_head_fucntion* shf = (Subprogram_head_fucntion*)sh;
	for (int i = 0; i < shf->args->paras->paras->size(); i++)
	{
		Type* x = shf->args->paras->paras->at(i)->second;
		Type_standard_type* y = (Type_standard_type*)x;
		key += y->standard_type->name;
	}
	shf->label = key;
	Type_standard_type* st_type = new Type_standard_type(shf->ident->line, shf->ident->column, shf->type);
	Symbol* sym = new Symbol(shf->ident->name, "f", st_type);
	Symbol* temp = this->scopes->at(0)->hashTab->GetMember(key);
	if (temp == NULL)
	{
		this->scopes->at(0)->hashTab->AddKey(key, sym);
		shf->ident->symbol = sym;
		shf->ident->symbol->label = key;
		return true;
	}
	else
	{
		cout << "Redifinition Function " << shf->ident->name << "at " << shf->ident->line << ' ' << ident->column << ' ' << '\n';
		return false;
	}
}

*/

bool SymbolTable::add_subprogram(Subprogram_declaration* sd)
{
	Subprogram_head* sh = sd->sh;
	string key = "f" + sh->ident->name;
	for (int i = 0; i < sh->args->paras->paras->size(); i++)
	{
		Type* x = sh->args->paras->paras->at(i)->second;
		Type_standard_type* y = (Type_standard_type*)x;
		key += y->standard_type->name;
	}
	sh->label = key;
	Type_standard_type* st_type = new Type_standard_type(sh->ident->line, sh->ident->column, sh->type);
	Symbol* sym = new Symbol(sh->ident->name, "f", st_type);
	Symbol* temp = this->scopes->at(0)->hashTab->GetMember(key);
	if (temp == NULL)
	{
		this->scopes->at(0)->hashTab->AddKey(key, sym);
		sh->ident->symbol = sym;
		sh->ident->symbol->label = key;
		sym->sd = sd;
		return true;
	}
	else
	{
		cout << "Redifinition Function " << sh->ident->name << " at " << sh->ident->line << ' ' << sh->ident->column << ' ' << '\n';
		return false;
	}
}

/*
bool SymbolTable::add_procedure(Ident* ident, Arguments* arguments)
{
	string key = "f" + ident->name;
	for (int i = 0; i < arguments->paras->paras->size(); i++)
	{
		Type* x = arguments->paras->paras->at(i)->second;
		Type_standard_type* y = (Type_standard_type*)x;
		key += y->standard_type->name;
	}

	Standard_type* vd = new Standard_type_integer(ident->line, ident->column);

	Type_standard_type* st_type = new Type_standard_type(ident->line, ident->column, vd);
	Symbol* sym = new Symbol(ident->name, "f", st_type);
	Symbol* temp = this->scopes->at(0)->hashTab->GetMember(key);
	if (temp == NULL)
	{
		this->scopes->at(0)->hashTab->AddKey(key, sym);
		ident->symbol = sym;
		return true;
	}
	else
	{
		cout << "Redifinition Procedure " << ident->name << "at " << ident->line << ' ' << ident->column << ' ' << '\n';
		return false;
	}
}
*/
Symbol* SymbolTable::lookup_symbol(Ident* ident)
{
	string key = "a" + ident->name;
	Symbol* sym;
	sym = this->current->hashTab->GetMember(key);
	if (sym != NULL)
	{
		ident->symbol = sym;
		return sym;
	}
	key = "l" + ident->name;
	cout << key << '\n';
	sym = this->current->hashTab->GetMember(key);
	if (sym != NULL)
	{
		ident->symbol = sym;
	}
	else
	{
		key = "g" + ident->name;
		sym = this->scopes->at(0)->hashTab->GetMember(key);
		if (sym != NULL)
			{
			ident->symbol = sym;
			}
		else
		{
			cout << "undeclared function " << ident->name << " at line " << ident->line << '\n';

		}
	}
	return sym;
	
	
}
Symbol* SymbolTable::lookup_function(Ident* ident, Expression_list* el)
{
	string key = "f" + ident->name;
	Symbol* sym;
	Expression* ex;
	for (int i = 0; i < el->expressions->size(); i++)
	{
		ex = el->expressions->at(i);
		Type_standard_type* st = (Type_standard_type*)ex->type;
		key += st->get_type();
		
	}
	sym = this->current->hashTab->GetMember(key);
	if (sym != NULL)
	{
		ident->symbol = sym;
		return sym;
	}
	else
	{
		cout << "undeclared function " << ident->name << " at line " << ident->line  << '\n';

	}
	
	return sym;
	
	
}

void SymbolTable::new_scope()
{
	this->scopes->push_back(new Scope());
	this->current = this->scopes->at(this->scopes->size() - 1);
}

void SymbolTable::close_scope()
{
	this->current = this->scopes->at(0);
}



/////////////////////////////////////////// TYPE VISITOR /////////////////////////////////

void Type_visitor::visit(Node* var)
{
	
}
void Type_visitor::visit(Root* var)
{
	var->compound_statement->accept(this);
	var->ident->accept(this);
	var->subprogram_declarations->accept(this);
	
	var->declarations->accept(this);

}
void Type_visitor::visit(Ident* var)
{
	
}
void Type_visitor::visit(Declarations* var)
{

}
void Type_visitor::visit(Subprogram_declarations* var)
{
	for (int i = 0; i < var->sub_decs->size(); i++)
	{
		var->sub_decs->at(i)->accept(this);
	}
}
void Type_visitor::visit(Compound_statement* var)
{
	var->optional_statement->accept(this);
}
void Type_visitor::visit(Identifier_list* var)
{
	for (int i = 0; i < var->idents->size(); i++)
	{
		var->idents->at(i)->accept(this);
	}
}
void Type_visitor::visit(Type* var)
{
	
}
void Type_visitor::visit(Standard_type* var)
{
	
}
void Type_visitor::visit(Standard_type_integer* var)
{
	
}
void Type_visitor::visit(Standard_type_real* var)
{
	
}
void Type_visitor::visit(Standard_type_boolean* var)
{
	
}
void Type_visitor::visit(Standard_type_string* var)
{
	
}
void Type_visitor::visit(Intnum* var)
{
	
}
void Type_visitor::visit(Realnum* var)
{

}
void Type_visitor::visit(Subprogram_declaration* var)
{
	
	var->sh->accept(this);
	var->cs->accept(this);
	
}
void Type_visitor::visit(Subprogram_head* var)
{
}

void Type_visitor::visit(Arguments* var)
{
	var->paras->accept(this);
}

void Type_visitor::visit(Parameter_list* var)
{
	for (int i = 0; i < var->paras->size(); i++)
	{
		var->paras->at(i)->first->accept(this);
		var->paras->at(i)->second->accept(this);
	}
}

void Type_visitor::visit(Optional_statements* var)
{
	
}

void Type_visitor::visit(Optional_statements_list* var)
{
	var->statement_list->accept(this);

}

void Type_visitor::visit(Optional_statements_empty* var)
{


}

void Type_visitor::visit(Statement* var)
{

}
void Type_visitor::visit(Statement_list* var)
{
	for (int i = 0; i < var->statements->size(); i++)
	{
		var->statements->at(i)->accept(this);
	}
}
void Type_visitor::visit(Variable* var)
{
	
}
void Type_visitor::visit(Expression* var)
{

}
void Type_visitor::visit(Procedure_statement* var)
{

}
void Type_visitor::visit(Expression_list* var)
{
	for (int i = 0; i < var->expressions->size(); i++)
	{
		var->expressions->at(i)->accept(this);
	}

}
void Type_visitor::visit(Unary_operator* var)
{
	
}
void Type_visitor::visit(Unary_operator_plus* var)
{

}
void Type_visitor::visit(Unary_operator_minus* var)
{


}
void Type_visitor::visit(Unary_operator_multiply* var)
{


}
void Type_visitor::visit(Unary_operator_divide* var)
{


}
void Type_visitor::visit(Unary_operator_div* var)
{
	

}
void Type_visitor::visit(Unary_operator_ge* var)
{
	
}
void Type_visitor::visit(Unary_operator_le* var)
{


}
void Type_visitor::visit(Unary_operator_greater* var)
{


}
void Type_visitor::visit(Unary_operator_less* var)
{


}
void Type_visitor::visit(Unary_operator_eq* var)
{


}
void Type_visitor::visit(Unary_operator_ne* var)
{


}
void Type_visitor::visit(Unary_operator_not* var)
{


}
void Type_visitor::visit(Unary_operator_or* var)
{


}
void Type_visitor::visit(Unary_operator_and* var)
{


}


void Type_visitor::visit(Type_standard_type* var)
{

	var->standard_type->accept(this);
}

void Type_visitor::visit(Type_array* var)
{

	var->type->accept(this);
	var->right->accept(this);
	var->type->accept(this);

}

void Type_visitor::visit(Subprogram_head_fucntion* var)
{

	var->type->accept(this);
	var->ident->accept(this);
	var->args->accept(this);
}

void Type_visitor::visit(Subprogram_head_procedure* var)
{

	var->ident->accept(this);
	var->args->accept(this);

}

void Type_visitor::visit(Statement_assigment* var)
{
	var->expression->accept(this);
	var->variable->accept(this);
	
	
}

void Type_visitor::visit(Statement_procedure* var)
{
	var->procedure_statement->accept(this);
}

void Type_visitor::visit(Procedure_statement_expression_list* var)
{

	var->ident->accept(this);
	var->expression_list->accept(this);

}

void Type_visitor::visit(Procedure_statement_ident* var)
{

	var->ident->accept(this);
}

void Type_visitor::visit(Statement_compound* var)
{

	var->compound_statement->accept(this);

}

void Type_visitor::visit(Statement_if* var)
{
	var->expression->accept(this);
	var->statement->accept(this);

}

void Type_visitor::visit(Statement_if_else* var)
{
	var->expression->accept(this);
	var->statement1->accept(this);
	var->statement2->accept(this);

}

void Type_visitor::visit(Statement_while* var)
{
	var->expression->accept(this);
	var->statement->accept(this);
}

void Type_visitor::visit(Variable_ident* var)
{

	var->ident->accept(this);
}

void Type_visitor::visit(Variable_expression_list* var)
{

	var->expression_list->accept(this);
	var->ident->accept(this);
}

void Type_visitor::visit(Expression_ident* var)
{
	var->ident->accept(this);
	var->type = var->ident->symbol->type;
}

void Type_visitor::visit(Expression_intnum* var)
{

	var->intnum->accept(this);
	Standard_type_integer* st = new Standard_type_integer(var->line, var->column);
	var->type = new Type_standard_type(var->line, var->column, st);
}

void Type_visitor::visit(Expression_realnum* var)
{
	Standard_type_real* st = new Standard_type_real(var->line, var->column);
	var->type = new Type_standard_type(var->line, var->column, st);
}

void Type_visitor::visit(Expression_true* var)
{
	Standard_type_boolean* st = new Standard_type_boolean(var->line, var->column);
	var->type = new Type_standard_type(var->line, var->column, st);

}

void Type_visitor::visit(Expression_false* var)
{
	Standard_type_boolean* st = new Standard_type_boolean(var->line, var->column);
	var->type = new Type_standard_type(var->line, var->column, st);

}

void Type_visitor::visit(Expression_expression_list* var)
{
	/*
	cout << "this is Expression_expression_list" << '\n';
	var->ident->accept(this);
	var->expression_list->accept(this);
	*/
}

void Type_visitor::visit(Expression_expression* var)
{
	/*
	cout << "this is Expression_expression" << '\n';
	var->expression->accept(this);
	*/
}

void Type_visitor::visit(Expression_unary* var)
{
	var->expression1->accept(this);
	var->expression2->accept(this);
	Type* type = Checker::unary_check(var->expression1, var->expression2);
	if (type == NULL)
	{
		cout << "cannot perform the unary operation " << var->line << ' ' << var->column << '\n';
	}
	else
	{
		var->expression1->type = type;
		var->expression2->type = type;
	}
	var->type = type;
	
}

void Type_visitor::visit(Expression_not* var)
{
	
	if (!Checker::check_boolean(var))
	{
		cout << "You cannot perform the NOT operation on non-boolean varialbe at " << var->line << ' ' << var->column << '\n';
	}
}



///////////////////////////Unary Checker////////////////////////


Type* Checker::unary_check(Expression* expression1, Expression* expression2)
{
	
	string left = expression1->type->get_type();
	string right = expression2->type->get_type();
	if (left == "array" || right == "array")
	{
		cout << "cannot perform unary operator in arrays at " << expression1->line << ' ' << expression1->column << '\n';
		return NULL;
	}
	if (left == right)
	{
		return new Type_standard_type(expression1->line, expression1->column, ((Type_standard_type*)expression1->type)->standard_type);
	}

	if ((left == "real" && right == "integer"))
	{
		Standard_type_real* st = new Standard_type_real(expression1->line, expression1->column);
		return new Type_standard_type(expression1->line, expression1->column, st);
	}
	else
	{
		cout << "invalid unary operator at line " << expression1->line << '\n';
		return NULL;
	}
}


bool Checker::check_boolean(Expression* expression)
{

	string name = expression->type->get_type();
	if (name != "boolean")
	{
		return false;
	}
	return true;
}



/////////////////////////////// Code Visitor //////////////////////////////


void Code_visitor::visit(Node* var)
{
}
void Code_visitor::visit(Root* var)
{
	
	vout << "start" << '\n';
	var->declarations->accept(this);
	var->subprogram_declarations->accept(this);
	var->compound_statement->accept(this);
	vout << "stop" << '\n';

}
void Code_visitor::visit(Ident* var)
{
	Type_standard_type* st = (Type_standard_type*)(var->symbol->type);
	Generator::push_ident(var, st->standard_type, var->symbol->kind);

}
void Code_visitor::visit(Declarations* var)
{
	Type* tp;
	Type_standard_type* ttp;
	Type_array* tap;
	for (int i = 0; i < var->decs->size(); i++)
	{
		tp = var->decs->at(i)->second;
		if (tp->get_type() == "array")
		{
			Generator::fp++;
			Ident* ident = var->decs->at(i)->first->idents->at(0);
			tap = (Type_array*)tp;
			vout << "alloc " << tap->right->num - tap->left->num + 1 << '\n';
			ident->symbol->location = Generator::fp;
			if (ident->symbol->kind == "g")
			{
				
				
				vout << "storeg " << Generator::fp << '\n';
				vout << "pushg " << Generator::fp << '\n';
			}
			else
			{
				
				
				vout << "storel " << Generator::fp << '\n';
				vout << "pushl " << Generator::fp << '\n';
			}
			for (int k = tap->left->num; k <= tap->right->num; k++)
			{
				if (ident->symbol->kind == "g")
				{
					vout << "pushg " << ident->symbol->location << '\n';
					vout << "pushi " << k- tap->left->num << '\n';
					if (tap->type->name == "real")
					{
						vout << "pushf 0.0" << '\n';
					}
					else
					{
						vout << "pushi 0" << '\n';
					}
					vout << "storen" << '\n';
				}
			}
			continue;
		}
		ttp = (Type_standard_type*)tp;
		for (int j = 0; j < var->decs->at(i)->first->idents->size(); j++)
		{
			Generator::initialize(var->decs->at(i)->first->idents->at(j), ttp->standard_type, var->decs->at(i)->first->idents->at(j)->symbol->kind);
			
		}
	}
}
void Code_visitor::visit(Subprogram_declarations* var)
{
	int x = Generator::fp;
	Generator::fp = 0;
	for (int i = 0; i < var->sub_decs->size(); i++)
	{
		Subprogram_head* sh = var->sub_decs->at(i)->sh;
		string key = "f" + sh->ident->name;
		for (int i = 0; i < sh->args->paras->paras->size(); i++)
		{
			Type* x = sh->args->paras->paras->at(i)->second;
			Type_standard_type* y = (Type_standard_type*)x;
			key += y->standard_type->name;
		}
		vout << "jump end_" << key << '\n';
		vout << key << ":" << '\n';
		int n = sh->args->paras->paras->size();
		for (int j = n; j > 0; j--)
		{
			vout << "pushl -" << j << '\n';
			vout << "storel " << n - j <<  '\n';
			vout << "pushl " << n - j <<  '\n';
			sh->args->paras->paras->at(n - j)->first->idents->at(0)->symbol->location = n - j;
			sh->args->paras->paras->at(n - j)->first->idents->at(0)->symbol->kind = "l";
			sh->args->paras->paras->at(n - j)->first->idents->at(0)->symbol->type = sh->args->paras->paras->at(n - j)->second;
		}
		
		Generator::fp = n;
		var->sub_decs->at(i)->local_decs->accept(this);
		var->sub_decs->at(i)->cs->accept(this);
		vout << "return" << '\n';
		vout << "end_" << key << ":" << '\n';
		Generator::fp = x;
	}
}
void Code_visitor::visit(Compound_statement* var)
{
	var->optional_statement->accept(this);
}
void Code_visitor::visit(Identifier_list* var)
{
	
}
void Code_visitor::visit(Type* var)
{

}
void Code_visitor::visit(Standard_type* var)
{


}
void Code_visitor::visit(Intnum* var)
{
	vout << "pushi " << var->num << '\n';

}
void Code_visitor::visit(Realnum* var)
{
	
	vout << std::fixed << std::setprecision(2) << "pushf " << var->num << '\n';
}
void Code_visitor::visit(Subprogram_declaration* var)
{
	
}
void Code_visitor::visit(Subprogram_head* var)
{

}

void Code_visitor::visit(Arguments* var)
{

}

void Code_visitor::visit(Parameter_list* var)
{
	
}

void Code_visitor::visit(Optional_statements* var)
{

}

void Code_visitor::visit(Optional_statements_list* var)
{
	var->statement_list->accept(this);
}

void Code_visitor::visit(Optional_statements_empty* var)
{


}

void Code_visitor::visit(Statement* var)
{

}
void Code_visitor::visit(Statement_list* var)
{
	for (int i = 0; i < var->statements->size(); i++)
	{
		var->statements->at(i)->accept(this);
		
	}
}
void Code_visitor::visit(Variable* var)
{

}
void Code_visitor::visit(Expression* var)
{

}
void Code_visitor::visit(Procedure_statement* var)
{

}
void Code_visitor::visit(Procedure_statement_expression_list * var)
{
	var->expression_list->accept(this);
	string key = "f";
	key += var->ident->name;
	for (int i = 0; i < var->expression_list->expressions->size(); i++)
	{
		key += var->expression_list->expressions->at(i)->type->get_type();
	}
	vout << "pusha " << key << '\n';
	vout << "call" << '\n';
	
	


}
void Code_visitor::visit(Expression_list* var)
{
	
	for (int i = 0; i < var->expressions->size(); i++)
	{
		var->expressions->at(i)->accept(this);
	}
}
void Code_visitor::visit(Unary_operator* var)
{

}
void Code_visitor::visit(Unary_operator_plus* var)
{


}
void Code_visitor::visit(Unary_operator_minus* var)
{


}
void Code_visitor::visit(Unary_operator_multiply* var)
{


}
void Code_visitor::visit(Unary_operator_divide* var)
{

}
void Code_visitor::visit(Unary_operator_div* var)
{

}
void Code_visitor::visit(Unary_operator_ge* var)
{
	

}
void Code_visitor::visit(Unary_operator_le* var)
{

}
void Code_visitor::visit(Unary_operator_greater* var)
{

}
void Code_visitor::visit(Unary_operator_less* var)
{

}
void Code_visitor::visit(Unary_operator_eq* var)
{

}
void Code_visitor::visit(Unary_operator_ne* var)
{

}
void Code_visitor::visit(Unary_operator_not* var)
{

}
void Code_visitor::visit(Unary_operator_or* var)
{

}
void Code_visitor::visit(Unary_operator_and* var)
{

}


void Code_visitor::visit(Type_standard_type* var)
{

}

void Code_visitor::visit(Type_array* var)
{


}

void Code_visitor::visit(Subprogram_head_fucntion* var)
{

}

void Code_visitor::visit(Subprogram_head_procedure* var)
{


}

void Code_visitor::visit(Statement_assigment* var)
{
	
	if (var->variable->kind == "array")
	{
		Variable_expression_list* ve = (Variable_expression_list*)var->variable;
		if (ve->ident->symbol->kind == "g")
		{
			vout << "pushg " << ve->ident->symbol->location << '\n';
		}
		else
		{
			vout << "pushl " << ve->ident->symbol->location << '\n';
		}
		Expression_intnum* exn = (Expression_intnum*)ve->expression_list->expressions->at(0);
		vout << "pushi " << exn->intnum->num << '\n';
		

		var->expression->accept(this);
		vout << "storen\n";




		return;
	}
	Variable_ident* vi = (Variable_ident*)var->variable;
	if (vi->ident->symbol->type->get_type() == "real" && var->expression->type->get_type() == "integer")
	{
		Expression_intnum* ei = (Expression_intnum*)var->expression;
		vout << std::fixed << std::setprecision(2) << "pushf " << (float)ei->intnum->num << '\n';

	}
	else {
		var->expression->accept(this);
	}
	
	if (vi->ident->symbol->kind == "g")
	{
		vout << "storeg " << vi->ident->symbol->location << '\n';
		vout << "pushg " << vi->ident->symbol->location << '\n';
	}
	else
	{
		vout << "storel " << vi->ident->symbol->location << '\n';
		vout << "pushl " << vi->ident->symbol->location << '\n';
	}

}

void Code_visitor::visit(Statement_procedure* var)
{
	var->procedure_statement->accept(this);
}



void Code_visitor::visit(Procedure_statement_ident* var)
{
	
}


void Code_visitor::visit(Statement_compound* var)
{
	var->compound_statement->accept(this);
}

void Code_visitor::visit(Statement_if* var)
{
	Generator::if_num++;
	var->expression->accept(this);
	vout << "jz END_IF" << Generator::if_num << '\n';
	var->statement->accept(this);
	vout << "END_IF" << Generator::if_num << ":"<< '\n';
}

void Code_visitor::visit(Statement_if_else* var)
{
	Generator::if_num++;
	var->expression->accept(this);
	vout << "jz ELSE" << Generator::if_num << '\n';
	var->statement1->accept(this);
	vout << "jump " << "END_ELSE" << Generator::if_num << '\n';
	vout << "ELSE" << Generator::if_num << ":" << '\n';
	var->statement2->accept(this);
	vout << "END_ELSE" << Generator::if_num << ":" << '\n';
}

void Code_visitor::visit(Statement_while* var)
{
	Generator::while_num++;
	var->expression->accept(this);
	vout << "jz END_WHILE" << Generator::while_num << '\n';
	vout << "START_WHILE" << Generator::while_num << ":" << '\n';
	var->statement->accept(this);


	var->expression->accept(this);
	vout << "jz END_WHILE" << Generator::while_num << '\n';
	vout << "jump START_WHILE" << Generator::while_num << '\n';
	vout << "END_WHILE" << Generator::while_num << ":" << '\n';
}

void Code_visitor::visit(Variable_ident* var)
{
	Type_standard_type* st= (Type_standard_type*)var->ident->symbol->type;
	Generator::push_ident(var->ident, st->standard_type, var->ident->symbol->kind);
}

void Code_visitor::visit(Variable_expression_list* var)
{
	Type_array* st = (Type_array*)var->ident->symbol->type;
	if (var->ident->symbol->kind == "g")
	{
		vout << "pushg " << var->ident->symbol->location << '\n';
		Expression_intnum* ex = (Expression_intnum*)var->expression_list->expressions->at(0);
		vout << "load " << ex->intnum->num << '\n';
	}
	else
	{
		vout << "pushl " << var->ident->symbol->location << '\n';
		Expression_intnum* ex = (Expression_intnum*)var->expression_list->expressions->at(0);
		vout << "load " << ex->intnum->num << '\n';
	}
}

void Code_visitor::visit(Expression_ident* var)
{
	Type_standard_type* st= (Type_standard_type*)var->type;
	Generator::push_ident(var->ident, st->standard_type, var->ident->symbol->kind);
}

void Code_visitor::visit(Expression_intnum* var)
{
	var->intnum->accept(this);

}

void Code_visitor::visit(Expression_realnum* var)
{
	var->realnum->accept(this);
}

void Code_visitor::visit(Expression_true* var)
{


}

void Code_visitor::visit(Expression_false* var)
{


}

void Code_visitor::visit(Expression_expression_list* var)
{
	
}

void Code_visitor::visit(Expression_expression* var)
{

}

void Code_visitor::visit(Expression_unary* var)
{

	var->expression1->accept(this);
	var->expression2->accept(this);
	Type_standard_type* st = (Type_standard_type*)var->type;
	Generator::unary(st->standard_type, var->unary_operator->kind);
}

void Code_visitor::visit(Expression_not* var)
{

}









/////////////////////////////// Code Generator ////////////////////////////////

int Generator::fp = -1;
int Generator::gp = -1;
int Generator::if_num = -1;
int Generator::while_num = -1;

void Generator::initialize(Ident* ident, Standard_type* st, string kind)
{
	st->initialize(ident, kind);
}

void Generator::initialize_type(Ident* ident, Standard_type_integer* st, string kind)
{
	if (kind == "g")
	{
		fp++;
		ident->symbol->location = fp;
		vout << "pushi 0" << '\n';
		vout << "storeg " << fp << '\n';
		vout << "pushg " << fp << '\n';
	}
	else
	{
		fp++;
		ident->symbol->location = fp;
		vout << "pushi 0" << '\n';
		vout << "storel " << fp << '\n';
		vout << "pushl " << fp << '\n';
	}
}
void Generator::initialize_type(Ident* ident, Standard_type_real* st, string kind)
{
	if (kind == "g")
	{
		fp++;
		ident->symbol->location = fp;
		vout << "pushf 0.0" << '\n';
		vout << "storeg " << fp << '\n';
		vout << "pushg " << fp << '\n';
	}
	else
	{
		fp++;
		ident->symbol->location = fp;
		vout << "pushf 0.0" << '\n';
		vout << "storel " << fp << '\n';
		vout << "pushl " << fp << '\n';
	}
}
void Generator::initialize_type(Ident* ident, Standard_type_boolean* st, string kind)
{
	
}
void Generator::initialize_type(Ident* ident, Standard_type_string* st, string kind)
{
	
}





void Generator::push_ident(Ident* ident, Standard_type* st, string kind)
{
	st->push_ident(ident, kind);
}

void Generator::push_ident_type(Ident* ident, Standard_type_integer* st, string kind)
{
	if (kind == "g")
	{
		vout << "pushg " << ident->symbol->location << '\n';
	}
	else
	{
		vout << "pushl " << ident->symbol->location << '\n';
	}
}
void Generator::push_ident_type(Ident* ident, Standard_type_real* st, string kind)
{
	if (kind == "g")
	{
		vout << "pushg " << ident->symbol->location << '\n';
	}
	else
	{
		vout << "pushl " << ident->symbol->location << '\n';
	}
}
void Generator::push_ident_type(Ident* ident, Standard_type_boolean* st, string kind)
{
	
}
void Generator::push_ident_type(Ident* ident, Standard_type_string* st, string kind)
{
	
}





void Generator::unary(Standard_type* st, string kind)
{
	st->unary(kind);
}

void Generator::unary_type(Standard_type_integer* st, string kind)
{
	if (kind == "+")
	{
		vout << "add" << '\n';
	}
	else if (kind == "-")
	{
		vout << "sub" << '\n';
	}
	else if (kind == "*")
	{
		vout << "mul" << '\n';
	}
	else if (kind == "div")
	{
		vout << "div" << '\n';
	}
	else if (kind == "ge")
	{
		vout << "infeq" << '\n';
	}
	else if (kind == "le")
	{
		vout << "supeq" << '\n';
	}
	else if (kind == "greater")
	{
		vout << "inf" << '\n';
	}
	else if (kind == "less")
	{
		vout << "sup" << '\n';
	}
	

	
}
void Generator::unary_type(Standard_type_real* st, string kind)
{
	if (kind == "+")
	{
		vout << "fadd" << '\n';
	}
	else if (kind == "-")
	{
		vout << "fsub" << '\n';
	}
	else if (kind == "*")
	{
		vout << "fmul" << '\n';
	}
	else if (kind == "fdiv")
	{
		vout << "fdiv" << '\n';
	}
	else if (kind == "ge")
	{
		vout << "finfeq" << '\n';
	}
	else if (kind == "le")
	{
		vout << "fsupeq" << '\n';
	}
	else if (kind == "greater")
	{
		vout << "finf" << '\n';
	}
	else if (kind == "less")
	{
		vout << "fsup" << '\n';
	}
}
void Generator::unary_type(Standard_type_boolean* st, string kind)
{
	
}
void Generator::unary_type(Standard_type_string* st, string kind)
{
	
}






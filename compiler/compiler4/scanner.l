
%{
#include "ast.h"
	#include "stdio.h"
	#include "parser.h"
	
	#include <iostream>
	using std::cout;	
	using std::endl;
	using std::left;
	
	
	#define YY_INPUT(buf,result,max_size) \
    { \
    int c = getchar(); \
    result = (c == EOF) ? YY_NULL : (buf[0] = c, 1); \
    }\

	
	#include "parser.h"
	
	int lin = 1, col = 1, errorno = 0;
%}
%x comment
REAL1	(0|[1-9][0-9]*)"."[0-9]*([eE][-+]?(0|[1-9][0-9]*))?
REAL2	"."[0-9]+([eE][-+]?(0|[1-9][0-9]*))?
REAL3	(0|[1-9][0-9]*)([eE][-+]?(0|[1-9][0-9]*))
%option noyywrap
%%
"/*"					{
						BEGIN(comment); col += yyleng;
						}
<comment>[^*\n]*		col += yyleng;
<comment>"*"+[^*/\n]*	col += yyleng;
<comment>\n				lin++; col = 1;
<comment>"*"+"/"		BEGIN(0); col += yyleng;

"//".*\n				lin++; col = 1;


"boolean"			{						
						col += yyleng;
						return BOOLEAN;
					}

":="			{						
						col += yyleng;
						return ASSIGNMENT;
					}

"real"				{
						col += yyleng;
						return REAL;
					}
"integer"				{
						col += yyleng;
						return INTEGER;
					}
"if"				{
						col += yyleng;
						return IF;
					}
"else"				{
						col += yyleng;
						return ELSE;
					}
"then"				{
						col += yyleng;
						return THEN;
					}
"while"				{
						col += yyleng;
						return WHILE;
					}
"return"				{
						col += yyleng;
						return RETURN;
					}
"do"				{
						col += yyleng;
						return DO;
					}
"false"				{
						col += yyleng;
						return FALSE;
					}
"true"				{
						col += yyleng;
						return TRUE;
					}
">="				{
						col += yyleng;
						return LE;
					}
">"					{
						col += yyleng;
						return LESS;
					}
"<="				{						
						col += yyleng;
						return GE;
					}
"<"				{						
						col += yyleng;
						return GREATER;
					}
"="					{
						col += yyleng;
						return EQ;
					}
"<>"				{
						col += yyleng;
						return NE;
					}
"and"				{
						col += yyleng;
						return AND;
					}
"or"				{
						col += yyleng;
						return OR;
					}
			
	
"not"				{
						col += yyleng;
						return NOT;
					}
"program"				{
						col += yyleng;
						return PROGRAM;
					}
"var"				{
						col += yyleng;
						return VAR;
					}
"function"				{
						col += yyleng;
						return FUNCTION;
					}
"procedure"				{
						col += yyleng;
						return PROCEDURE;
					}
"begin"				{
						col += yyleng;
						return BEG;
					}
"end"				{
						col += yyleng;
						return END;
					}
"array"				{
						col += yyleng;
						return ARRAY;
					}
"of"				{
						col += yyleng;
						return OF;
					}
"div"				{
						col += yyleng;
						return DIV;
					}
";"					{
						col += yyleng;
						return *yytext;
					}
[0-9][0-9]*		{
						col += yyleng;
						yylval.tIntnum = new Intnum(lin, col, atoi(yytext));
						return INTNUM;
					}
					
(0|[1-9][0-9]*)"."[0-9]*([eE][-+]?(0|[1-9][0-9]*))? |
"."[0-9]+([eE][-+]?(0|[1-9][0-9]*))?				|
(0|[1-9][0-9]*)([eE][-+]?(0|[1-9][0-9]*))			{
														col += yyleng;
														yylval.tRealnum = new Realnum(lin, col, atof(yytext));
														return REALNUM;
													}

[\"][^\n\t]*[\"] {
        col+=yyleng;
        return STRINGNUM;
           }

([a-zA-Z]|_)([a-zA-Z]|[0-9]|_)*	{
									col += yyleng;
									yylval.tIdent = new Ident(lin, col, strdup(yytext));
									return IDENT;
								}
[\t]*				{
					col += 4 * yyleng;
					}

[ ]*				{
					col += yyleng;
					}
\n					{
					lin++; col = 1;
					}
[-+*\/=<>;:(),{}\[\]\?!]	{
							return *yytext;
							}
.					{
						col += yyleng;
						errorno++;
					}
%%



   
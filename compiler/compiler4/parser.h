/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     BOOLEAN = 258,
     REAL = 259,
     INTEGER = 260,
     VAR = 261,
     ARRAY = 262,
     DIGIT = 263,
     INTNUM = 264,
     REALNUM = 265,
     STRINGNUM = 266,
     IDENT = 267,
     IF = 268,
     ELSE = 269,
     THEN = 270,
     WHILE = 271,
     DO = 272,
     OF = 273,
     RETURN = 274,
     TRUE = 275,
     FALSE = 276,
     AND = 277,
     OR = 278,
     NOT = 279,
     DIV = 280,
     PROGRAM = 281,
     FUNCTION = 282,
     PROCEDURE = 283,
     BEG = 284,
     END = 285,
     ASSIGNMENT = 286,
     LE = 287,
     LESS = 288,
     GE = 289,
     GREATER = 290,
     EQ = 291,
     NE = 292
   };
#endif
/* Tokens.  */
#define BOOLEAN 258
#define REAL 259
#define INTEGER 260
#define VAR 261
#define ARRAY 262
#define DIGIT 263
#define INTNUM 264
#define REALNUM 265
#define STRINGNUM 266
#define IDENT 267
#define IF 268
#define ELSE 269
#define THEN 270
#define WHILE 271
#define DO 272
#define OF 273
#define RETURN 274
#define TRUE 275
#define FALSE 276
#define AND 277
#define OR 278
#define NOT 279
#define DIV 280
#define PROGRAM 281
#define FUNCTION 282
#define PROCEDURE 283
#define BEG 284
#define END 285
#define ASSIGNMENT 286
#define LE 287
#define LESS 288
#define GE 289
#define GREATER 290
#define EQ 291
#define NE 292




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 38 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
typedef union YYSTYPE {
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
 } YYSTYPE;
/* Line 1447 of yacc.c.  */
#line 138 "parser.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;




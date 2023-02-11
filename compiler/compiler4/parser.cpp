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

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"

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


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

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
/* Line 196 of yacc.c.  */
#line 201 "parser.cpp"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 219 of yacc.c.  */
#line 213 "parser.cpp"

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T) && (defined (__STDC__) || defined (__cplusplus))
# include <stddef.h> /* INFRINGES ON USER NAME SPACE */
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if defined (__STDC__) || defined (__cplusplus)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     define YYINCLUDED_STDLIB_H
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2005 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM ((YYSIZE_T) -1)
#  endif
#  ifdef __cplusplus
extern "C" {
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if (! defined (malloc) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if (! defined (free) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifdef __cplusplus
}
#  endif
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   170

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  28
/* YYNRULES -- Number of rules. */
#define YYNRULES  70
/* YYNRULES -- Number of states. */
#define YYNSTATES  133

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      50,    51,    40,    38,    46,    39,     2,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    47,    45,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    48,     2,    49,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    42,    43,    44
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned char yyprhs[] =
{
       0,     0,     3,     4,    12,    14,    18,    25,    26,    28,
      38,    40,    42,    44,    46,    50,    51,    52,    59,    60,
      65,    72,    73,    74,    82,    83,    89,    93,    94,    98,
     104,   105,   110,   112,   113,   115,   119,   123,   125,   127,
     132,   139,   144,   146,   151,   153,   158,   160,   164,   166,
     168,   170,   172,   174,   179,   183,   187,   190,   192,   194,
     196,   198,   200,   202,   204,   206,   208,   210,   212,   214,
     216
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      53,     0,    -1,    -1,    26,    12,    45,    56,    54,    59,
      70,    -1,    12,    -1,    55,    46,    12,    -1,    56,     6,
      55,    47,    57,    45,    -1,    -1,    58,    -1,     7,    48,
       9,    46,    46,     9,    49,    18,    58,    -1,     5,    -1,
       4,    -1,     3,    -1,    11,    -1,    59,    60,    45,    -1,
      -1,    -1,    64,    63,    61,    70,    19,    78,    -1,    -1,
      66,    63,    62,    70,    -1,    63,     6,    55,    47,    57,
      45,    -1,    -1,    -1,    27,    12,    65,    68,    47,    58,
      45,    -1,    -1,    28,    12,    67,    68,    45,    -1,    50,
      69,    51,    -1,    -1,    55,    47,    57,    -1,    69,    45,
      55,    47,    57,    -1,    -1,    29,    72,    30,    71,    -1,
      73,    -1,    -1,    74,    -1,    73,    45,    74,    -1,    75,
      31,    78,    -1,    76,    -1,    70,    -1,    13,    78,    15,
      74,    -1,    13,    78,    15,    74,    14,    74,    -1,    16,
      78,    17,    74,    -1,    12,    -1,    12,    48,    77,    49,
      -1,    12,    -1,    12,    50,    77,    51,    -1,    78,    -1,
      77,    46,    78,    -1,    12,    -1,     9,    -1,    10,    -1,
      20,    -1,    21,    -1,    12,    50,    77,    51,    -1,    50,
      78,    51,    -1,    78,    79,    78,    -1,    24,    78,    -1,
      38,    -1,    39,    -1,    40,    -1,    41,    -1,    25,    -1,
      34,    -1,    32,    -1,    35,    -1,    33,    -1,    36,    -1,
      37,    -1,    24,    -1,    23,    -1,    22,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,    98,    98,    98,   106,   110,   117,   127,   131,   135,
     140,   144,   148,   152,   157,   164,   168,   168,   175,   175,
     184,   194,   198,   198,   203,   203,   208,   215,   219,   227,
     236,   236,   242,   247,   251,   255,   262,   266,   270,   274,
     278,   282,   288,   293,   301,   305,   311,   315,   321,   326,
     330,   334,   338,   342,   347,   351,   355,   360,   364,   368,
     372,   376,   380,   384,   388,   392,   396,   400,   404,   408,
     412
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BOOLEAN", "REAL", "INTEGER", "VAR",
  "ARRAY", "DIGIT", "INTNUM", "REALNUM", "STRINGNUM", "IDENT", "IF",
  "ELSE", "THEN", "WHILE", "DO", "OF", "RETURN", "TRUE", "FALSE", "AND",
  "OR", "NOT", "DIV", "PROGRAM", "FUNCTION", "PROCEDURE", "BEG", "END",
  "ASSIGNMENT", "LE", "LESS", "GE", "GREATER", "EQ", "NE", "'+'", "'-'",
  "'*'", "'/'", "\"ifelse\"", "\"then\"", "\"unary\"", "';'", "','", "':'",
  "'['", "']'", "'('", "')'", "$accept", "root", "@1", "identifier_list",
  "declarations", "type", "standard_type", "subprogram_declarations",
  "subprogram_declaration", "@2", "@3", "local_declarations",
  "subprogram_head_function", "@4", "subprogram_head_procedure", "@5",
  "arguments", "parameter_list", "compound_statement", "@6",
  "optional_statements", "statement_list", "statement", "variable",
  "procedure_statement", "expression_list", "expression", "unary_operator", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,    43,    45,
      42,    47,   293,   294,   295,    59,    44,    58,    91,    93,
      40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    52,    54,    53,    55,    55,    56,    56,    57,    57,
      58,    58,    58,    58,    59,    59,    61,    60,    62,    60,
      63,    63,    65,    64,    67,    66,    68,    68,    69,    69,
      71,    70,    72,    72,    73,    73,    74,    74,    74,    74,
      74,    74,    75,    75,    76,    76,    77,    77,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     0,     7,     1,     3,     6,     0,     1,     9,
       1,     1,     1,     1,     3,     0,     0,     6,     0,     4,
       6,     0,     0,     7,     0,     5,     3,     0,     3,     5,
       0,     4,     1,     0,     1,     3,     3,     1,     1,     4,
       6,     4,     1,     4,     1,     4,     1,     3,     1,     1,
       1,     1,     1,     4,     3,     3,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       0,     0,     0,     0,     1,     7,     2,     0,    15,     4,
       0,     0,     0,     0,     0,     0,    33,     0,    21,    21,
       3,     5,    12,    11,    10,     0,    13,     0,     8,    22,
      24,    44,     0,     0,    38,     0,    32,    34,     0,    37,
      14,    16,    18,     0,     6,    27,    27,     0,     0,    49,
      50,    48,    51,    52,     0,     0,     0,     0,    30,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    46,
       0,     0,    56,     0,     0,    70,    69,    68,    61,    63,
      65,    62,    64,    66,    67,    57,    58,    59,    60,     0,
       0,    31,    35,    36,     0,     0,    19,     0,     0,     0,
       0,    25,     0,    43,    45,     0,    54,    39,    55,    41,
       0,     0,     0,     0,     0,    26,     0,    47,    53,     0,
       0,    17,     0,    28,     0,    23,    40,    20,     0,     0,
       0,    29,     9
};

/* YYDEFGOTO[NTERM-NUM]. */
static const yysigned_char yydefgoto[] =
{
      -1,     2,     8,    10,     6,    27,    28,    11,    17,    62,
      63,    41,    18,    45,    19,    46,    66,    99,    34,    91,
      35,    36,    37,    38,    39,    68,    69,    89
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -97
static const short int yypact[] =
{
     -20,     2,    15,    -7,   -97,   -97,    45,    51,   -97,   -97,
      19,    -2,    63,   150,    66,    80,    64,    22,   -97,   -97,
     -97,   -97,   -97,   -97,   -97,    21,   -97,    75,   -97,   -97,
     -97,   -13,     0,     0,   -97,    92,    76,   -97,    93,   -97,
     -97,   117,   117,   116,   -97,    88,    88,     0,     0,   -97,
     -97,    89,   -97,   -97,     0,     0,    49,    74,   -97,    64,
       0,    51,   112,   112,   110,    51,   113,    95,   -30,    94,
      54,     0,   111,     7,    64,   -97,   -97,   -97,   -97,   -97,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,     0,
      64,   -97,   -97,    94,    48,   139,   -97,   118,    55,   -40,
      50,   -97,     0,   -97,   -97,    91,   -97,   145,   -97,   -97,
     150,     0,   153,   150,    51,   -97,   120,    94,   -97,    64,
     121,    94,   114,   -97,    57,   -97,   -97,   -97,   149,   150,
      50,   -97,   -97
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
     -97,   -97,   -97,   -58,   -97,   -61,   -96,   -97,   -97,   -97,
     -97,   151,   -97,   -97,   -97,   -97,   122,   -97,    -3,   -97,
     -97,   -97,   -57,   -97,   -97,   -35,   -32,   -97
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -43
static const short int yytable[] =
{
      56,    57,    92,    94,   116,   114,     1,    98,    20,    49,
      50,   115,    51,    70,     3,     4,   102,   107,   -42,   103,
      52,    53,    72,    73,    54,    14,    15,    16,    93,    75,
      76,    77,    78,   109,   132,    47,   105,    48,     5,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,   120,
      55,     7,   123,    22,    23,    24,   124,   108,   106,    95,
      96,    26,   126,     9,    74,    12,    13,    40,   131,    43,
     117,    75,    76,    77,    78,    21,    31,    32,    29,   121,
      33,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    90,    30,    16,    12,   110,    75,    76,    77,    78,
     102,    12,   113,    12,   129,   104,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    75,    76,    77,    78,
      44,    59,    58,    61,    60,    64,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    78,   102,    65,    71,
     101,    16,   118,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    22,    23,    24,    97,    25,   111,   119,
     100,    26,   122,   128,   112,   125,   127,   130,    67,     0,
      42
};

static const short int yycheck[] =
{
      32,    33,    59,    61,   100,    45,    26,    65,    11,     9,
      10,    51,    12,    48,    12,     0,    46,    74,    31,    49,
      20,    21,    54,    55,    24,    27,    28,    29,    60,    22,
      23,    24,    25,    90,   130,    48,    71,    50,    45,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,   110,
      50,     6,   113,     3,     4,     5,   114,    89,    51,    62,
      63,    11,   119,    12,    15,    46,    47,    45,   129,    48,
     102,    22,    23,    24,    25,    12,    12,    13,    12,   111,
      16,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    17,    12,    29,    46,    47,    22,    23,    24,    25,
      46,    46,    47,    46,    47,    51,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    22,    23,    24,    25,
      45,    45,    30,     6,    31,     9,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    25,    46,    50,    50,
      45,    29,    51,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     3,     4,     5,    46,     7,    19,    14,
      47,    11,     9,    49,    46,    45,    45,    18,    46,    -1,
      19
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    26,    53,    12,     0,    45,    56,     6,    54,    12,
      55,    59,    46,    47,    27,    28,    29,    60,    64,    66,
      70,    12,     3,     4,     5,     7,    11,    57,    58,    12,
      12,    12,    13,    16,    70,    72,    73,    74,    75,    76,
      45,    63,    63,    48,    45,    65,    67,    48,    50,     9,
      10,    12,    20,    21,    24,    50,    78,    78,    30,    45,
      31,     6,    61,    62,     9,    50,    68,    68,    77,    78,
      77,    50,    78,    78,    15,    22,    23,    24,    25,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    79,
      17,    71,    74,    78,    55,    70,    70,    46,    55,    69,
      47,    45,    46,    49,    51,    77,    51,    74,    78,    74,
      47,    19,    46,    47,    45,    51,    58,    78,    51,    14,
      57,    78,     9,    57,    55,    45,    74,    45,    49,    47,
      18,    57,    58
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (0)


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (N)								\
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (0)
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
              (Loc).first_line, (Loc).first_column,	\
              (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr,					\
                  Type, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname[yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      size_t yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

#endif /* YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);


# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()
    ;
#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short int *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short int *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a look-ahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to look-ahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 98 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {symbolTable->add_declarations((yyvsp[0].tDeclarations));;}
    break;

  case 3:
#line 99 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
			(yyval.tRoot) = new Root(lin, col, (yyvsp[-5].tIdent), (yyvsp[-3].tDeclarations), (yyvsp[-1].tSubprogram_declarations), (yyvsp[0].tCompound_statement));
			rt = (yyval.tRoot);
			

		;}
    break;

  case 4:
#line 107 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
						(yyval.tIdentifier_list) = new Identifier_list(lin, col, (yyvsp[0].tIdent));
					;}
    break;

  case 5:
#line 111 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
						(yyvsp[-2].tIdentifier_list)->add_ident((yyvsp[0].tIdent));
						(yyval.tIdentifier_list) = (yyvsp[-2].tIdentifier_list);
					;}
    break;

  case 6:
#line 118 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
						symbolTable->current = symbolTable->scopes->at(0);
						pair<Identifier_list*, Type*>* p = new pair<Identifier_list*, Type*>;
						p->first = (yyvsp[-3].tIdentifier_list);
						p->second = (yyvsp[-1].tType);
						(yyvsp[-5].tDeclarations)->add_declaration(p);
						(yyval.tDeclarations) = (yyvsp[-5].tDeclarations);
					;}
    break;

  case 7:
#line 127 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
						(yyval.tDeclarations) = new Declarations(lin, col);
					 ;}
    break;

  case 8:
#line 132 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
				(yyval.tType) = new Type_standard_type(lin, col, (yyvsp[0].tStandard_type));
			;}
    break;

  case 9:
#line 136 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
				(yyval.tType) = new Type_array(lin, col, (yyvsp[-6].tIntnum), (yyvsp[-3].tIntnum), (yyvsp[0].tStandard_type));
			;}
    break;

  case 10:
#line 141 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
						(yyval.tStandard_type) = new Standard_type_integer(lin, col);
					;}
    break;

  case 11:
#line 145 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
						(yyval.tStandard_type) = new Standard_type_real(lin, col);
					;}
    break;

  case 12:
#line 149 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
						(yyval.tStandard_type) = new Standard_type_boolean(lin, col);
					;}
    break;

  case 13:
#line 153 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
						(yyval.tStandard_type) = new Standard_type_string(lin, col);
					;}
    break;

  case 14:
#line 158 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
								(yyvsp[-2].tSubprogram_declarations)->add_subprogram_declaration((yyvsp[-1].tSubprogram_declaration));

								(yyval.tSubprogram_declarations) = (yyvsp[-2].tSubprogram_declarations);
							;}
    break;

  case 15:
#line 164 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
								(yyval.tSubprogram_declarations) = new Subprogram_declarations(lin, col);
							;}
    break;

  case 16:
#line 168 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {symbolTable->add_local_declarations((yyvsp[0].tDeclarations));;}
    break;

  case 17:
#line 169 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
								(yyval.tSubprogram_declaration) = new Subprogram_declaration(lin, col, (yyvsp[-5].tSubprogram_head), (yyvsp[-4].tDeclarations), (yyvsp[-2].tCompound_statement));
								symbolTable->add_subprogram((yyval.tSubprogram_declaration));
								
							;}
    break;

  case 18:
#line 175 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {symbolTable->add_local_declarations((yyvsp[0].tDeclarations));;}
    break;

  case 19:
#line 176 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
								(yyval.tSubprogram_declaration) = new Subprogram_declaration(lin, col, (yyvsp[-3].tSubprogram_head), (yyvsp[-2].tDeclarations), (yyvsp[0].tCompound_statement));
								symbolTable->add_subprogram((yyval.tSubprogram_declaration));
								
							;}
    break;

  case 20:
#line 185 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
						pair<Identifier_list*, Type*>* p = new pair<Identifier_list*, Type*>;
						p->first = (yyvsp[-3].tIdentifier_list);
						p->second = (yyvsp[-1].tType);
						(yyvsp[-5].tDeclarations)->add_declaration(p);
						(yyval.tDeclarations) = (yyvsp[-5].tDeclarations);
						
						;}
    break;

  case 21:
#line 194 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
							(yyval.tDeclarations) = new Declarations(lin, col);
						;}
    break;

  case 22:
#line 198 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {symbolTable->new_scope();;}
    break;

  case 23:
#line 199 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
						(yyval.tSubprogram_head) = new Subprogram_head_fucntion(lin, col, (yyvsp[-5].tIdent), (yyvsp[-3].tArguments), (yyvsp[-1].tStandard_type));
						
					;}
    break;

  case 24:
#line 203 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {symbolTable->new_scope();;}
    break;

  case 25:
#line 204 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
						(yyval.tSubprogram_head) = new Subprogram_head_procedure(lin, col, (yyvsp[-3].tIdent), (yyvsp[-1].tArguments));
					;}
    break;

  case 26:
#line 209 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
					(yyval.tArguments) = new Arguments(lin, col, (yyvsp[-1].tParameter_list));
					symbolTable->add_parameter_list((yyvsp[-1].tParameter_list));

				;}
    break;

  case 27:
#line 215 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
					(yyval.tArguments) = new Arguments(lin, col);
				;}
    break;

  case 28:
#line 220 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
						pair<Identifier_list*, Type*>* p = new pair<Identifier_list*, Type*>;
						p->first = (yyvsp[-2].tIdentifier_list);
						p->second = (yyvsp[0].tType);
						(yyval.tParameter_list) = new Parameter_list(lin, col, p);
						
					;}
    break;

  case 29:
#line 228 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
						pair<Identifier_list*, Type*>* p = new pair<Identifier_list*, Type*>;
						p->first = (yyvsp[-2].tIdentifier_list);
						p->second = (yyvsp[0].tType);
						(yyvsp[-4].tParameter_list)->add_parameter(p);
						(yyval.tParameter_list) = (yyvsp[-4].tParameter_list);
					;}
    break;

  case 30:
#line 236 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {symbolTable->close_scope();;}
    break;

  case 31:
#line 237 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
							(yyval.tCompound_statement) = new Compound_statement(lin, col, (yyvsp[-2].tOptional_statements));

						;}
    break;

  case 32:
#line 243 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
							(yyval.tOptional_statements) = new Optional_statements_list(lin, col, (yyvsp[0].tStatement_list));
						;}
    break;

  case 33:
#line 247 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
							(yyval.tOptional_statements) = new Optional_statements_empty(lin, col);
						;}
    break;

  case 34:
#line 252 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
						(yyval.tStatement_list) = new Statement_list(lin, col, (yyvsp[0].tStatement));
					;}
    break;

  case 35:
#line 256 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
						(yyvsp[-2].tStatement_list)->add_statement((yyvsp[0].tStatement));
						(yyval.tStatement_list) = (yyvsp[-2].tStatement_list);
					;}
    break;

  case 36:
#line 263 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
					(yyval.tStatement) = new Statement_assigment(lin, col, (yyvsp[-2].tVariable), (yyvsp[0].tExpression));
				;}
    break;

  case 37:
#line 267 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
					(yyval.tStatement) = new Statement_procedure(lin, col, (yyvsp[0].tProcedure_statement));
				;}
    break;

  case 38:
#line 271 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
					(yyval.tStatement) = new Statement_compound(lin, col, (yyvsp[0].tCompound_statement));
				;}
    break;

  case 39:
#line 275 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
					(yyval.tStatement) = new Statement_if(lin, col, (yyvsp[-2].tExpression), (yyvsp[0].tStatement));
				;}
    break;

  case 40:
#line 279 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
					(yyval.tStatement) = new Statement_if_else(lin, col, (yyvsp[-4].tExpression), (yyvsp[-2].tStatement), (yyvsp[0].tStatement));
				;}
    break;

  case 41:
#line 283 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
					(yyval.tStatement) = new Statement_while(lin, col, (yyvsp[-2].tExpression), (yyvsp[0].tStatement));
				;}
    break;

  case 42:
#line 289 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
				(yyval.tVariable) = new Variable_ident(lin, col, (yyvsp[0].tIdent));
				symbolTable->lookup_symbol((yyvsp[0].tIdent));
			;}
    break;

  case 43:
#line 294 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
				(yyval.tVariable) = new Variable_expression_list(lin, col, (yyvsp[-3].tIdent), (yyvsp[-1].tExpression_list));
				symbolTable->lookup_symbol((yyvsp[-3].tIdent));
				cout << "vaaaaaaaaaaaaaaaaaaaaaaaaa\n";
			;}
    break;

  case 44:
#line 302 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
							(yyval.tProcedure_statement) = new Procedure_statement_ident(lin, col, (yyvsp[0].tIdent));
						;}
    break;

  case 45:
#line 306 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
							(yyval.tProcedure_statement) = new Procedure_statement_expression_list(lin, col, (yyvsp[-3].tIdent), (yyvsp[-1].tExpression_list));
						;}
    break;

  case 46:
#line 312 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
						(yyval.tExpression_list) = new Expression_list(lin, col, (yyvsp[0].tExpression));
					;}
    break;

  case 47:
#line 316 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
						(yyvsp[-2].tExpression_list)->add_expression((yyvsp[0].tExpression));
						(yyval.tExpression_list) = (yyvsp[-2].tExpression_list);
					;}
    break;

  case 48:
#line 322 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
					(yyval.tExpression) = new Expression_ident(lin, col, (yyvsp[0].tIdent));
					symbolTable->lookup_symbol((yyvsp[0].tIdent));
				;}
    break;

  case 49:
#line 327 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
					(yyval.tExpression) = new Expression_intnum(lin, col, (yyvsp[0].tIntnum));
				;}
    break;

  case 50:
#line 331 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
					(yyval.tExpression) = new Expression_realnum(lin, col, (yyvsp[0].tRealnum));
				;}
    break;

  case 51:
#line 335 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
					(yyval.tExpression) = new Expression_true(lin, col);
				;}
    break;

  case 52:
#line 339 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
					(yyval.tExpression) = new Expression_false(lin, col);
				;}
    break;

  case 53:
#line 343 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
					(yyval.tExpression) = new Expression_expression_list(lin, col, (yyvsp[-3].tIdent), (yyvsp[-1].tExpression_list));
					symbolTable->lookup_symbol((yyvsp[-3].tIdent));
				;}
    break;

  case 54:
#line 348 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
					(yyval.tExpression) = new Expression_expression(lin, col, (yyvsp[-1].tExpression));
				;}
    break;

  case 55:
#line 352 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
					(yyval.tExpression) = new Expression_unary(lin, col, (yyvsp[-2].tExpression), (yyvsp[0].tExpression), (yyvsp[-1].tUnary_operator));
				;}
    break;

  case 56:
#line 356 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
					(yyval.tExpression) = new Expression_not(lin, col, (yyvsp[0].tExpression));
				;}
    break;

  case 57:
#line 361 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
					(yyval.tUnary_operator) = new Unary_operator_plus(lin, col);
				;}
    break;

  case 58:
#line 365 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
					(yyval.tUnary_operator) = new Unary_operator_minus(lin, col);
				;}
    break;

  case 59:
#line 369 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
					(yyval.tUnary_operator) = new Unary_operator_multiply(lin, col);
				;}
    break;

  case 60:
#line 373 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
					(yyval.tUnary_operator) = new Unary_operator_divide(lin, col);
				;}
    break;

  case 61:
#line 377 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
					(yyval.tUnary_operator) = new Unary_operator_div(lin, col);
				;}
    break;

  case 62:
#line 381 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
					(yyval.tUnary_operator) = new Unary_operator_ge(lin, col);
				;}
    break;

  case 63:
#line 385 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
					(yyval.tUnary_operator) = new Unary_operator_le(lin, col);
				;}
    break;

  case 64:
#line 389 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
					(yyval.tUnary_operator) = new Unary_operator_greater(lin, col);
				;}
    break;

  case 65:
#line 393 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
					(yyval.tUnary_operator) = new Unary_operator_less(lin, col);
				;}
    break;

  case 66:
#line 397 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
					(yyval.tUnary_operator) = new Unary_operator_eq(lin, col);
				;}
    break;

  case 67:
#line 401 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
					(yyval.tUnary_operator) = new Unary_operator_ne(lin, col);
				;}
    break;

  case 68:
#line 405 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
					(yyval.tUnary_operator) = new Unary_operator_not(lin, col);
				;}
    break;

  case 69:
#line 409 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
					(yyval.tUnary_operator) = new Unary_operator_or(lin, col);
				;}
    break;

  case 70:
#line 413 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"
    {
					(yyval.tUnary_operator) = new Unary_operator_and(lin, col);
				;}
    break;


      default: break;
    }

/* Line 1126 of yacc.c.  */
#line 1842 "parser.cpp"

  yyvsp -= yylen;
  yyssp -= yylen;


  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  int yytype = YYTRANSLATE (yychar);
	  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
	  YYSIZE_T yysize = yysize0;
	  YYSIZE_T yysize1;
	  int yysize_overflow = 0;
	  char *yymsg = 0;
#	  define YYERROR_VERBOSE_ARGS_MAXIMUM 5
	  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
	  int yyx;

#if 0
	  /* This is so xgettext sees the translatable formats that are
	     constructed on the fly.  */
	  YY_("syntax error, unexpected %s");
	  YY_("syntax error, unexpected %s, expecting %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
#endif
	  char *yyfmt;
	  char const *yyf;
	  static char const yyunexpected[] = "syntax error, unexpected %s";
	  static char const yyexpecting[] = ", expecting %s";
	  static char const yyor[] = " or %s";
	  char yyformat[sizeof yyunexpected
			+ sizeof yyexpecting - 1
			+ ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
			   * (sizeof yyor - 1))];
	  char const *yyprefix = yyexpecting;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 1;

	  yyarg[0] = yytname[yytype];
	  yyfmt = yystpcpy (yyformat, yyunexpected);

	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
		  {
		    yycount = 1;
		    yysize = yysize0;
		    yyformat[sizeof yyunexpected - 1] = '\0';
		    break;
		  }
		yyarg[yycount++] = yytname[yyx];
		yysize1 = yysize + yytnamerr (0, yytname[yyx]);
		yysize_overflow |= yysize1 < yysize;
		yysize = yysize1;
		yyfmt = yystpcpy (yyfmt, yyprefix);
		yyprefix = yyor;
	      }

	  yyf = YY_(yyformat);
	  yysize1 = yysize + yystrlen (yyf);
	  yysize_overflow |= yysize1 < yysize;
	  yysize = yysize1;

	  if (!yysize_overflow && yysize <= YYSTACK_ALLOC_MAXIMUM)
	    yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg)
	    {
	      /* Avoid sprintf, as that infringes on the user's name space.
		 Don't have undefined behavior even if the translation
		 produced a string with the wrong number of "%s"s.  */
	      char *yyp = yymsg;
	      int yyi = 0;
	      while ((*yyp = *yyf))
		{
		  if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		    {
		      yyp += yytnamerr (yyp, yyarg[yyi++]);
		      yyf += 2;
		    }
		  else
		    {
		      yyp++;
		      yyf++;
		    }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    {
	      yyerror (YY_("syntax error"));
	      goto yyexhaustedlab;
	    }
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror (YY_("syntax error"));
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
        {
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
        }
      else
	{
	  yydestruct ("Error: discarding", yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (0)
     goto yyerrorlab;

yyvsp -= yylen;
  yyssp -= yylen;
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping", yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token. */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK;
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 418 "C:\\Users\\Baher\\source\\repos\\compiler4\\compiler4\\parser.y"

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




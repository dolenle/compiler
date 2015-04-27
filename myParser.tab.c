/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

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

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

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
     CHARLIT = 258,
     STRING = 259,
     IDENT = 260,
     NUMBER = 261,
     INDSEL = 262,
     PLUSPLUS = 263,
     MINUSMINUS = 264,
     SHL = 265,
     SHR = 266,
     LTEQ = 267,
     GTEQ = 268,
     EQEQ = 269,
     NOTEQ = 270,
     LOGAND = 271,
     LOGOR = 272,
     ELLIPSIS = 273,
     TIMESEQ = 274,
     DIVEQ = 275,
     MODEQ = 276,
     PLUSEQ = 277,
     MINUSEQ = 278,
     SHLEQ = 279,
     SHREQ = 280,
     ANDEQ = 281,
     OREQ = 282,
     XOREQ = 283,
     AUTO = 284,
     BREAK = 285,
     CASE = 286,
     CHAR = 287,
     CONST = 288,
     CONTINUE = 289,
     DEFAULT = 290,
     DO = 291,
     DOUBLE = 292,
     ELSE = 293,
     ENUM = 294,
     EXTERN = 295,
     FLOAT = 296,
     FOR = 297,
     GOTO = 298,
     IF = 299,
     INLINE = 300,
     INT = 301,
     LONG = 302,
     REGISTER = 303,
     RESTRICT = 304,
     RETURN = 305,
     SHORT = 306,
     SIGNED = 307,
     SIZEOF = 308,
     STATIC = 309,
     STRUCT = 310,
     SWITCH = 311,
     TYPEDEF = 312,
     TYPEDEF_NAME = 313,
     UNION = 314,
     UNSIGNED = 315,
     VOID = 316,
     VOLATILE = 317,
     WHILE = 318,
     _BOOL = 319,
     _COMPLEX = 320,
     _IMAGINARY = 321,
     NEG = 322
   };
#endif
/* Tokens.  */
#define CHARLIT 258
#define STRING 259
#define IDENT 260
#define NUMBER 261
#define INDSEL 262
#define PLUSPLUS 263
#define MINUSMINUS 264
#define SHL 265
#define SHR 266
#define LTEQ 267
#define GTEQ 268
#define EQEQ 269
#define NOTEQ 270
#define LOGAND 271
#define LOGOR 272
#define ELLIPSIS 273
#define TIMESEQ 274
#define DIVEQ 275
#define MODEQ 276
#define PLUSEQ 277
#define MINUSEQ 278
#define SHLEQ 279
#define SHREQ 280
#define ANDEQ 281
#define OREQ 282
#define XOREQ 283
#define AUTO 284
#define BREAK 285
#define CASE 286
#define CHAR 287
#define CONST 288
#define CONTINUE 289
#define DEFAULT 290
#define DO 291
#define DOUBLE 292
#define ELSE 293
#define ENUM 294
#define EXTERN 295
#define FLOAT 296
#define FOR 297
#define GOTO 298
#define IF 299
#define INLINE 300
#define INT 301
#define LONG 302
#define REGISTER 303
#define RESTRICT 304
#define RETURN 305
#define SHORT 306
#define SIGNED 307
#define SIZEOF 308
#define STATIC 309
#define STRUCT 310
#define SWITCH 311
#define TYPEDEF 312
#define TYPEDEF_NAME 313
#define UNION 314
#define UNSIGNED 315
#define VOID 316
#define VOLATILE 317
#define WHILE 318
#define _BOOL 319
#define _COMPLEX 320
#define _IMAGINARY 321
#define NEG 322




/* Copy the first part of user declarations.  */
#line 3 "myParser.y"


#include "syms.h"
#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

extern int yylex();
extern int line;
char filename[4096];

#define YYDEBUG 1
int yydebug = 0;
void yyerror(const char* s);

symbolTable* currentTable;

char currentSym[128]; //probably not the proper way to do this


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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 24 "myParser.y"
{
	char charBuff;
	char* stringBuff;
	void* noval;
	
	node* astNode;
	
	struct num {
		long long intBuff;
		long double realBuff;
		enum numtype {
			INT_T,
			LONG_T,
			LONGLONG_T,
			FLOAT_T,
			DOUBLE_T,
			LONGDOUBLE_T
		} typeFlag;
		enum signtype {
			SIGNED_T,
			UNSIGNED_T
		} signFlag;
	} num;
}
/* Line 193 of yacc.c.  */
#line 276 "myParser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 289 "myParser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
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
      while (YYID (0))
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
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  61
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1494

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  93
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  212
/* YYNRULES -- Number of states.  */
#define YYNSTATES  350

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   322

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    83,     2,     2,     2,    84,    80,     2,
      74,    75,    70,    68,    79,    81,    78,    71,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    89,    90,
      85,    69,    86,    88,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    76,     2,    77,    73,    67,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    91,    87,    92,    82,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    72
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    13,    15,    20,    24,
      29,    33,    37,    40,    43,    45,    49,    51,    54,    57,
      60,    63,    68,    70,    72,    74,    76,    78,    80,    82,
      87,    89,    93,    97,   101,   103,   107,   111,   113,   117,
     121,   123,   127,   131,   135,   139,   141,   145,   149,   151,
     155,   157,   161,   163,   167,   169,   173,   175,   179,   181,
     187,   189,   193,   195,   197,   199,   201,   203,   205,   207,
     209,   211,   213,   215,   217,   221,   223,   226,   230,   232,
     235,   237,   240,   242,   245,   247,   251,   253,   257,   259,
     261,   263,   265,   267,   269,   271,   273,   275,   277,   279,
     281,   283,   285,   287,   289,   291,   297,   302,   305,   307,
     309,   311,   314,   318,   321,   323,   326,   328,   330,   334,
     336,   339,   343,   348,   354,   357,   359,   363,   365,   369,
     371,   373,   376,   378,   380,   384,   389,   393,   398,   403,
     407,   409,   412,   415,   419,   421,   424,   426,   430,   432,
     436,   439,   442,   444,   446,   450,   452,   455,   457,   459,
     462,   466,   469,   473,   477,   482,   485,   489,   493,   498,
     500,   504,   509,   511,   515,   517,   519,   521,   523,   525,
     527,   531,   536,   540,   543,   547,   551,   556,   558,   561,
     563,   566,   568,   571,   577,   585,   591,   597,   605,   612,
     620,   624,   627,   630,   633,   637,   639,   642,   644,   646,
     651,   655,   659
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     154,     0,    -1,     5,    -1,     6,    -1,     4,    -1,    74,
     113,    75,    -1,    94,    -1,    95,    76,   113,    77,    -1,
      95,    74,    75,    -1,    95,    74,    96,    75,    -1,    95,
      78,     5,    -1,    95,     7,     5,    -1,    95,     8,    -1,
      95,     9,    -1,   111,    -1,    96,    79,   111,    -1,    95,
      -1,    98,    99,    -1,     8,    97,    -1,     9,    97,    -1,
      53,    97,    -1,    53,    74,   140,    75,    -1,    80,    -1,
      70,    -1,    68,    -1,    81,    -1,    82,    -1,    83,    -1,
      97,    -1,    74,   140,    75,    99,    -1,    99,    -1,   100,
      70,    99,    -1,   100,    71,    99,    -1,   100,    84,    99,
      -1,   100,    -1,   101,    68,   100,    -1,   101,    81,   100,
      -1,   101,    -1,   102,    10,   101,    -1,   102,    11,   101,
      -1,   102,    -1,   103,    85,   102,    -1,   103,    86,   102,
      -1,   103,    12,   102,    -1,   103,    13,   102,    -1,   103,
      -1,   104,    14,   103,    -1,   104,    15,   103,    -1,   104,
      -1,   105,    80,   104,    -1,   105,    -1,   106,    73,   105,
      -1,   106,    -1,   107,    87,   106,    -1,   107,    -1,   108,
      16,   107,    -1,   108,    -1,   109,    17,   108,    -1,   109,
      -1,   109,    88,   113,    89,   110,    -1,   110,    -1,    97,
     112,   111,    -1,    69,    -1,    22,    -1,    23,    -1,    19,
      -1,    20,    -1,    21,    -1,    24,    -1,    25,    -1,    26,
      -1,    27,    -1,    28,    -1,   111,    -1,   113,    79,   111,
      -1,   110,    -1,   116,    90,    -1,   116,   117,    90,    -1,
     119,    -1,   119,   116,    -1,   120,    -1,   120,   116,    -1,
     131,    -1,   131,   116,    -1,   118,    -1,   117,    79,   118,
      -1,   132,    -1,   132,    69,   143,    -1,    57,    -1,    40,
      -1,    54,    -1,    29,    -1,    48,    -1,    61,    -1,    32,
      -1,    51,    -1,    46,    -1,    47,    -1,    41,    -1,    37,
      -1,    52,    -1,    60,    -1,   121,    -1,   128,    -1,    58,
      -1,   122,     5,    91,   123,    92,    -1,   122,    91,   123,
      92,    -1,   122,     5,    -1,    55,    -1,    59,    -1,   124,
      -1,   123,   124,    -1,   125,   126,    90,    -1,   120,   125,
      -1,   120,    -1,   131,   125,    -1,   131,    -1,   127,    -1,
     126,    79,   127,    -1,   132,    -1,    89,   114,    -1,   132,
      89,   114,    -1,    39,    91,   129,    92,    -1,    39,     5,
      91,   129,    92,    -1,    39,     5,    -1,   130,    -1,   129,
      79,   130,    -1,     5,    -1,     5,    69,   114,    -1,    33,
      -1,    62,    -1,   134,   133,    -1,   133,    -1,     5,    -1,
      74,   132,    75,    -1,   133,    76,   114,    77,    -1,   133,
      76,    77,    -1,   133,    74,   136,    75,    -1,   133,    74,
     139,    75,    -1,   133,    74,    75,    -1,    70,    -1,    70,
     135,    -1,    70,   134,    -1,    70,   135,   134,    -1,   131,
      -1,   135,   131,    -1,   137,    -1,   137,    79,    18,    -1,
     138,    -1,   137,    79,   138,    -1,   116,   132,    -1,   116,
     141,    -1,   116,    -1,     5,    -1,   139,    79,     5,    -1,
     125,    -1,   125,   141,    -1,   134,    -1,   142,    -1,   134,
     142,    -1,    74,   141,    75,    -1,    76,    77,    -1,    76,
     114,    77,    -1,   142,    76,    77,    -1,   142,    76,   114,
      77,    -1,    74,    75,    -1,    74,   136,    75,    -1,   142,
      74,    75,    -1,   142,    74,   136,    75,    -1,   111,    -1,
      91,   144,    92,    -1,    91,   144,    79,    92,    -1,   143,
      -1,   144,    79,   143,    -1,   146,    -1,   147,    -1,   150,
      -1,   151,    -1,   152,    -1,   153,    -1,     5,    89,   145,
      -1,    31,   114,    89,   145,    -1,    35,    89,   145,    -1,
      91,    92,    -1,    91,   149,    92,    -1,    91,   148,    92,
      -1,    91,   148,   149,    92,    -1,   115,    -1,   148,   115,
      -1,   145,    -1,   149,   145,    -1,    90,    -1,   113,    90,
      -1,    44,    74,   113,    75,   145,    -1,    44,    74,   113,
      75,   145,    38,   145,    -1,    56,    74,   113,    75,   145,
      -1,    63,    74,   113,    75,   145,    -1,    36,   145,    63,
      74,   113,    75,    90,    -1,    42,    74,   150,   150,    75,
     145,    -1,    42,    74,   150,   150,   113,    75,   145,    -1,
      43,     5,    90,    -1,    34,    90,    -1,    30,    90,    -1,
      50,    90,    -1,    50,   113,    90,    -1,   155,    -1,   154,
     155,    -1,   156,    -1,   115,    -1,   116,   132,   148,   147,
      -1,   116,   132,   147,    -1,   132,   148,   147,    -1,   132,
     147,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    73,    73,    82,    91,    92,    96,    97,    98,    99,
     100,   101,   102,   103,   107,   108,   112,   113,   114,   115,
     116,   117,   121,   122,   123,   124,   125,   126,   130,   131,
     135,   136,   137,   138,   142,   143,   144,   148,   149,   150,
     154,   155,   156,   157,   158,   162,   163,   164,   168,   169,
     173,   174,   178,   179,   183,   184,   188,   189,   193,   194,
     198,   199,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   217,   218,   222,   226,   227,   231,   232,
     233,   234,   235,   236,   240,   241,   245,   246,   250,   251,
     252,   253,   254,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   273,   274,   275,   279,   280,
     284,   285,   289,   293,   294,   295,   296,   300,   301,   305,
     306,   307,   311,   312,   313,   317,   318,   322,   323,   327,
     328,   332,   333,   337,   344,   345,   346,   347,   348,   349,
     353,   354,   355,   356,   360,   361,   366,   367,   371,   372,
     376,   377,   378,   382,   383,   387,   388,   392,   393,   394,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   410,
     411,   412,   416,   417,   421,   422,   423,   424,   425,   426,
     430,   431,   432,   436,   437,   438,   439,   465,   466,   470,
     471,   475,   476,   480,   481,   482,   486,   487,   488,   489,
     493,   494,   495,   496,   497,   501,   502,   506,   507,   511,
     512,   513,   514
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CHARLIT", "STRING", "IDENT", "NUMBER",
  "INDSEL", "PLUSPLUS", "MINUSMINUS", "SHL", "SHR", "LTEQ", "GTEQ", "EQEQ",
  "NOTEQ", "LOGAND", "LOGOR", "ELLIPSIS", "TIMESEQ", "DIVEQ", "MODEQ",
  "PLUSEQ", "MINUSEQ", "SHLEQ", "SHREQ", "ANDEQ", "OREQ", "XOREQ", "AUTO",
  "BREAK", "CASE", "CHAR", "CONST", "CONTINUE", "DEFAULT", "DO", "DOUBLE",
  "ELSE", "ENUM", "EXTERN", "FLOAT", "FOR", "GOTO", "IF", "INLINE", "INT",
  "LONG", "REGISTER", "RESTRICT", "RETURN", "SHORT", "SIGNED", "SIZEOF",
  "STATIC", "STRUCT", "SWITCH", "TYPEDEF", "TYPEDEF_NAME", "UNION",
  "UNSIGNED", "VOID", "VOLATILE", "WHILE", "_BOOL", "_COMPLEX",
  "_IMAGINARY", "'_'", "'+'", "'='", "'*'", "'/'", "NEG", "'^'", "'('",
  "')'", "'['", "']'", "'.'", "','", "'&'", "'-'", "'~'", "'!'", "'%'",
  "'<'", "'>'", "'|'", "'?'", "':'", "';'", "'{'", "'}'", "$accept",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "statement", "labeled_statement",
  "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,    95,    43,    61,
      42,    47,   322,    94,    40,    41,    91,    93,    46,    44,
      38,    45,   126,    33,    37,    60,    62,   124,    63,    58,
      59,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    93,    94,    94,    94,    94,    95,    95,    95,    95,
      95,    95,    95,    95,    96,    96,    97,    97,    97,    97,
      97,    97,    98,    98,    98,    98,    98,    98,    99,    99,
     100,   100,   100,   100,   101,   101,   101,   102,   102,   102,
     103,   103,   103,   103,   103,   104,   104,   104,   105,   105,
     106,   106,   107,   107,   108,   108,   109,   109,   110,   110,
     111,   111,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   113,   113,   114,   115,   115,   116,   116,
     116,   116,   116,   116,   117,   117,   118,   118,   119,   119,
     119,   119,   119,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   121,   121,   121,   122,   122,
     123,   123,   124,   125,   125,   125,   125,   126,   126,   127,
     127,   127,   128,   128,   128,   129,   129,   130,   130,   131,
     131,   132,   132,   133,   133,   133,   133,   133,   133,   133,
     134,   134,   134,   134,   135,   135,   136,   136,   137,   137,
     138,   138,   138,   139,   139,   140,   140,   141,   141,   141,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   143,
     143,   143,   144,   144,   145,   145,   145,   145,   145,   145,
     146,   146,   146,   147,   147,   147,   147,   148,   148,   149,
     149,   150,   150,   151,   151,   151,   152,   152,   152,   152,
     153,   153,   153,   153,   153,   154,   154,   155,   155,   156,
     156,   156,   156
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     3,     1,     2,     2,     2,
       2,     4,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     5,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     2,     3,     1,     2,
       1,     2,     1,     2,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     4,     2,     1,     1,
       1,     2,     3,     2,     1,     2,     1,     1,     3,     1,
       2,     3,     4,     5,     2,     1,     3,     1,     3,     1,
       1,     2,     1,     1,     3,     4,     3,     4,     4,     3,
       1,     2,     2,     3,     1,     2,     1,     3,     1,     3,
       2,     2,     1,     1,     3,     1,     2,     1,     1,     2,
       3,     2,     3,     3,     4,     2,     3,     3,     4,     1,
       3,     4,     1,     3,     1,     1,     1,     1,     1,     1,
       3,     4,     3,     2,     3,     3,     4,     1,     2,     1,
       2,     1,     2,     5,     7,     5,     5,     7,     6,     7,
       3,     2,     2,     2,     3,     1,     2,     1,     1,     4,
       3,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   133,    91,    94,   129,    99,     0,    89,    98,    96,
      97,    92,    95,   100,    90,   108,    88,   104,   109,   101,
      93,   130,   140,     0,   208,     0,    78,    80,   102,     0,
     103,    82,     0,   132,     0,     0,   205,   207,   124,     0,
     144,   142,   141,     0,    76,     0,    84,    86,    79,    81,
     107,     0,    83,     0,   187,     0,   212,     0,     0,     0,
     131,     1,   206,     0,   127,     0,   125,   145,   143,   134,
       0,    77,     0,   210,     0,     0,   114,     0,   110,     0,
     116,     4,     2,     3,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    24,    23,
       0,    22,    25,    26,    27,   191,   183,     6,    16,    28,
       0,    30,    34,    37,    40,    45,    48,    50,    52,    54,
      56,    58,    60,    73,     0,   189,   174,   175,     0,     0,
     176,   177,   178,   179,    86,   188,   211,   153,   139,   152,
       0,   146,   148,     0,     2,   136,    28,    75,     0,     0,
       0,     0,   122,    85,     0,   169,    87,   209,     0,   113,
     106,   111,     0,     0,   117,   119,   115,     0,     0,    18,
      19,   202,     0,   201,     0,     0,     0,     0,     0,   203,
       0,     0,    20,     0,     0,     0,   155,     0,     0,    12,
      13,     0,     0,     0,    65,    66,    67,    63,    64,    68,
      69,    70,    71,    72,    62,     0,    17,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   192,   185,     0,
     184,   190,     0,     0,   150,   157,   151,   158,   137,     0,
     138,     0,   135,   123,   128,   126,   172,     0,   105,   120,
       0,   112,     0,   180,     0,   182,     0,     0,   200,     0,
     204,     0,     0,     0,     5,     0,   157,   156,     0,    11,
       8,     0,    14,     0,    10,    61,    31,    32,    33,    35,
      36,    38,    39,    43,    44,    41,    42,    46,    47,    49,
      51,    53,    55,    57,     0,    74,   186,   165,     0,     0,
     161,     0,   159,     0,     0,   147,   149,   154,     0,   170,
     118,   121,   181,     0,     0,     0,    21,     0,     0,    29,
       9,     0,     7,     0,   166,   160,   162,   167,     0,   163,
       0,   171,   173,     0,     0,     0,   193,   195,   196,    15,
      59,   168,   164,     0,   198,     0,     0,   197,   199,   194
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   107,   108,   271,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   205,
     124,   148,    54,    55,    45,    46,    26,    27,    28,    29,
      77,    78,    79,   163,   164,    30,    65,    66,    31,    32,
      33,    34,    42,   298,   141,   142,   143,   187,   299,   237,
     156,   247,   125,   126,   127,    57,   129,   130,   131,   132,
     133,    35,    36,    37
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -215
static const yytype_int16 yypact[] =
{
    1106,  -215,  -215,  -215,  -215,  -215,     6,  -215,  -215,  -215,
    -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,
    -215,  -215,    16,   132,  -215,     1,  1401,  1401,  -215,     8,
    -215,  1401,  1177,    51,     9,   990,  -215,  -215,   -35,    33,
    -215,  -215,    16,    28,  -215,   -45,  -215,  1142,  -215,  -215,
     -18,  1432,  -215,   280,  -215,     1,  -215,  1177,  1069,   768,
      51,  -215,  -215,    33,   -23,   -26,  -215,  -215,  -215,  -215,
     132,  -215,   140,  -215,  1177,  1432,  1432,  1211,  -215,    -2,
    1432,  -215,    39,  -215,   901,   901,     4,   917,   122,   139,
     578,   164,   240,   174,   621,   935,   193,   197,  -215,  -215,
     701,  -215,  -215,  -215,  -215,  -215,  -215,  -215,   179,   660,
     917,  -215,   -27,    -4,   166,    57,   203,   171,   204,   189,
     262,     2,  -215,  -215,   -29,  -215,  -215,  -215,   347,   414,
    -215,  -215,  -215,  -215,   210,  -215,  -215,  -215,  -215,    36,
     205,   202,  -215,    60,  -215,  -215,  -215,  -215,   206,    19,
     917,    33,  -215,  -215,   140,  -215,  -215,  -215,  1246,  -215,
    -215,  -215,   917,   -14,  -215,   201,  -215,   578,   917,  -215,
    -215,  -215,   207,  -215,   578,   228,   645,   208,   917,  -215,
       3,   701,  -215,   917,   917,   136,   115,   217,   288,  -215,
    -215,   784,   917,   289,  -215,  -215,  -215,  -215,  -215,  -215,
    -215,  -215,  -215,  -215,  -215,   917,  -215,   917,   917,   917,
     917,   917,   917,   917,   917,   917,   917,   917,   917,   917,
     917,   917,   917,   917,   917,   917,   917,  -215,  -215,   481,
    -215,  -215,  1029,   800,  -215,     5,  -215,   118,  -215,  1367,
    -215,   290,  -215,  -215,  -215,  -215,  -215,    30,  -215,  -215,
      -2,  -215,   917,  -215,   578,  -215,   223,   645,  -215,   150,
    -215,   224,   151,   162,  -215,  1282,   133,  -215,   917,  -215,
    -215,   165,  -215,   177,  -215,  -215,  -215,  -215,  -215,   -27,
     -27,    -4,    -4,   166,   166,   166,   166,    57,    57,   203,
     171,   204,   189,   262,   -61,  -215,  -215,  -215,   226,   227,
    -215,   229,   118,  1322,   818,  -215,  -215,  -215,   524,  -215,
    -215,  -215,  -215,   917,   885,   578,  -215,   578,   578,  -215,
    -215,   917,  -215,   917,  -215,  -215,  -215,  -215,   232,  -215,
     231,  -215,  -215,   168,   578,   191,   266,  -215,  -215,  -215,
    -215,  -215,  -215,   235,  -215,   578,   578,  -215,  -215,  -215
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -215,  -215,  -215,  -215,   -55,  -215,   -88,   -60,   -30,    58,
      40,    98,   108,   123,   121,   125,  -215,   -54,   -21,  -215,
     -52,   -62,    67,     0,  -215,   276,  -215,   124,  -215,  -215,
     272,   -53,   -64,  -215,   107,  -215,   295,   213,    38,   -16,
     -32,    -5,  -215,   -57,  -215,   120,  -215,   184,  -124,  -214,
    -134,  -215,   -82,  -215,    27,    83,   238,  -153,  -215,  -215,
    -215,  -215,   332,  -215
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      25,   140,    60,     1,   146,   147,     1,    43,   175,    47,
       1,    38,   159,    50,     1,   236,   166,    41,   226,   224,
     246,   302,   206,   257,   161,   172,    48,    49,   323,   169,
     170,    52,   146,   147,    70,    25,   186,    68,    64,   134,
     182,     1,   180,   207,   208,    71,   150,   231,   185,     4,
     226,   155,   302,   151,   134,   146,    63,   209,   139,    56,
      40,   227,   267,   165,   210,   250,   152,    24,    22,   214,
     215,    22,    23,    75,    73,    23,   251,   211,    21,   232,
      67,   233,   226,    23,   136,   253,    22,   162,   244,    80,
     225,    44,   255,   260,   171,   146,   147,    39,   151,    51,
     249,   157,    24,    69,   314,   161,    22,   146,   147,   308,
     232,   243,   233,    80,    80,    80,   185,   186,    80,   276,
     277,   278,   309,   234,   135,    58,   259,    59,   167,   185,
      74,   262,   263,   155,   235,   240,   128,     1,    80,   241,
     273,   135,   216,   217,    81,   144,    83,   231,    84,    85,
     279,   280,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     272,   301,   312,   294,   332,    76,   212,   213,   146,   147,
     319,   266,   281,   282,   275,    22,   188,   189,   190,   265,
     311,   233,   303,    95,   304,   135,    80,   146,   147,    76,
      76,    76,    22,    60,    76,   295,    23,   265,    98,   233,
      99,   264,   173,   146,   100,   226,    43,   218,   219,    80,
     101,   102,   103,   104,    76,   315,   317,   235,   174,   226,
     226,   154,   139,   336,   165,   337,   338,   318,   176,   139,
     320,   226,   330,   343,   321,   177,   328,   226,   178,   146,
     147,   220,   344,   191,   322,   192,   226,   193,   287,   288,
     266,   333,   335,   348,   349,   139,   345,   183,   146,   340,
     226,   184,   283,   284,   285,   286,   222,   221,   223,    72,
     238,   239,    76,   242,    81,    82,    83,   155,    84,    85,
     252,   256,   268,   269,   274,   307,   254,   313,   258,   316,
     339,   324,   325,   139,   346,    76,   326,   341,   342,     2,
      86,    87,     3,     4,    88,    89,    90,     5,   289,     6,
       7,     8,    91,    92,    93,   347,     9,    10,    11,   290,
      94,    12,    13,    95,    14,    15,    96,    16,    17,    18,
      19,    20,    21,    97,   292,   291,   153,   158,    98,   293,
      99,    81,    82,    83,   100,    84,    85,   310,   149,   306,
     101,   102,   103,   104,   245,   261,   229,    62,     0,     0,
     105,    53,   106,     0,     0,     0,     2,    86,    87,     3,
       4,    88,    89,    90,     5,     0,     6,     7,     8,    91,
      92,    93,     0,     9,    10,    11,     0,    94,    12,    13,
      95,    14,    15,    96,    16,    17,    18,    19,    20,    21,
      97,     0,     0,     0,     0,    98,     0,    99,    81,    82,
      83,   100,    84,    85,     0,     0,     0,   101,   102,   103,
     104,     0,     0,     0,     0,     0,     0,   105,    53,   228,
       0,     0,     0,     0,    86,    87,     0,     0,    88,    89,
      90,     0,     0,     0,     0,     0,    91,    92,    93,     0,
       0,     0,     0,     0,    94,     0,     0,    95,     0,     0,
      96,     0,     0,     0,     0,     0,     0,    97,     0,     0,
       0,     0,    98,     0,    99,    81,    82,    83,   100,    84,
      85,     0,     0,     0,   101,   102,   103,   104,     0,     0,
       0,     0,     0,     0,   105,    53,   230,     0,     0,     0,
       0,    86,    87,     0,     0,    88,    89,    90,     0,     0,
       0,     0,     0,    91,    92,    93,     0,     0,    81,   144,
      83,    94,    84,    85,    95,     0,     0,    96,     0,     0,
       0,     0,     0,     0,    97,     0,     0,     0,     0,    98,
       0,    99,     0,     0,     0,   100,     0,     0,     0,     0,
       0,   101,   102,   103,   104,     0,     0,     0,     0,     0,
       0,   105,    53,   296,     0,     0,     0,    95,     0,     0,
       0,     0,    81,    82,    83,     0,    84,    85,     0,     0,
       0,     0,    98,     0,    99,     0,     0,     0,   100,     0,
       0,     0,     0,     0,   101,   102,   103,   104,    86,    87,
       0,     0,    88,    89,    90,   154,   331,     0,     0,     0,
      91,    92,    93,     0,     0,    81,   144,    83,    94,    84,
      85,    95,     0,     0,    96,     0,     0,     0,     0,     0,
       0,    97,     0,     0,     0,     0,    98,     0,    99,    81,
     144,    83,   100,    84,    85,     0,     0,     0,   101,   102,
     103,   104,     0,     0,     0,     0,     0,     0,   105,    53,
       0,     0,     0,     0,    95,     0,     0,     0,     0,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,    98,
       0,    99,     0,     0,     0,   100,     0,     0,    95,     0,
       0,   101,   102,   103,   104,    81,   144,    83,     0,    84,
      85,   179,     0,    98,     0,    99,     0,     0,     0,   100,
       0,     0,     0,     0,     0,   101,   102,   103,   104,   204,
       0,     0,     0,     3,     4,   105,     0,     0,     5,     0,
       6,     0,     8,     0,     0,     0,     0,     9,    10,     0,
       0,     0,    12,    13,    95,     0,    15,     0,     0,    17,
      18,    19,    20,    21,     0,     0,     0,     0,     0,    98,
       0,    99,    81,   144,    83,   100,    84,    85,     0,     0,
       0,   101,   102,   103,   104,     0,     0,     0,    81,   144,
      83,     0,    84,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    81,   144,    83,     0,    84,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    95,    81,   144,    83,     0,    84,    85,     0,     0,
       0,     0,     0,     0,     0,     0,    98,    95,    99,     0,
       0,     0,   100,     0,     0,   145,     0,     0,   101,   102,
     103,   104,    98,    95,    99,     0,     0,     0,   100,   270,
       0,     0,     0,     0,   101,   102,   103,   104,    98,     0,
      99,    95,     0,     0,   100,     0,     0,   300,     0,     0,
     101,   102,   103,   104,     0,     0,    98,     0,    99,    81,
     144,    83,   100,    84,    85,   329,     0,     0,   101,   102,
     103,   104,     0,     0,     0,    81,   144,    83,     0,    84,
      85,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    81,   144,    83,     0,    84,    85,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    95,    81,
     144,    83,     0,    84,    85,     0,     0,     0,     0,     0,
       0,     0,     0,    98,    95,    99,     0,     0,     0,   100,
     334,     0,     0,     0,     0,   101,   102,   103,   104,    98,
      95,    99,     0,     0,     0,   168,     0,     0,     0,     0,
       0,   101,   102,   103,   104,    98,     0,    99,    95,     0,
      61,   100,     0,     0,     0,     1,     0,   101,   102,   103,
     104,     0,     0,    98,     0,    99,     0,     0,     0,   181,
       0,     0,     0,     0,     0,   101,   102,   103,   104,     2,
       0,     0,     3,     4,     0,     0,     0,     5,     0,     6,
       7,     8,     0,     0,     1,     0,     9,    10,    11,     0,
       0,    12,    13,     0,    14,    15,     0,    16,    17,    18,
      19,    20,    21,     0,     0,     0,     0,     0,     2,     0,
      22,     3,     4,     0,    23,     0,     5,     0,     6,     7,
       8,     0,     0,     0,   137,     9,    10,    11,     0,     0,
      12,    13,     0,    14,    15,     0,    16,    17,    18,    19,
      20,    21,     0,     0,     0,     0,     0,     0,     2,    22,
       0,     3,     4,   232,   297,   233,     5,     0,     6,     7,
       8,     1,     0,     0,     0,     9,    10,    11,     0,     0,
      12,    13,     0,    14,    15,     0,    16,    17,    18,    19,
      20,    21,     0,     0,     0,     2,     0,     0,     3,     4,
       0,     0,     0,     5,   138,     6,     7,     8,     0,     0,
       0,     0,     9,    10,    11,     0,     0,    12,    13,     0,
      14,    15,     0,    16,    17,    18,    19,    20,    21,     0,
       0,     2,     0,     0,     3,     4,    22,     0,     0,     5,
      23,     6,     7,     8,     0,     0,     0,     0,     9,    10,
      11,     0,     0,    12,    13,     0,    14,    15,     0,    16,
      17,    18,    19,    20,    21,     0,     2,     0,     0,     3,
       4,    72,     0,     0,     5,     0,     6,     7,     8,     0,
       0,     0,     0,     9,    10,    11,     0,     0,    12,    13,
       0,    14,    15,    53,    16,    17,    18,    19,    20,    21,
       0,     0,     0,     3,     4,     0,     0,     0,     5,     0,
       6,     0,     8,     0,     0,     0,     0,     9,    10,     0,
       0,     0,    12,    13,     0,     0,    15,     0,    53,    17,
      18,    19,    20,    21,     0,     0,     0,     0,     3,     4,
       0,     0,     0,     5,     0,     6,     0,     8,     0,     0,
       0,     0,     9,    10,     0,     0,     0,    12,    13,     0,
       0,    15,     0,   160,    17,    18,    19,    20,    21,     0,
       0,     2,     0,     0,     3,     4,     0,     0,     0,     5,
       0,     6,     7,     8,     0,     0,     0,     0,     9,    10,
      11,     0,     0,    12,    13,     0,    14,    15,   248,    16,
      17,    18,    19,    20,    21,     0,     0,     0,     0,     0,
       0,     2,    22,     0,     3,     4,   265,   297,   233,     5,
       0,     6,     7,     8,     0,     0,     0,     0,     9,    10,
      11,     0,     0,    12,    13,     0,    14,    15,     0,    16,
      17,    18,    19,    20,    21,   305,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     2,   327,     0,     3,
       4,     0,     0,     0,     5,     0,     6,     7,     8,     0,
       0,     0,     0,     9,    10,    11,     0,     0,    12,    13,
       0,    14,    15,     0,    16,    17,    18,    19,    20,    21,
       2,     0,     0,     3,     4,     0,     0,     0,     5,     0,
       6,     7,     8,     0,     0,     0,     0,     9,    10,    11,
       0,     0,    12,    13,     0,    14,    15,     0,    16,    17,
      18,    19,    20,    21,     3,     4,     0,     0,     0,     5,
       0,     6,     0,     8,     0,     0,     0,     0,     9,    10,
       0,     0,     0,    12,    13,     0,     0,    15,     0,     0,
      17,    18,    19,    20,    21
};

static const yytype_int16 yycheck[] =
{
       0,    58,    34,     5,    59,    59,     5,    23,    90,    25,
       5,     5,    76,     5,     5,   139,    80,    22,    79,    17,
     154,   235,   110,   176,    77,    87,    26,    27,    89,    84,
      85,    31,    87,    87,    79,    35,   100,    42,     5,    55,
      95,     5,    94,    70,    71,    90,    69,   129,   100,    33,
      79,    72,   266,    79,    70,   110,    91,    84,    58,    32,
      22,    90,   186,    79,    68,    79,    92,     0,    70,    12,
      13,    70,    74,    91,    47,    74,    90,    81,    62,    74,
      42,    76,    79,    74,    57,   167,    70,    89,   150,    51,
      88,    90,   174,    90,    90,   150,   150,    91,    79,    91,
     162,    74,    35,    75,   257,   158,    70,   162,   162,    79,
      74,    92,    76,    75,    76,    77,   168,   181,    80,   207,
     208,   209,    92,   139,    57,    74,   178,    76,    89,   181,
      47,   183,   184,   154,   139,    75,    53,     5,   100,    79,
     192,    74,    85,    86,     4,     5,     6,   229,     8,     9,
     210,   211,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     191,   233,   254,   225,   308,    51,    10,    11,   233,   233,
     268,   186,   212,   213,   205,    70,     7,     8,     9,    74,
     252,    76,    74,    53,    76,   128,   158,   252,   252,    75,
      76,    77,    70,   235,    80,   226,    74,    74,    68,    76,
      70,    75,    90,   268,    74,    79,   232,    14,    15,   181,
      80,    81,    82,    83,   100,    75,    75,   232,    89,    79,
      79,    91,   232,   315,   250,   317,   318,    75,    74,   239,
      75,    79,   304,    75,    79,     5,   303,    79,    74,   304,
     304,    80,   334,    74,    77,    76,    79,    78,   218,   219,
     265,   313,   314,   345,   346,   265,    75,    74,   323,   323,
      79,    74,   214,   215,   216,   217,    87,    73,    16,    69,
      75,    79,   158,    77,     4,     5,     6,   308,     8,     9,
      89,    63,    75,     5,     5,     5,    89,    74,    90,    75,
     321,    75,    75,   303,    38,   181,    77,    75,    77,    29,
      30,    31,    32,    33,    34,    35,    36,    37,   220,    39,
      40,    41,    42,    43,    44,    90,    46,    47,    48,   221,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,   223,   222,    70,    75,    68,   224,
      70,     4,     5,     6,    74,     8,     9,   250,    63,   239,
      80,    81,    82,    83,   151,   181,   128,    35,    -1,    -1,
      90,    91,    92,    -1,    -1,    -1,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    39,    40,    41,    42,
      43,    44,    -1,    46,    47,    48,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    -1,    68,    -1,    70,     4,     5,
       6,    74,     8,     9,    -1,    -1,    -1,    80,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    92,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    -1,    53,    -1,    -1,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    68,    -1,    70,     4,     5,     6,    74,     8,
       9,    -1,    -1,    -1,    80,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    91,    92,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    42,    43,    44,    -1,    -1,     4,     5,
       6,    50,     8,     9,    53,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    68,
      -1,    70,    -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,
      -1,    80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    91,    92,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    -1,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      -1,    -1,    68,    -1,    70,    -1,    -1,    -1,    74,    -1,
      -1,    -1,    -1,    -1,    80,    81,    82,    83,    30,    31,
      -1,    -1,    34,    35,    36,    91,    92,    -1,    -1,    -1,
      42,    43,    44,    -1,    -1,     4,     5,     6,    50,     8,
       9,    53,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    68,    -1,    70,     4,
       5,     6,    74,     8,     9,    -1,    -1,    -1,    80,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    68,
      -1,    70,    -1,    -1,    -1,    74,    -1,    -1,    53,    -1,
      -1,    80,    81,    82,    83,     4,     5,     6,    -1,     8,
       9,    90,    -1,    68,    -1,    70,    -1,    -1,    -1,    74,
      -1,    -1,    -1,    -1,    -1,    80,    81,    82,    83,    69,
      -1,    -1,    -1,    32,    33,    90,    -1,    -1,    37,    -1,
      39,    -1,    41,    -1,    -1,    -1,    -1,    46,    47,    -1,
      -1,    -1,    51,    52,    53,    -1,    55,    -1,    -1,    58,
      59,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    70,     4,     5,     6,    74,     8,     9,    -1,    -1,
      -1,    80,    81,    82,    83,    -1,    -1,    -1,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    53,    70,    -1,
      -1,    -1,    74,    -1,    -1,    77,    -1,    -1,    80,    81,
      82,    83,    68,    53,    70,    -1,    -1,    -1,    74,    75,
      -1,    -1,    -1,    -1,    80,    81,    82,    83,    68,    -1,
      70,    53,    -1,    -1,    74,    -1,    -1,    77,    -1,    -1,
      80,    81,    82,    83,    -1,    -1,    68,    -1,    70,     4,
       5,     6,    74,     8,     9,    77,    -1,    -1,    80,    81,
      82,    83,    -1,    -1,    -1,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    53,    70,    -1,    -1,    -1,    74,
      75,    -1,    -1,    -1,    -1,    80,    81,    82,    83,    68,
      53,    70,    -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,
      -1,    80,    81,    82,    83,    68,    -1,    70,    53,    -1,
       0,    74,    -1,    -1,    -1,     5,    -1,    80,    81,    82,
      83,    -1,    -1,    68,    -1,    70,    -1,    -1,    -1,    74,
      -1,    -1,    -1,    -1,    -1,    80,    81,    82,    83,    29,
      -1,    -1,    32,    33,    -1,    -1,    -1,    37,    -1,    39,
      40,    41,    -1,    -1,     5,    -1,    46,    47,    48,    -1,
      -1,    51,    52,    -1,    54,    55,    -1,    57,    58,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    -1,    29,    -1,
      70,    32,    33,    -1,    74,    -1,    37,    -1,    39,    40,
      41,    -1,    -1,    -1,     5,    46,    47,    48,    -1,    -1,
      51,    52,    -1,    54,    55,    -1,    57,    58,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    29,    70,
      -1,    32,    33,    74,    75,    76,    37,    -1,    39,    40,
      41,     5,    -1,    -1,    -1,    46,    47,    48,    -1,    -1,
      51,    52,    -1,    54,    55,    -1,    57,    58,    59,    60,
      61,    62,    -1,    -1,    -1,    29,    -1,    -1,    32,    33,
      -1,    -1,    -1,    37,    75,    39,    40,    41,    -1,    -1,
      -1,    -1,    46,    47,    48,    -1,    -1,    51,    52,    -1,
      54,    55,    -1,    57,    58,    59,    60,    61,    62,    -1,
      -1,    29,    -1,    -1,    32,    33,    70,    -1,    -1,    37,
      74,    39,    40,    41,    -1,    -1,    -1,    -1,    46,    47,
      48,    -1,    -1,    51,    52,    -1,    54,    55,    -1,    57,
      58,    59,    60,    61,    62,    -1,    29,    -1,    -1,    32,
      33,    69,    -1,    -1,    37,    -1,    39,    40,    41,    -1,
      -1,    -1,    -1,    46,    47,    48,    -1,    -1,    51,    52,
      -1,    54,    55,    91,    57,    58,    59,    60,    61,    62,
      -1,    -1,    -1,    32,    33,    -1,    -1,    -1,    37,    -1,
      39,    -1,    41,    -1,    -1,    -1,    -1,    46,    47,    -1,
      -1,    -1,    51,    52,    -1,    -1,    55,    -1,    91,    58,
      59,    60,    61,    62,    -1,    -1,    -1,    -1,    32,    33,
      -1,    -1,    -1,    37,    -1,    39,    -1,    41,    -1,    -1,
      -1,    -1,    46,    47,    -1,    -1,    -1,    51,    52,    -1,
      -1,    55,    -1,    92,    58,    59,    60,    61,    62,    -1,
      -1,    29,    -1,    -1,    32,    33,    -1,    -1,    -1,    37,
      -1,    39,    40,    41,    -1,    -1,    -1,    -1,    46,    47,
      48,    -1,    -1,    51,    52,    -1,    54,    55,    92,    57,
      58,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    70,    -1,    32,    33,    74,    75,    76,    37,
      -1,    39,    40,    41,    -1,    -1,    -1,    -1,    46,    47,
      48,    -1,    -1,    51,    52,    -1,    54,    55,    -1,    57,
      58,    59,    60,    61,    62,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    75,    -1,    32,
      33,    -1,    -1,    -1,    37,    -1,    39,    40,    41,    -1,
      -1,    -1,    -1,    46,    47,    48,    -1,    -1,    51,    52,
      -1,    54,    55,    -1,    57,    58,    59,    60,    61,    62,
      29,    -1,    -1,    32,    33,    -1,    -1,    -1,    37,    -1,
      39,    40,    41,    -1,    -1,    -1,    -1,    46,    47,    48,
      -1,    -1,    51,    52,    -1,    54,    55,    -1,    57,    58,
      59,    60,    61,    62,    32,    33,    -1,    -1,    -1,    37,
      -1,    39,    -1,    41,    -1,    -1,    -1,    -1,    46,    47,
      -1,    -1,    -1,    51,    52,    -1,    -1,    55,    -1,    -1,
      58,    59,    60,    61,    62
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    29,    32,    33,    37,    39,    40,    41,    46,
      47,    48,    51,    52,    54,    55,    57,    58,    59,    60,
      61,    62,    70,    74,   115,   116,   119,   120,   121,   122,
     128,   131,   132,   133,   134,   154,   155,   156,     5,    91,
     131,   134,   135,   132,    90,   117,   118,   132,   116,   116,
       5,    91,   116,    91,   115,   116,   147,   148,    74,    76,
     133,     0,   155,    91,     5,   129,   130,   131,   134,    75,
      79,    90,    69,   147,   148,    91,   120,   123,   124,   125,
     131,     4,     5,     6,     8,     9,    30,    31,    34,    35,
      36,    42,    43,    44,    50,    53,    56,    63,    68,    70,
      74,    80,    81,    82,    83,    90,    92,    94,    95,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   113,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   132,   115,   147,     5,    75,   116,
     136,   137,   138,   139,     5,    77,    97,   110,   114,   129,
      69,    79,    92,   118,    91,   111,   143,   147,   123,   125,
      92,   124,    89,   126,   127,   132,   125,    89,    74,    97,
      97,    90,   114,    90,    89,   145,    74,     5,    74,    90,
     113,    74,    97,    74,    74,   113,   125,   140,     7,     8,
       9,    74,    76,    78,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    69,   112,    99,    70,    71,    84,
      68,    81,    10,    11,    12,    13,    85,    86,    14,    15,
      80,    73,    87,    16,    17,    88,    79,    90,    92,   149,
      92,   145,    74,    76,   132,   134,   141,   142,    75,    79,
      75,    79,    77,    92,   114,   130,   143,   144,    92,   114,
      79,    90,    89,   145,    89,   145,    63,   150,    90,   113,
      90,   140,   113,   113,    75,    74,   134,   141,    75,     5,
      75,    96,   111,   113,     5,   111,    99,    99,    99,   100,
     100,   101,   101,   102,   102,   102,   102,   103,   103,   104,
     105,   106,   107,   108,   113,   111,    92,    75,   136,   141,
      77,   114,   142,    74,    76,    18,   138,     5,    79,    92,
     127,   114,   145,    74,   150,    75,    75,    75,    75,    99,
      75,    79,    77,    89,    75,    75,    77,    75,   136,    77,
     114,    92,   143,   113,    75,   113,   145,   145,   145,   111,
     110,    75,    77,    75,   145,    75,    38,    90,   145,   145
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
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
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
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
      YYSIZE_T yyn = 0;
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
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
      int yychecklim = YYLAST - yyn + 1;
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
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
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
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  YYUSE (yyvaluep);

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
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

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
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

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
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


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
	yytype_int16 *yyss1 = yyss;
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

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
#line 73 "myParser.y"
    {
				if(containsSymbol(currentTable, (yyvsp[(1) - (1)].stringBuff))) {
					(yyval.num.intBuff) = getSymbolValue(currentTable, (yyvsp[(1) - (1)].stringBuff));
					strcpy(currentSym, (yyvsp[(1) - (1)].stringBuff));
					printf("exprval: %lli\n",(yyval.num.intBuff));
				} else {
					yyerror("Symbol not found\n");
				}
			;}
    break;

  case 3:
#line 82 "myParser.y"
    {
					if (yylval.num.typeFlag == INT_T || yylval.num.typeFlag == LONG_T || yylval.num.typeFlag == LONGLONG_T)
                        (yyval.num.intBuff) = yylval.num.intBuff;
                else {
                        (yyval.num.intBuff) = (long long)yylval.num.realBuff;
                        fprintf(stderr,"Truncating real number %Lg to integer %lld\n",yylval.num.realBuff,(yyval.num.intBuff));
                        printf("exprval=%lld\n",(yyval.num.intBuff));
                }
				;}
    break;

  case 4:
#line 91 "myParser.y"
    {yyerror("Strings not supported.");;}
    break;

  case 5:
#line 92 "myParser.y"
    {;}
    break;

  case 16:
#line 112 "myParser.y"
    {;}
    break;

  case 17:
#line 113 "myParser.y"
    {;}
    break;

  case 18:
#line 114 "myParser.y"
    {;}
    break;

  case 19:
#line 115 "myParser.y"
    {;}
    break;

  case 20:
#line 116 "myParser.y"
    {;}
    break;

  case 21:
#line 117 "myParser.y"
    {;}
    break;

  case 28:
#line 130 "myParser.y"
    {;}
    break;

  case 29:
#line 131 "myParser.y"
    {;}
    break;

  case 34:
#line 142 "myParser.y"
    {;}
    break;

  case 54:
#line 183 "myParser.y"
    {;}
    break;

  case 60:
#line 198 "myParser.y"
    {;}
    break;

  case 133:
#line 337 "myParser.y"
    {
				if(!containsSymbol(currentTable, (yyvsp[(1) - (1)].stringBuff))) {
					installSymbol(currentTable, (yyvsp[(1) - (1)].stringBuff), filename, line, NUM);
				} else {
					yyerror("Redeclaration of variable");
					}
			;}
    break;

  case 153:
#line 382 "myParser.y"
    {printf("%s\n", "identifier list");;}
    break;

  case 170:
#line 411 "myParser.y"
    {;}
    break;

  case 171:
#line 412 "myParser.y"
    {;}
    break;

  case 207:
#line 506 "myParser.y"
    {printf("Left function!\n");;}
    break;


/* Line 1267 of yacc.c.  */
#line 2200 "myParser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
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
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
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
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
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
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
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
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 517 "myParser.y"


void yyerror(const char* s) {
	fprintf(stderr, "Error: %s on line %i\n", s, line);
}

int main(int argc, char** argv) {
	printf("[Parser Begin]\n");
	strcpy(filename, "Placeholder.c");
	currentTable = enterScope(GLOBAL_SCOPE, 0, "TestFileName.c", NULL);
	yyparse();
	return 0;
}

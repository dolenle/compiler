/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 3 "myParser.y" /* yacc.c:339  */


#include "syms.h"
#include "ast.h"
#include <stdio.h>
#include <stdlib.h>

#define YYDEBUG 1
int yydebug = 0;
void yyerror(const char* s);

void doScopeThing();

extern int yylex();
extern int line;
char filename[4096];

symbolTable* currentTable;

char currentSym[128]; //probably not the proper way to do this

#line 88 "myParser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "myParser.tab.h".  */
#ifndef YY_YY_MYPARSER_TAB_H_INCLUDED
# define YY_YY_MYPARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 25 "myParser.y" /* yacc.c:355  */

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

#line 221 "myParser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MYPARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 238 "myParser.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  61
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1392

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  93
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  212
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  358

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   322

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    74,    74,    85,    94,    95,    99,   100,   101,   102,
     103,   104,   105,   106,   110,   111,   115,   116,   117,   118,
     119,   120,   124,   125,   126,   127,   128,   129,   133,   134,
     138,   139,   140,   141,   145,   146,   147,   151,   152,   153,
     157,   158,   159,   160,   161,   165,   166,   167,   171,   172,
     176,   177,   181,   182,   186,   187,   191,   192,   196,   197,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   232,   233,   237,   241,   242,   246,   247,   248,
     249,   250,   251,   255,   256,   260,   261,   265,   266,   267,
     268,   269,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   288,   289,   290,   294,   295,   299,
     300,   304,   308,   309,   310,   311,   315,   316,   320,   321,
     322,   326,   327,   328,   332,   333,   337,   338,   342,   343,
     347,   348,   352,   359,   360,   361,   362,   363,   364,   368,
     369,   370,   371,   375,   376,   381,   382,   386,   387,   391,
     392,   393,   397,   398,   402,   403,   407,   408,   409,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   425,   426,
     427,   431,   432,   436,   437,   438,   439,   440,   441,   445,
     446,   447,   464,   465,   469,   472,   472,   478,   479,   483,
     484,   488,   489,   493,   494,   495,   499,   500,   501,   502,
     506,   507,   508,   509,   510,   514,   515,   519,   520,   524,
     525,   526,   527
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
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
  "conditional_expression", "assignment_expression", "expression",
  "constant_expression", "declaration", "declaration_specifiers",
  "init_declarator_list", "init_declarator", "storage_class_specifier",
  "type_specifier", "struct_or_union_specifier", "struct_or_union",
  "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "statement", "labeled_statement", "declaration_list",
  "compound_statement", "$@1", "declaration_or_statement_list",
  "declaration_or_statement", "expression_statement",
  "selection_statement", "iteration_statement", "jump_statement",
  "translation_unit", "external_declaration", "function_definition", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
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

#define YYPACT_NINF -224

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-224)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1004,  -224,  -224,  -224,  -224,  -224,     6,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,   153,    57,  -224,    15,  1299,  1299,  -224,     7,
    -224,  1299,  1075,   -52,    25,   341,  -224,  -224,   -47,    53,
    -224,  -224,   153,   124,  -224,   -14,  -224,  1040,  -224,  -224,
     -17,  1330,  -224,   -10,  -224,    15,  1075,  -224,   967,   705,
     -52,  -224,  -224,    53,    31,   -50,  -224,  -224,  -224,  -224,
      57,  -224,   534,  1075,  -224,  1330,  1330,  1109,  -224,    40,
    1330,  -224,   424,    64,  -224,  -224,  -224,  -224,    47,   150,
     118,  -224,     0,  -224,  -224,  -224,   822,   822,   838,  -224,
    -224,   638,  -224,  -224,  -224,  -224,  -224,  -224,    48,  -224,
     872,  -224,   -43,   -20,    39,    34,   173,   148,   166,   154,
     234,     8,  -224,   175,   101,   872,    53,  -224,  -224,   534,
     712,  -224,  -224,  -224,  -224,  1144,  -224,  -224,  -224,   872,
      28,  -224,   164,  -224,   165,   170,   872,   174,   177,   491,
     182,   252,   188,   558,   193,   194,  -224,  -224,    94,  -224,
    -224,  -224,  -224,   277,  -224,  -224,  -224,  -224,  -224,   927,
     721,  -224,    54,  -224,    58,  -224,  1265,  -224,   266,   872,
    -224,  -224,   638,  -224,   133,   122,   197,   274,  -224,  -224,
     737,   872,   275,  -224,   872,   872,   872,   872,   872,   872,
     872,   872,   872,   872,   872,   872,   872,   872,   872,   872,
     872,   872,   872,  -224,  -224,  -224,  -224,  -224,   103,   872,
     872,   872,   872,   872,   872,   872,   872,   872,   872,   872,
    -224,  -224,    40,  -224,   872,   491,  -224,   195,  -224,   491,
     224,   584,   198,   872,  -224,    99,   872,   872,   872,  -224,
    -224,  -224,  -224,   214,   215,  -224,   216,    58,  1220,   755,
    -224,  -224,  -224,   217,  -224,  1180,    96,  -224,   872,  -224,
    -224,   139,  -224,   -62,  -224,  -224,  -224,  -224,   -43,   -43,
     -20,   -20,    39,    39,    39,    39,    34,    34,   173,   148,
     166,   154,   234,    -6,   357,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
     491,  -224,   220,   584,  -224,   147,  -224,   152,   159,  -224,
    -224,  -224,  -224,  -224,   221,  -224,   222,  -224,  -224,  -224,
     872,  -224,   872,  -224,  -224,  -224,   872,   788,   491,   491,
     491,  -224,  -224,  -224,  -224,   167,   491,   172,   253,  -224,
    -224,   207,  -224,   491,   491,  -224,  -224,  -224
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   132,    90,    93,   128,    98,     0,    88,    97,    95,
      96,    91,    94,    99,    89,   107,    87,   103,   108,   100,
      92,   129,   139,     0,   208,     0,    77,    79,   101,     0,
     102,    81,     0,   131,     0,     0,   205,   207,   123,     0,
     143,   141,   140,     0,    75,     0,    83,    85,    78,    80,
     106,     0,    82,   185,   182,     0,     0,   212,     0,     0,
     130,     1,   206,     0,   126,     0,   124,   144,   142,   133,
       0,    76,     0,     0,   210,     0,   113,     0,   109,     0,
     115,   184,     0,    85,   183,   211,   152,   138,   151,     0,
     145,   147,     0,     4,     2,     3,     0,     0,     0,    24,
      23,     0,   135,    22,    25,    26,    27,     6,    16,    28,
       0,    30,    34,    37,    40,    45,    48,    50,    52,    54,
      56,    58,    74,     0,     0,     0,     0,   121,    84,     0,
      28,    60,   168,    86,   209,     0,   112,   105,   110,     0,
       0,   116,   118,   114,     2,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   191,    72,     0,   189,
     190,   173,   174,     0,   187,   175,   176,   177,   178,     0,
       0,   149,   156,   150,   157,   136,     0,   137,     0,     0,
      18,    19,     0,    20,     0,   154,     0,     0,    12,    13,
       0,     0,     0,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   134,   122,   127,   125,   171,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     104,   119,     0,   111,     0,     0,   202,     0,   201,     0,
       0,     0,     0,     0,   203,     0,     0,     0,     0,   192,
     186,   188,   164,     0,     0,   160,     0,   158,     0,     0,
     146,   148,   153,     0,     5,     0,   156,   155,     0,    11,
       8,     0,    14,     0,    10,    31,    32,    33,    35,    36,
      38,    39,    43,    44,    41,    42,    46,    47,    49,    51,
      53,    55,    57,     0,     0,   169,    64,    65,    66,    62,
      63,    67,    68,    69,    70,    71,    61,   117,   120,   179,
       0,   181,     0,     0,   200,     0,   204,     0,     0,    73,
     165,   159,   161,   166,     0,   162,     0,    21,    29,     9,
       0,     7,     0,   170,   172,   180,     0,     0,     0,     0,
       0,   167,   163,    15,    59,     0,     0,     0,   193,   195,
     196,     0,   198,     0,     0,   197,   199,   194
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -224,  -224,  -224,  -224,   -59,  -224,  -102,   -89,    17,    74,
      27,    91,    92,    93,    95,    90,  -224,   -58,   -65,    12,
     -55,    22,     5,  -224,   245,  -224,   160,  -224,  -224,   229,
     -64,   -66,  -224,   111,  -224,   259,   200,   168,    -2,    -1,
     -16,  -224,   -56,  -224,   176,  -224,   162,   -84,  -163,  -126,
    -224,  -133,  -224,   306,   -13,  -224,  -224,   191,  -223,  -224,
    -224,  -224,  -224,   320,  -224
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   107,   108,   271,   130,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   131,   157,   158,
     123,    24,    55,    45,    46,    26,    27,    28,    29,    77,
      78,    79,   140,   141,    30,    65,    66,    31,    32,    33,
      34,    42,   253,    90,    91,    92,   186,   254,   174,   133,
     218,   160,   161,    56,   162,    82,   163,   164,   165,   166,
     167,   168,    35,    36,    37
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     109,   122,    89,   217,   173,    25,    41,   132,   193,   257,
     136,    38,    50,   138,   143,   331,   240,   248,   313,    57,
       1,    43,    58,    47,    59,   211,    68,   194,   195,   126,
       1,    48,    49,    60,    74,   185,    52,   180,   181,   183,
      25,   196,   127,    85,    63,     1,   201,   202,   197,   199,
     200,   109,     1,    83,    54,   187,   188,   189,    64,     1,
     134,   198,     1,    88,   132,    70,   109,   122,    83,    54,
     215,   138,   172,   248,    75,   177,    71,   142,    84,   178,
     109,   122,    81,   332,   231,    22,   171,   109,   122,    23,
     337,   237,   275,   276,   277,    84,   212,    39,    51,    23,
     125,   267,   309,   257,   159,    44,   311,   232,   278,   279,
      22,   109,   122,   184,    23,   256,   185,    22,   233,   203,
     204,   169,   190,   170,   191,   272,   192,    22,   169,   139,
     170,    23,   258,    72,   259,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   172,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   245,   328,    43,   334,   266,
     265,    60,   170,   248,    88,   109,   122,   335,   248,   308,
     126,    88,   294,   319,   249,   159,     4,   205,   206,   316,
      40,   184,    22,   214,   184,   295,   265,   176,   170,    69,
     109,   122,   324,   273,   326,   348,   349,   350,   264,   109,
      67,    76,   248,   352,   329,    21,   280,   281,   330,    80,
     356,   357,   338,    22,   293,   175,   248,   339,   207,   132,
     142,   248,   286,   287,   340,    76,    76,    76,   248,   208,
      76,   209,   351,    80,    80,    80,   248,   353,    80,   266,
     210,   248,   213,   234,   235,   315,   241,   242,   317,   318,
     236,    76,   243,    88,   238,   343,   239,   246,   247,    80,
      88,   262,   268,   109,   344,   282,   283,   284,   285,   269,
     274,    93,   144,    95,   310,    96,    97,   312,   314,   320,
     321,   354,   327,   322,   336,    76,   341,   355,   288,   342,
     289,   292,   290,    80,   135,   291,     2,   145,   146,     3,
       4,   147,   148,   149,     5,   128,     6,     7,     8,   150,
     151,   152,   124,     9,    10,    11,   216,   153,    12,    13,
      98,    14,    15,   154,    16,    17,    18,    19,    20,    21,
     155,    61,    76,   307,   263,    99,     1,   100,   345,   347,
      80,   101,   261,    73,   251,    62,     0,   103,   104,   105,
     106,    93,    94,    95,     0,    96,    97,   156,    53,   250,
       2,     0,     0,     3,     4,     0,     0,     0,     5,     0,
       6,     7,     8,     0,     0,     0,     0,     9,    10,    11,
       0,     0,    12,    13,     0,    14,    15,     0,    16,    17,
      18,    19,    20,    21,     0,     0,     0,     0,     0,     0,
      98,    22,     0,     0,     0,    23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    99,     0,   100,    93,   144,
      95,   101,    96,    97,     0,     0,     0,   103,   104,   105,
     106,     0,     0,     0,     0,     0,     0,     0,   129,   333,
       0,     0,     0,     2,   145,   146,     3,     4,   147,   148,
     149,     5,     0,     6,     7,     8,   150,   151,   152,     0,
       9,    10,    11,     0,   153,    12,    13,    98,    14,    15,
     154,    16,    17,    18,    19,    20,    21,   155,     0,     0,
       0,     0,    99,     0,   100,    93,   144,    95,   101,    96,
      97,     0,     0,     0,   103,   104,   105,   106,     0,     0,
       0,     0,     0,     0,   156,    53,     0,     0,     0,     0,
       0,   145,   146,     0,     0,   147,   148,   149,     0,     0,
       0,     0,     0,   150,   151,   152,     0,     0,    93,    94,
      95,   153,    96,    97,    98,     0,     0,   154,     0,     0,
       0,     0,     0,     0,   155,     0,     0,     0,     0,    99,
       0,   100,    93,    94,    95,   101,    96,    97,     0,     0,
       0,   103,   104,   105,   106,     0,     0,     0,     0,     0,
       0,   156,    53,     0,     0,     0,     0,    98,    93,    94,
      95,     0,    96,    97,     0,     0,     0,     0,     0,     0,
       0,     0,    99,     0,   100,     0,     0,     0,   101,     0,
       0,    98,     0,     0,   103,   104,   105,   106,     0,     0,
       0,     0,     0,     0,     0,   129,    99,     0,   100,     0,
       0,     0,   101,     0,     0,     0,     0,    98,   103,   104,
     105,   106,    93,    94,    95,     0,    96,    97,   244,     0,
       0,     0,    99,     0,   100,     0,     0,     0,   101,     0,
       0,     0,     0,     0,   103,   104,   105,   106,     0,     0,
       3,     4,     0,     0,   156,     5,     0,     6,     0,     8,
       0,     0,     0,     0,     9,    10,     0,     0,     0,    12,
      13,    98,     0,    15,     0,     0,    17,    18,    19,    20,
      21,     0,     0,     0,     0,     0,    99,     0,   100,    93,
      94,    95,   101,    96,    97,     0,     0,     0,   103,   104,
     105,   106,     0,     0,     0,    93,    94,    95,     0,    96,
      97,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,    93,    94,    95,     0,    96,    97,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    98,    93,
      94,    95,     0,    96,    97,     0,     0,     0,     0,     0,
       0,     0,     0,    99,    98,   100,     0,     0,     0,   101,
       0,   229,   102,     0,     0,   103,   104,   105,   106,    99,
      98,   100,    93,    94,    95,   101,    96,    97,   255,     0,
       0,   103,   104,   105,   106,    99,     0,   100,    98,     0,
       0,   101,   270,     0,     0,     0,     0,   103,   104,   105,
     106,     0,     0,    99,     0,   100,    93,    94,    95,   101,
      96,    97,   325,     0,     0,   103,   104,   105,   106,     0,
       0,    98,    93,    94,    95,     0,    96,    97,     0,     0,
       0,     0,     0,     0,     0,     0,    99,     0,   100,     0,
       0,     0,   101,   346,     0,     0,     0,     0,   103,   104,
     105,   106,     0,     0,     0,    98,    93,    94,    95,     0,
      96,    97,     0,     0,     0,     0,     0,     0,     0,     0,
      99,    98,   100,     0,     0,     0,   179,     0,     0,     0,
       0,     0,   103,   104,   105,   106,    99,     0,   100,     0,
       0,     0,   182,     0,     0,     0,     0,     0,   103,   104,
     105,   106,     0,     0,     0,    98,     0,     0,     0,     0,
       0,     0,     1,     0,     0,     0,     0,     0,     0,     0,
      99,     0,   100,     0,     0,     0,   101,     0,     0,     0,
       0,     0,   103,   104,   105,   106,     2,     0,     0,     3,
       4,     0,     0,     0,     5,     0,     6,     7,     8,     0,
       0,     0,    86,     9,    10,    11,     0,     0,    12,    13,
       0,    14,    15,     0,    16,    17,    18,    19,    20,    21,
       0,     0,     0,     0,     0,     0,     2,    22,     0,     3,
       4,   169,   252,   170,     5,     0,     6,     7,     8,     1,
       0,     0,     0,     9,    10,    11,     0,     0,    12,    13,
       0,    14,    15,     0,    16,    17,    18,    19,    20,    21,
       0,     0,     0,     2,     0,     0,     3,     4,     0,     0,
       0,     5,    87,     6,     7,     8,     0,     0,     0,     0,
       9,    10,    11,     0,     0,    12,    13,     0,    14,    15,
       0,    16,    17,    18,    19,    20,    21,     0,     0,     2,
       0,     0,     3,     4,    22,     0,     0,     5,    23,     6,
       7,     8,     0,     0,     0,     0,     9,    10,    11,     0,
       0,    12,    13,     0,    14,    15,     0,    16,    17,    18,
      19,    20,    21,     0,     2,     0,     0,     3,     4,    72,
       0,     0,     5,     0,     6,     7,     8,     0,     0,     0,
       0,     9,    10,    11,     0,     0,    12,    13,     0,    14,
      15,    53,    16,    17,    18,    19,    20,    21,     0,     0,
       0,     3,     4,     0,     0,     0,     5,     0,     6,     0,
       8,     0,     0,     0,     0,     9,    10,     0,     0,     0,
      12,    13,     0,     0,    15,     0,    53,    17,    18,    19,
      20,    21,     0,     0,     0,     0,     3,     4,     0,     0,
       0,     5,     0,     6,     0,     8,     0,     0,     0,     0,
       9,    10,     0,     0,     0,    12,    13,     0,     0,    15,
       0,   137,    17,    18,    19,    20,    21,     0,     0,     2,
       0,     0,     3,     4,     0,     0,     0,     5,     0,     6,
       7,     8,     0,     0,     0,     0,     9,    10,    11,     0,
       0,    12,    13,     0,    14,    15,   230,    16,    17,    18,
      19,    20,    21,     0,     0,     0,     0,     0,     0,     2,
      22,     0,     3,     4,   265,   252,   170,     5,     0,     6,
       7,     8,     0,     0,     0,     0,     9,    10,    11,     0,
       0,    12,    13,     0,    14,    15,     0,    16,    17,    18,
      19,    20,    21,   260,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,   323,     0,     3,     4,     0,
       0,     0,     5,     0,     6,     7,     8,     0,     0,     0,
       0,     9,    10,    11,     0,     0,    12,    13,     0,    14,
      15,     0,    16,    17,    18,    19,    20,    21,     2,     0,
       0,     3,     4,     0,     0,     0,     5,     0,     6,     7,
       8,     0,     0,     0,     0,     9,    10,    11,     0,     0,
      12,    13,     0,    14,    15,     0,    16,    17,    18,    19,
      20,    21,     3,     4,     0,     0,     0,     5,     0,     6,
       0,     8,     0,     0,     0,     0,     9,    10,     0,     0,
       0,    12,    13,     0,     0,    15,     0,     0,    17,    18,
      19,    20,    21
};

static const yytype_int16 yycheck[] =
{
      59,    59,    58,   129,    88,     0,    22,    72,   110,   172,
      76,     5,     5,    77,    80,    77,   149,    79,   241,    32,
       5,    23,    74,    25,    76,    17,    42,    70,    71,    79,
       5,    26,    27,    34,    47,   101,    31,    96,    97,    98,
      35,    84,    92,    56,    91,     5,    12,    13,    68,    10,
      11,   110,     5,    55,    32,     7,     8,     9,     5,     5,
      73,    81,     5,    58,   129,    79,   125,   125,    70,    47,
     125,   135,    88,    79,    91,    75,    90,    79,    56,    79,
     139,   139,    92,    89,   139,    70,    88,   146,   146,    74,
     313,   146,   194,   195,   196,    73,    88,    91,    91,    74,
      69,   185,   235,   266,    82,    90,   239,    79,   197,   198,
      70,   170,   170,   101,    74,   170,   182,    70,    90,    85,
      86,    74,    74,    76,    76,   190,    78,    70,    74,    89,
      76,    74,    74,    69,    76,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   169,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   153,   268,   169,   294,   185,
      74,   172,    76,    79,   169,   234,   234,   310,    79,   234,
      79,   176,    79,   248,    90,   163,    33,    14,    15,    90,
      22,   179,    70,    92,   182,    92,    74,    79,    76,    75,
     259,   259,   258,   191,   259,   338,   339,   340,    75,   268,
      42,    51,    79,   346,    75,    62,   199,   200,    79,    51,
     353,   354,    75,    70,   212,    75,    79,    75,    80,   294,
     232,    79,   205,   206,    75,    75,    76,    77,    79,    73,
      80,    87,    75,    75,    76,    77,    79,    75,    80,   265,
      16,    79,    77,    89,    89,   243,    74,     5,   246,   247,
      90,   101,    74,   258,    90,   330,    89,    74,    74,   101,
     265,     5,    75,   332,   332,   201,   202,   203,   204,     5,
       5,     4,     5,     6,    89,     8,     9,    63,    90,    75,
      75,    38,    75,    77,    74,   135,    75,    90,   207,    77,
     208,   211,   209,   135,    75,   210,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    70,    39,    40,    41,    42,
      43,    44,    63,    46,    47,    48,   126,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,     0,   182,   232,   182,    68,     5,    70,   336,   337,
     182,    74,   176,    47,   163,    35,    -1,    80,    81,    82,
      83,     4,     5,     6,    -1,     8,     9,    90,    91,    92,
      29,    -1,    -1,    32,    33,    -1,    -1,    -1,    37,    -1,
      39,    40,    41,    -1,    -1,    -1,    -1,    46,    47,    48,
      -1,    -1,    51,    52,    -1,    54,    55,    -1,    57,    58,
      59,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    70,    -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    70,     4,     5,
       6,    74,     8,     9,    -1,    -1,    -1,    80,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    92,
      -1,    -1,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    39,    40,    41,    42,    43,    44,    -1,
      46,    47,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    -1,
      -1,    -1,    68,    -1,    70,     4,     5,     6,    74,     8,
       9,    -1,    -1,    -1,    80,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    91,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    42,    43,    44,    -1,    -1,     4,     5,
       6,    50,     8,     9,    53,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    68,
      -1,    70,     4,     5,     6,    74,     8,     9,    -1,    -1,
      -1,    80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    91,    -1,    -1,    -1,    -1,    53,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    -1,    70,    -1,    -1,    -1,    74,    -1,
      -1,    53,    -1,    -1,    80,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    91,    68,    -1,    70,    -1,
      -1,    -1,    74,    -1,    -1,    -1,    -1,    53,    80,    81,
      82,    83,     4,     5,     6,    -1,     8,     9,    90,    -1,
      -1,    -1,    68,    -1,    70,    -1,    -1,    -1,    74,    -1,
      -1,    -1,    -1,    -1,    80,    81,    82,    83,    -1,    -1,
      32,    33,    -1,    -1,    90,    37,    -1,    39,    -1,    41,
      -1,    -1,    -1,    -1,    46,    47,    -1,    -1,    -1,    51,
      52,    53,    -1,    55,    -1,    -1,    58,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    -1,    68,    -1,    70,     4,
       5,     6,    74,     8,     9,    -1,    -1,    -1,    80,    81,
      82,    83,    -1,    -1,    -1,     4,     5,     6,    -1,     8,
       9,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,     4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    53,    70,    -1,    -1,    -1,    74,
      -1,    69,    77,    -1,    -1,    80,    81,    82,    83,    68,
      53,    70,     4,     5,     6,    74,     8,     9,    77,    -1,
      -1,    80,    81,    82,    83,    68,    -1,    70,    53,    -1,
      -1,    74,    75,    -1,    -1,    -1,    -1,    80,    81,    82,
      83,    -1,    -1,    68,    -1,    70,     4,     5,     6,    74,
       8,     9,    77,    -1,    -1,    80,    81,    82,    83,    -1,
      -1,    53,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    70,    -1,
      -1,    -1,    74,    75,    -1,    -1,    -1,    -1,    80,    81,
      82,    83,    -1,    -1,    -1,    53,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    53,    70,    -1,    -1,    -1,    74,    -1,    -1,    -1,
      -1,    -1,    80,    81,    82,    83,    68,    -1,    70,    -1,
      -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,    80,    81,
      82,    83,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      -1,    -1,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    -1,    70,    -1,    -1,    -1,    74,    -1,    -1,    -1,
      -1,    -1,    80,    81,    82,    83,    29,    -1,    -1,    32,
      33,    -1,    -1,    -1,    37,    -1,    39,    40,    41,    -1,
      -1,    -1,     5,    46,    47,    48,    -1,    -1,    51,    52,
      -1,    54,    55,    -1,    57,    58,    59,    60,    61,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    70,    -1,    32,
      33,    74,    75,    76,    37,    -1,    39,    40,    41,     5,
      -1,    -1,    -1,    46,    47,    48,    -1,    -1,    51,    52,
      -1,    54,    55,    -1,    57,    58,    59,    60,    61,    62,
      -1,    -1,    -1,    29,    -1,    -1,    32,    33,    -1,    -1,
      -1,    37,    75,    39,    40,    41,    -1,    -1,    -1,    -1,
      46,    47,    48,    -1,    -1,    51,    52,    -1,    54,    55,
      -1,    57,    58,    59,    60,    61,    62,    -1,    -1,    29,
      -1,    -1,    32,    33,    70,    -1,    -1,    37,    74,    39,
      40,    41,    -1,    -1,    -1,    -1,    46,    47,    48,    -1,
      -1,    51,    52,    -1,    54,    55,    -1,    57,    58,    59,
      60,    61,    62,    -1,    29,    -1,    -1,    32,    33,    69,
      -1,    -1,    37,    -1,    39,    40,    41,    -1,    -1,    -1,
      -1,    46,    47,    48,    -1,    -1,    51,    52,    -1,    54,
      55,    91,    57,    58,    59,    60,    61,    62,    -1,    -1,
      -1,    32,    33,    -1,    -1,    -1,    37,    -1,    39,    -1,
      41,    -1,    -1,    -1,    -1,    46,    47,    -1,    -1,    -1,
      51,    52,    -1,    -1,    55,    -1,    91,    58,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    32,    33,    -1,    -1,
      -1,    37,    -1,    39,    -1,    41,    -1,    -1,    -1,    -1,
      46,    47,    -1,    -1,    -1,    51,    52,    -1,    -1,    55,
      -1,    92,    58,    59,    60,    61,    62,    -1,    -1,    29,
      -1,    -1,    32,    33,    -1,    -1,    -1,    37,    -1,    39,
      40,    41,    -1,    -1,    -1,    -1,    46,    47,    48,    -1,
      -1,    51,    52,    -1,    54,    55,    92,    57,    58,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      70,    -1,    32,    33,    74,    75,    76,    37,    -1,    39,
      40,    41,    -1,    -1,    -1,    -1,    46,    47,    48,    -1,
      -1,    51,    52,    -1,    54,    55,    -1,    57,    58,    59,
      60,    61,    62,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    75,    -1,    32,    33,    -1,
      -1,    -1,    37,    -1,    39,    40,    41,    -1,    -1,    -1,
      -1,    46,    47,    48,    -1,    -1,    51,    52,    -1,    54,
      55,    -1,    57,    58,    59,    60,    61,    62,    29,    -1,
      -1,    32,    33,    -1,    -1,    -1,    37,    -1,    39,    40,
      41,    -1,    -1,    -1,    -1,    46,    47,    48,    -1,    -1,
      51,    52,    -1,    54,    55,    -1,    57,    58,    59,    60,
      61,    62,    32,    33,    -1,    -1,    -1,    37,    -1,    39,
      -1,    41,    -1,    -1,    -1,    -1,    46,    47,    -1,    -1,
      -1,    51,    52,    -1,    -1,    55,    -1,    -1,    58,    59,
      60,    61,    62
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    29,    32,    33,    37,    39,    40,    41,    46,
      47,    48,    51,    52,    54,    55,    57,    58,    59,    60,
      61,    62,    70,    74,   114,   115,   118,   119,   120,   121,
     127,   130,   131,   132,   133,   155,   156,   157,     5,    91,
     130,   133,   134,   131,    90,   116,   117,   131,   115,   115,
       5,    91,   115,    91,   114,   115,   146,   147,    74,    76,
     132,     0,   156,    91,     5,   128,   129,   130,   133,    75,
      79,    90,    69,   146,   147,    91,   119,   122,   123,   124,
     130,    92,   148,   131,   114,   147,     5,    75,   115,   135,
     136,   137,   138,     4,     5,     6,     8,     9,    53,    68,
      70,    74,    77,    80,    81,    82,    83,    94,    95,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   113,   128,    69,    79,    92,   117,    91,
      97,   110,   111,   142,   147,   122,   124,    92,   123,    89,
     125,   126,   131,   124,     5,    30,    31,    34,    35,    36,
      42,    43,    44,    50,    56,    63,    90,   111,   112,   114,
     144,   145,   147,   149,   150,   151,   152,   153,   154,    74,
      76,   131,   133,   140,   141,    75,    79,    75,    79,    74,
      97,    97,    74,    97,   112,   124,   139,     7,     8,     9,
      74,    76,    78,    99,    70,    71,    84,    68,    81,    10,
      11,    12,    13,    85,    86,    14,    15,    80,    73,    87,
      16,    17,    88,    77,    92,   113,   129,   142,   143,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    69,
      92,   113,    79,    90,    89,    89,    90,   113,    90,    89,
     144,    74,     5,    74,    90,   112,    74,    74,    79,    90,
      92,   150,    75,   135,   140,    77,   113,   141,    74,    76,
      18,   137,     5,   139,    75,    74,   133,   140,    75,     5,
      75,    96,   111,   112,     5,    99,    99,    99,   100,   100,
     101,   101,   102,   102,   102,   102,   103,   103,   104,   105,
     106,   107,   108,   112,    79,    92,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   126,   113,   144,
      89,   144,    63,   151,    90,   112,    90,   112,   112,   111,
      75,    75,    77,    75,   135,    77,   113,    75,    99,    75,
      79,    77,    89,    92,   142,   144,    74,   151,    75,    75,
      75,    75,    77,   111,   110,   112,    75,   112,   144,   144,
     144,    75,   144,    75,    38,    90,   144,   144
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    93,    94,    94,    94,    94,    95,    95,    95,    95,
      95,    95,    95,    95,    96,    96,    97,    97,    97,    97,
      97,    97,    98,    98,    98,    98,    98,    98,    99,    99,
     100,   100,   100,   100,   101,   101,   101,   102,   102,   102,
     103,   103,   103,   103,   103,   104,   104,   104,   105,   105,
     106,   106,   107,   107,   108,   108,   109,   109,   110,   110,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   112,   112,   113,   114,   114,   115,   115,   115,
     115,   115,   115,   116,   116,   117,   117,   118,   118,   118,
     118,   118,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   120,   120,   120,   121,   121,   122,
     122,   123,   124,   124,   124,   124,   125,   125,   126,   126,
     126,   127,   127,   127,   128,   128,   129,   129,   130,   130,
     131,   131,   132,   132,   132,   132,   132,   132,   132,   133,
     133,   133,   133,   134,   134,   135,   135,   136,   136,   137,
     137,   137,   138,   138,   139,   139,   140,   140,   140,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   142,   142,
     142,   143,   143,   144,   144,   144,   144,   144,   144,   145,
     145,   145,   146,   146,   147,   148,   147,   149,   149,   150,
     150,   151,   151,   152,   152,   152,   153,   153,   153,   153,
     154,   154,   154,   154,   154,   155,   155,   156,   156,   157,
     157,   157,   157
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     3,     1,     2,     2,     2,
       2,     4,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     5,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     3,     1,     2,     3,     1,     2,     1,
       2,     1,     2,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     4,     2,     1,     1,     1,
       2,     3,     2,     1,     2,     1,     1,     3,     1,     2,
       3,     4,     5,     2,     1,     3,     1,     3,     1,     1,
       2,     1,     1,     3,     4,     3,     4,     4,     3,     1,
       2,     2,     3,     1,     2,     1,     3,     1,     3,     2,
       2,     1,     1,     3,     1,     2,     1,     1,     2,     3,
       2,     3,     3,     4,     2,     3,     3,     4,     1,     3,
       4,     1,     3,     1,     1,     1,     1,     1,     1,     3,
       4,     3,     1,     2,     2,     0,     4,     1,     2,     1,
       1,     1,     2,     5,     7,     5,     5,     7,     6,     7,
       3,     2,     2,     2,     3,     1,     2,     1,     1,     4,
       3,     3,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 74 "myParser.y" /* yacc.c:1646  */
    {
				if(containsSymbol(currentTable, (yyvsp[0].stringBuff))) {
					(yyval.num.intBuff) = getSymbolValue(currentTable, (yyvsp[0].stringBuff));
					strcpy(currentSym, (yyvsp[0].stringBuff));
					printf("exprval: %lli\n",(yyval.num.intBuff));
				} else if(searchSymbol(currentTable, (yyvsp[0].stringBuff))) {
					printf("Symbol found in outer scope\n");
				} else {
					yyerror("Symbol not found");
				}
			}
#line 1819 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 85 "myParser.y" /* yacc.c:1646  */
    {
					if (yylval.num.typeFlag == INT_T || yylval.num.typeFlag == LONG_T || yylval.num.typeFlag == LONGLONG_T)
                        (yyval.num.intBuff) = yylval.num.intBuff;
					else {
                        (yyval.num.intBuff) = (long long)yylval.num.realBuff;
                        fprintf(stderr,"Truncating real number %Lg to integer %lld\n",yylval.num.realBuff,(yyval.num.intBuff));
                        printf("exprval=%lld\n",(yyval.num.intBuff));
					}
				}
#line 1833 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 94 "myParser.y" /* yacc.c:1646  */
    {yyerror("Strings not supported.");}
#line 1839 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 95 "myParser.y" /* yacc.c:1646  */
    {}
#line 1845 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 115 "myParser.y" /* yacc.c:1646  */
    {}
#line 1851 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 116 "myParser.y" /* yacc.c:1646  */
    {}
#line 1857 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 117 "myParser.y" /* yacc.c:1646  */
    {}
#line 1863 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 118 "myParser.y" /* yacc.c:1646  */
    {}
#line 1869 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 119 "myParser.y" /* yacc.c:1646  */
    {}
#line 1875 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 120 "myParser.y" /* yacc.c:1646  */
    {}
#line 1881 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 133 "myParser.y" /* yacc.c:1646  */
    {}
#line 1887 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 134 "myParser.y" /* yacc.c:1646  */
    {}
#line 1893 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 145 "myParser.y" /* yacc.c:1646  */
    {}
#line 1899 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 186 "myParser.y" /* yacc.c:1646  */
    {}
#line 1905 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 201 "myParser.y" /* yacc.c:1646  */
    {}
#line 1911 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 202 "myParser.y" /* yacc.c:1646  */
    { (yyval.num.intBuff) = (yyvsp[0].num.intBuff); setSymbolValue(currentTable, currentSym, (long long) (yyvsp[0].num.intBuff)); printf( "exprval=%lld\n", (yyval.num.intBuff)); }
#line 1917 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 203 "myParser.y" /* yacc.c:1646  */
    {(yyval.num.intBuff) = (yyvsp[-2].num.intBuff) + (yyvsp[0].num.intBuff);(yyvsp[-2].num.intBuff) = (yyval.num.intBuff); }
#line 1923 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 204 "myParser.y" /* yacc.c:1646  */
    { (yyval.num.intBuff) = (yyvsp[-2].num.intBuff) - (yyvsp[0].num.intBuff);(yyvsp[-2].num.intBuff) = (yyval.num.intBuff);}
#line 1929 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 205 "myParser.y" /* yacc.c:1646  */
    { (yyval.num.intBuff) = (yyvsp[-2].num.intBuff) * (yyvsp[0].num.intBuff);(yyvsp[-2].num.intBuff) = (yyval.num.intBuff); }
#line 1935 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 206 "myParser.y" /* yacc.c:1646  */
    { (yyval.num.intBuff) = (yyvsp[-2].num.intBuff) / (yyvsp[0].num.intBuff);(yyvsp[-2].num.intBuff) = (yyval.num.intBuff); }
#line 1941 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 207 "myParser.y" /* yacc.c:1646  */
    { (yyval.num.intBuff) = (yyvsp[-2].num.intBuff) % (yyvsp[0].num.intBuff);(yyvsp[-2].num.intBuff) = (yyval.num.intBuff); }
#line 1947 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 208 "myParser.y" /* yacc.c:1646  */
    { (yyval.num.intBuff) = (yyvsp[-2].num.intBuff) << (yyvsp[0].num.intBuff);(yyvsp[-2].num.intBuff) = (yyval.num.intBuff); }
#line 1953 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 209 "myParser.y" /* yacc.c:1646  */
    { (yyval.num.intBuff) = (yyvsp[-2].num.intBuff) >> (yyvsp[0].num.intBuff);(yyvsp[-2].num.intBuff) = (yyval.num.intBuff); }
#line 1959 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 210 "myParser.y" /* yacc.c:1646  */
    { (yyval.num.intBuff) = (yyvsp[-2].num.intBuff) & (yyvsp[0].num.intBuff);(yyvsp[-2].num.intBuff) = (yyval.num.intBuff); }
#line 1965 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 211 "myParser.y" /* yacc.c:1646  */
    { (yyval.num.intBuff) = (yyvsp[-2].num.intBuff) | (yyvsp[0].num.intBuff);(yyvsp[-2].num.intBuff) = (yyval.num.intBuff); }
#line 1971 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 212 "myParser.y" /* yacc.c:1646  */
    { (yyval.num.intBuff) = (yyvsp[-2].num.intBuff) ^ (yyvsp[0].num.intBuff);(yyvsp[-2].num.intBuff) = (yyval.num.intBuff); }
#line 1977 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 352 "myParser.y" /* yacc.c:1646  */
    {
				if(!containsSymbol(currentTable, (yyvsp[0].stringBuff))) {
					installSymbol(currentTable, (yyvsp[0].stringBuff), filename, line, NUM);
				} else {
					yyerror("Redeclaration of variable");
				}
			}
#line 1989 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 397 "myParser.y" /* yacc.c:1646  */
    {printf("%s\n", "identifier list");}
#line 1995 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 426 "myParser.y" /* yacc.c:1646  */
    {}
#line 2001 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 427 "myParser.y" /* yacc.c:1646  */
    {}
#line 2007 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 469 "myParser.y" /* yacc.c:1646  */
    {
                //TODO: fix later
        }
#line 2015 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 472 "myParser.y" /* yacc.c:1646  */
    {doScopeThing();}
#line 2021 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 472 "myParser.y" /* yacc.c:1646  */
    {
                currentTable = leaveScope(currentTable, 0);
        }
#line 2029 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 519 "myParser.y" /* yacc.c:1646  */
    {printf("Left function!\n");}
#line 2035 "myParser.tab.c" /* yacc.c:1646  */
    break;


#line 2039 "myParser.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 530 "myParser.y" /* yacc.c:1906  */


void doScopeThing() {
	if(currentTable -> scope == GLOBAL_SCOPE) {
		currentTable = enterScope(FUNCTION_SCOPE, line, filename, currentTable);
	} else {
		currentTable = enterScope(BLOCK_SCOPE, line, filename, currentTable);
	}
}

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

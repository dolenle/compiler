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
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

extern int yylex();
//extern int yyparse();
int line;
char filename[4096];

#define YYDEBUG 1
int yydebug = 0;
void yyerror(const char* s);
symbolTable* currentTable;

#line 84 "myParser.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
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
#line 21 "myParser.y" /* yacc.c:355  */

	char charBuff;
	char* stringBuff;
	void* noval;
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
		} signFlag;
		enum signtype {
			SIGNED_T,
			UNSIGNED_T
		} typeFlag;
	} num;

#line 214 "myParser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MYPARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 231 "myParser.tab.c" /* yacc.c:358  */

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
#define YYLAST   1408

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  93
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  215
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  366

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
       2,     2,     2,    81,     2,     2,     2,    84,    83,     2,
      74,    75,    70,    68,    79,    80,    78,    71,     2,     2,
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
       0,    67,    67,    73,    74,    75,    79,    80,    81,    82,
      83,    84,    85,    86,    90,    91,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   105,   118,   119,
     123,   124,   125,   126,   130,   131,   132,   136,   137,   138,
     142,   143,   144,   145,   146,   150,   151,   152,   156,   157,
     161,   162,   166,   167,   171,   172,   176,   177,   181,   182,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   215,   216,   220,   224,   225,   229,   230,   231,
     232,   233,   234,   238,   239,   243,   244,   248,   249,   250,
     251,   252,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   271,   272,   273,   277,   278,   282,
     283,   287,   291,   292,   293,   294,   298,   299,   303,   304,
     305,   309,   310,   311,   315,   316,   320,   321,   325,   326,
     330,   331,   335,   342,   343,   344,   345,   346,   347,   351,
     352,   353,   354,   358,   359,   364,   365,   369,   370,   374,
     375,   376,   380,   381,   385,   386,   390,   391,   392,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   408,   409,
     410,   414,   415,   419,   420,   421,   422,   423,   424,   428,
     429,   430,   434,   435,   435,   446,   447,   448,   449,   450,
     454,   455,   459,   460,   464,   465,   469,   470,   471,   475,
     476,   477,   478,   482,   483,   484,   485,   486,   490,   491,
     495,   496,   500,   501,   502,   503
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
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
  "')'", "'['", "']'", "'.'", "','", "'-'", "'!'", "'~'", "'&'", "'%'",
  "'<'", "'>'", "'|'", "'?'", "':'", "';'", "'{'", "'}'", "$accept",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "$@1", "cast_expression",
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
  "initializer_list", "statement", "labeled_statement",
  "compound_statement", "$@2", "declaration_or_statement_list",
  "declaration_list", "statement_list", "expression_statement",
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
      45,    33,   126,    38,    37,    60,    62,   124,    63,    58,
      59,   123,   125
};
# endif

#define YYPACT_NINF -231

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-231)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1020,  -231,  -231,  -231,  -231,  -231,     6,  -231,  -231,  -231,
    -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,
    -231,  -231,   -14,    21,  -231,     2,  1315,  1315,  -231,     9,
    -231,  1315,  1091,   118,    11,   904,  -231,  -231,   -13,    84,
    -231,  -231,   -14,   102,  -231,   -16,  -231,  1056,  -231,  -231,
      18,  1346,  -231,    40,  -231,     2,  -231,  1091,   983,   682,
     118,  -231,  -231,    84,    66,   -61,  -231,  -231,  -231,  -231,
      21,  -231,   535,  -231,  1091,  1346,  1346,  1125,  -231,   179,
    1346,  -231,   425,   146,  -231,  -231,  -231,  -231,    54,   148,
     152,  -231,   -54,  -231,  -231,  -231,   799,   799,   815,   849,
     849,   615,  -231,   849,   849,   849,   849,  -231,    60,  -231,
    -231,    12,   -44,   108,   103,    56,   172,   189,   183,   250,
       0,  -231,   196,   -50,   849,    84,  -231,  -231,   535,   420,
    -231,  -231,  -231,  -231,  1160,  -231,  -231,  -231,   849,    22,
    -231,   188,  -231,   190,   201,   849,   202,   204,   492,   212,
     289,   222,   234,   223,   227,  -231,  -231,    95,  -231,  -231,
    -231,   326,   425,   492,  -231,  -231,  -231,  -231,   943,   698,
    -231,    30,  -231,   187,  -231,  1281,  -231,   298,   849,  -231,
    -231,   615,  -231,  -231,  -231,   -22,    57,   231,  -231,  -231,
    -231,  -231,   302,  -231,  -231,   714,   849,   304,   849,   849,
     849,   849,   849,   849,   849,   849,   849,   849,   849,   849,
     849,   849,   849,   849,   849,   849,   849,  -231,  -231,  -231,
    -231,  -231,   -28,   849,   849,   849,   849,   849,   849,   849,
     849,   849,   849,   849,  -231,  -231,   179,  -231,   849,   492,
    -231,   221,  -231,   492,   249,   559,   228,   849,  -231,    97,
     849,   849,   849,  -231,  -231,  1315,   492,   492,  -231,  -231,
     238,   244,  -231,   243,   187,  1236,   732,  -231,  -231,  -231,
     246,  -231,  1196,   193,  -231,   849,  -231,  -231,   122,  -231,
     197,  -231,  -231,  -231,  -231,    12,    12,   -44,   -44,   108,
     108,   108,   108,   103,   103,    56,   172,   189,   183,   250,
      34,   345,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,
    -231,  -231,  -231,  -231,  -231,  -231,  -231,   492,  -231,   248,
     559,  -231,   153,  -231,   154,   155,  -231,  -231,  -231,  -231,
    -231,   251,  -231,   252,  -231,  -231,  -231,   849,  -231,   849,
    -231,  -231,  -231,   849,   765,   492,   492,   492,  -231,  -231,
    -231,  -231,  -231,   175,   492,   177,   285,  -231,  -231,   237,
    -231,   492,   492,  -231,  -231,  -231
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   132,    90,    93,   128,    98,     0,    88,    97,    95,
      96,    91,    94,    99,    89,   107,    87,   103,   108,   100,
      92,   129,   139,     0,   211,     0,    77,    79,   101,     0,
     102,    81,     0,   131,     0,     0,   208,   210,   123,     0,
     143,   141,   140,     0,    75,     0,    83,    85,    78,    80,
     106,     0,    82,   183,   190,     0,   215,     0,     0,     0,
     130,     1,   209,     0,   126,     0,   124,   144,   142,   133,
       0,    76,     0,   213,     0,     0,   113,     0,   109,     0,
     115,   182,     0,    85,   191,   214,   152,   138,   151,     0,
     145,   147,     0,     4,     2,     3,     0,     0,     0,     0,
       0,     0,   135,     0,     0,     0,     0,     6,    16,    28,
      30,    34,    37,    40,    45,    48,    50,    52,    54,    56,
      58,    74,     0,     0,     0,     0,   121,    84,     0,    28,
      60,   168,    86,   212,     0,   112,   105,   110,     0,     0,
     116,   118,   114,     2,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   194,    72,     0,   192,   173,
     174,     0,   186,   185,   175,   176,   177,   178,     0,     0,
     149,   156,   150,   157,   136,     0,   137,     0,     0,    23,
      24,     0,    25,    18,    22,     0,   154,     0,    17,    19,
      20,    21,     0,    12,    13,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   134,   122,   127,
     125,   171,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   104,   119,     0,   111,     0,     0,
     205,     0,   204,     0,     0,     0,     0,     0,   206,     0,
       0,     0,     0,   195,   184,   187,   188,   189,   193,   164,
       0,     0,   160,     0,   158,     0,     0,   146,   148,   153,
       0,     5,     0,   156,   155,     0,    11,     8,     0,    14,
       0,    10,    31,    32,    33,    35,    36,    38,    39,    43,
      44,    41,    42,    46,    47,    49,    51,    53,    55,    57,
       0,     0,   169,    64,    65,    66,    62,    63,    67,    68,
      69,    70,    71,    61,   117,   120,   179,     0,   181,     0,
       0,   203,     0,   207,     0,     0,    73,   165,   159,   161,
     166,     0,   162,     0,    26,    29,     9,     0,     7,     0,
     170,   172,   180,     0,     0,     0,     0,     0,   167,   163,
      27,    15,    59,     0,     0,     0,   196,   198,   199,     0,
     201,     0,     0,   200,   202,   197
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -231,  -231,  -231,  -231,   -59,  -231,   100,   -76,    33,    52,
      75,   117,   121,   123,   124,   125,  -231,   -58,   -66,   -79,
      45,    20,    23,  -231,   267,  -231,   144,  -231,  -231,   264,
     -73,   -67,  -231,   105,  -231,   279,   218,   171,     5,    -1,
      10,  -231,   -53,  -231,   169,  -231,   164,   -78,  -168,  -126,
    -231,  -136,  -231,   170,  -231,  -231,   -39,   128,  -230,  -231,
    -231,  -231,  -231,   311,  -231
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   107,   108,   278,   129,   350,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   130,   156,   157,
     122,    54,    55,    45,    46,    26,    27,    28,    29,    77,
      78,    79,   139,   140,    30,    65,    66,    31,    32,    33,
      34,    42,   260,    90,    91,    92,   187,   261,   173,   132,
     222,   158,   159,   160,    82,   161,    57,   163,   164,   165,
     166,   167,    35,    36,    37
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     109,   121,   221,   264,   137,    89,   131,     1,    74,   135,
     172,    38,   244,   142,    50,   320,     1,   215,   125,     4,
      24,   176,   185,    25,   201,   177,     1,   258,    43,   125,
      47,   126,    41,    60,   186,     1,   202,   179,   180,   182,
     109,   109,   218,   162,   109,   109,   109,   109,    21,    48,
      49,   301,    68,   271,    52,    24,    22,   252,    25,     1,
      83,   137,   131,    70,   302,   109,   121,   192,   193,   194,
     209,   210,    22,   249,    71,    83,    23,    84,    63,   109,
     121,    88,   198,   199,   141,    23,   109,   121,   216,    64,
     344,    22,    44,   170,    84,    23,   200,    39,   171,   185,
      51,   236,   185,   316,   168,   264,   169,   318,   274,    75,
     109,   121,   237,   252,   186,   205,   206,   280,   203,   204,
     258,   258,   255,   339,    22,   285,   286,    22,   168,   279,
     169,   272,    81,   169,   195,   124,   196,   300,   197,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   322,   219,
      60,   324,   325,    43,   252,   341,   252,    69,   171,   109,
     121,   342,    84,   235,     1,   253,   326,   323,   207,   208,
     241,    88,    58,    40,    59,    76,   273,   336,    88,   183,
     184,   337,    56,   188,   189,   190,   191,   109,   121,   356,
     357,   358,   331,    67,   263,    72,   109,    73,   360,    76,
      76,    76,    80,   174,    76,   364,   365,    85,   345,   346,
     347,   175,   252,   252,   252,   131,   287,   288,    93,    94,
      95,   141,    96,    97,   133,    76,    80,    80,    80,    22,
     359,    80,   361,    23,   252,   211,   252,   289,   290,   291,
     292,   265,   212,   266,   353,   355,   214,   272,   138,   169,
     213,   351,    80,   217,   338,    84,   252,   238,    76,   239,
     109,   352,   273,   315,   293,   294,   245,    98,    88,   256,
     257,   240,   242,   243,   246,    88,   247,   250,   282,   283,
     284,   251,    99,   269,   100,    80,   275,   276,   101,   281,
     317,   333,   319,   327,   103,   104,   105,   106,   321,   328,
     329,   334,   343,   362,   248,    76,   348,   363,   295,   349,
      93,   143,    95,   296,    96,    97,   297,   127,   298,   134,
     299,   314,   123,   220,   268,   270,    62,     0,     0,    93,
      94,    95,    80,    96,    97,     2,   144,   145,     3,     4,
     146,   147,   148,     5,     0,     6,     7,     8,   149,   150,
     151,     0,     9,    10,    11,   335,   152,    12,    13,    98,
      14,    15,   153,    16,    17,    18,    19,    20,    21,   154,
       0,     0,     0,     0,    99,     0,   100,     0,    98,     0,
     101,     0,     0,     0,     0,     0,   103,   104,   105,   106,
       0,     0,     0,    99,     0,   100,   155,    53,   254,   101,
       0,     0,     0,     0,     0,   103,   104,   105,   106,    93,
     143,    95,     0,    96,    97,     0,   128,   340,     0,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,     0,
       0,     0,     0,     0,     2,   144,   145,     3,     4,   146,
     147,   148,     5,     0,     6,     7,     8,   149,   150,   151,
       0,     9,    10,    11,     0,   152,    12,    13,    98,    14,
      15,   153,    16,    17,    18,    19,    20,    21,   154,   233,
       0,     0,     0,    99,     0,   100,    93,   143,    95,   101,
      96,    97,     0,     0,     0,   103,   104,   105,   106,     0,
       0,     0,     0,     0,     0,   155,    53,     0,     0,     0,
       0,     0,   144,   145,     0,     0,   146,   147,   148,     0,
       0,     0,     0,     0,   149,   150,   151,     0,     0,    93,
      94,    95,   152,    96,    97,    98,     0,     0,   153,     0,
       0,     0,     0,     0,     0,   154,     0,     0,     0,     0,
      99,     0,   100,    93,    94,    95,   101,    96,    97,     0,
       0,     0,   103,   104,   105,   106,     0,     0,     0,     0,
       0,     0,   155,    53,     0,     0,     0,     0,    98,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    99,     0,   100,     0,     0,     0,   101,
       0,     0,    98,     0,     0,   103,   104,   105,   106,    93,
      94,    95,     0,    96,    97,     0,   128,    99,     0,   100,
       0,     0,     0,   101,     0,     0,     0,     0,     0,   103,
     104,   105,   106,     0,     0,     0,     0,     3,     4,   155,
       0,     0,     5,     0,     6,     0,     8,     0,     0,     0,
       0,     9,    10,     0,     0,     0,    12,    13,    98,     0,
      15,     0,     0,    17,    18,    19,    20,    21,     0,     0,
       0,     0,     0,    99,     0,   100,    93,    94,    95,   101,
      96,    97,     0,     0,     0,   103,   104,   105,   106,     0,
       0,     0,    93,    94,    95,     0,    96,    97,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    93,    94,
      95,     0,    96,    97,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    98,    93,    94,    95,     0,
      96,    97,     0,     0,     0,     0,     0,     0,     0,     0,
      99,    98,   100,     0,     0,     0,   101,     0,     0,   102,
       0,     0,   103,   104,   105,   106,    99,    98,   100,    93,
      94,    95,   101,    96,    97,   262,     0,     0,   103,   104,
     105,   106,    99,     0,   100,    98,     0,     0,   101,   277,
       0,     0,     0,     0,   103,   104,   105,   106,     0,     0,
      99,     0,   100,    93,    94,    95,   101,    96,    97,   332,
       0,     0,   103,   104,   105,   106,     0,     0,    98,    93,
      94,    95,     0,    96,    97,     0,     0,     0,     0,     0,
       0,     0,     0,    99,     0,   100,     0,     0,     0,   101,
     354,     0,     0,     0,     0,   103,   104,   105,   106,     0,
       0,     0,    98,    93,    94,    95,     0,    96,    97,     0,
       0,     0,     0,     0,     0,     0,     0,    99,    98,   100,
       0,     0,     0,   178,     0,     0,     0,     0,     0,   103,
     104,   105,   106,    99,     0,   100,     0,     0,     0,   181,
       0,     0,     0,     0,     0,   103,   104,   105,   106,     0,
       0,     0,    98,     0,    61,     0,     0,     0,     0,     1,
       0,     0,     0,     0,     0,     0,     0,    99,     0,   100,
       0,     0,     0,   101,     0,     0,     0,     0,     0,   103,
     104,   105,   106,     2,     0,     0,     3,     4,     0,     0,
       0,     5,     0,     6,     7,     8,     0,     0,     1,     0,
       9,    10,    11,     0,     0,    12,    13,     0,    14,    15,
       0,    16,    17,    18,    19,    20,    21,     0,     0,     0,
       0,     0,     2,     0,    22,     3,     4,     0,    23,     0,
       5,     0,     6,     7,     8,     0,     0,     0,    86,     9,
      10,    11,     0,     0,    12,    13,     0,    14,    15,     0,
      16,    17,    18,    19,    20,    21,     0,     0,     0,     0,
       0,     0,     2,    22,     0,     3,     4,   168,   259,   169,
       5,     0,     6,     7,     8,     1,     0,     0,     0,     9,
      10,    11,     0,     0,    12,    13,     0,    14,    15,     0,
      16,    17,    18,    19,    20,    21,     0,     0,     0,     2,
       0,     0,     3,     4,     0,     0,     0,     5,    87,     6,
       7,     8,     0,     0,     0,     0,     9,    10,    11,     0,
       0,    12,    13,     0,    14,    15,     0,    16,    17,    18,
      19,    20,    21,     0,     0,     2,     0,     0,     3,     4,
      22,     0,     0,     5,    23,     6,     7,     8,     0,     0,
       0,     0,     9,    10,    11,     0,     0,    12,    13,     0,
      14,    15,     0,    16,    17,    18,    19,    20,    21,     0,
       2,     0,     0,     3,     4,    72,     0,     0,     5,     0,
       6,     7,     8,     0,     0,     0,     0,     9,    10,    11,
       0,     0,    12,    13,     0,    14,    15,    53,    16,    17,
      18,    19,    20,    21,     0,     0,     0,     3,     4,     0,
       0,     0,     5,     0,     6,     0,     8,     0,     0,     0,
       0,     9,    10,     0,     0,     0,    12,    13,     0,     0,
      15,     0,    53,    17,    18,    19,    20,    21,     0,     0,
       0,     0,     3,     4,     0,     0,     0,     5,     0,     6,
       0,     8,     0,     0,     0,     0,     9,    10,     0,     0,
       0,    12,    13,     0,     0,    15,     0,   136,    17,    18,
      19,    20,    21,     0,     0,     2,     0,     0,     3,     4,
       0,     0,     0,     5,     0,     6,     7,     8,     0,     0,
       0,     0,     9,    10,    11,     0,     0,    12,    13,     0,
      14,    15,   234,    16,    17,    18,    19,    20,    21,     0,
       0,     0,     0,     0,     0,     2,    22,     0,     3,     4,
     272,   259,   169,     5,     0,     6,     7,     8,     0,     0,
       0,     0,     9,    10,    11,     0,     0,    12,    13,     0,
      14,    15,     0,    16,    17,    18,    19,    20,    21,   267,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,   330,     0,     3,     4,     0,     0,     0,     5,     0,
       6,     7,     8,     0,     0,     0,     0,     9,    10,    11,
       0,     0,    12,    13,     0,    14,    15,     0,    16,    17,
      18,    19,    20,    21,     2,     0,     0,     3,     4,     0,
       0,     0,     5,     0,     6,     7,     8,     0,     0,     0,
       0,     9,    10,    11,     0,     0,    12,    13,     0,    14,
      15,     0,    16,    17,    18,    19,    20,    21,     3,     4,
       0,     0,     0,     5,     0,     6,     0,     8,     0,     0,
       0,     0,     9,    10,     0,     0,     0,    12,    13,     0,
       0,    15,     0,     0,    17,    18,    19,    20,    21
};

static const yytype_int16 yycheck[] =
{
      59,    59,   128,   171,    77,    58,    72,     5,    47,    76,
      88,     5,   148,    80,     5,   245,     5,    17,    79,    33,
       0,    75,   101,     0,    68,    79,     5,   163,    23,    79,
      25,    92,    22,    34,   101,     5,    80,    96,    97,    98,
      99,   100,    92,    82,   103,   104,   105,   106,    62,    26,
      27,    79,    42,    75,    31,    35,    70,    79,    35,     5,
      55,   134,   128,    79,    92,   124,   124,     7,     8,     9,
      14,    15,    70,   152,    90,    70,    74,    57,    91,   138,
     138,    58,    70,    71,    79,    74,   145,   145,    88,     5,
     320,    70,    90,    88,    74,    74,    84,    91,    88,   178,
      91,    79,   181,   239,    74,   273,    76,   243,   186,    91,
     169,   169,    90,    79,   181,    12,    13,   196,    10,    11,
     256,   257,   161,    89,    70,   201,   202,    70,    74,   195,
      76,    74,    92,    76,    74,    69,    76,   216,    78,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   247,   124,
     171,   250,   251,   168,    79,   301,    79,    75,   168,   238,
     238,   317,   162,   138,     5,    90,   252,    90,    85,    86,
     145,   168,    74,    22,    76,    51,   186,    75,   175,    99,
     100,    79,    32,   103,   104,   105,   106,   266,   266,   345,
     346,   347,   265,    42,   169,    69,   275,    47,   354,    75,
      76,    77,    51,    75,    80,   361,   362,    57,    75,    75,
      75,    79,    79,    79,    79,   301,   203,   204,     4,     5,
       6,   236,     8,     9,    74,   101,    75,    76,    77,    70,
      75,    80,    75,    74,    79,    83,    79,   205,   206,   207,
     208,    74,    73,    76,   343,   344,    16,    74,    89,    76,
      87,   337,   101,    77,    77,   255,    79,    89,   134,    89,
     339,   339,   272,   238,   209,   210,    74,    53,   265,   161,
     162,    90,    90,    89,     5,   272,    74,    74,   198,   199,
     200,    74,    68,     5,    70,   134,    75,     5,    74,     5,
      89,   266,    63,    75,    80,    81,    82,    83,    90,    75,
      77,    75,    74,    38,    90,   181,    75,    90,   211,    77,
       4,     5,     6,   212,     8,     9,   213,    70,   214,    75,
     215,   236,    63,   125,   175,   181,    35,    -1,    -1,     4,
       5,     6,   181,     8,     9,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    39,    40,    41,    42,    43,
      44,    -1,    46,    47,    48,   275,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    -1,    -1,    -1,    68,    -1,    70,    -1,    53,    -1,
      74,    -1,    -1,    -1,    -1,    -1,    80,    81,    82,    83,
      -1,    -1,    -1,    68,    -1,    70,    90,    91,    92,    74,
      -1,    -1,    -1,    -1,    -1,    80,    81,    82,    83,     4,
       5,     6,    -1,     8,     9,    -1,    91,    92,    -1,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    39,    40,    41,    42,    43,    44,
      -1,    46,    47,    48,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    69,
      -1,    -1,    -1,    68,    -1,    70,     4,     5,     6,    74,
       8,     9,    -1,    -1,    -1,    80,    81,    82,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    90,    91,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    -1,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    42,    43,    44,    -1,    -1,     4,
       5,     6,    50,     8,     9,    53,    -1,    -1,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      68,    -1,    70,     4,     5,     6,    74,     8,     9,    -1,
      -1,    -1,    80,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    90,    91,    -1,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    70,    -1,    -1,    -1,    74,
      -1,    -1,    53,    -1,    -1,    80,    81,    82,    83,     4,
       5,     6,    -1,     8,     9,    -1,    91,    68,    -1,    70,
      -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,    32,    33,    90,
      -1,    -1,    37,    -1,    39,    -1,    41,    -1,    -1,    -1,
      -1,    46,    47,    -1,    -1,    -1,    51,    52,    53,    -1,
      55,    -1,    -1,    58,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    70,     4,     5,     6,    74,
       8,     9,    -1,    -1,    -1,    80,    81,    82,    83,    -1,
      -1,    -1,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    53,    70,    -1,    -1,    -1,    74,    -1,    -1,    77,
      -1,    -1,    80,    81,    82,    83,    68,    53,    70,     4,
       5,     6,    74,     8,     9,    77,    -1,    -1,    80,    81,
      82,    83,    68,    -1,    70,    53,    -1,    -1,    74,    75,
      -1,    -1,    -1,    -1,    80,    81,    82,    83,    -1,    -1,
      68,    -1,    70,     4,     5,     6,    74,     8,     9,    77,
      -1,    -1,    80,    81,    82,    83,    -1,    -1,    53,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    70,    -1,    -1,    -1,    74,
      75,    -1,    -1,    -1,    -1,    80,    81,    82,    83,    -1,
      -1,    -1,    53,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    53,    70,
      -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,    80,
      81,    82,    83,    68,    -1,    70,    -1,    -1,    -1,    74,
      -1,    -1,    -1,    -1,    -1,    80,    81,    82,    83,    -1,
      -1,    -1,    53,    -1,     0,    -1,    -1,    -1,    -1,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    70,
      -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,    80,
      81,    82,    83,    29,    -1,    -1,    32,    33,    -1,    -1,
      -1,    37,    -1,    39,    40,    41,    -1,    -1,     5,    -1,
      46,    47,    48,    -1,    -1,    51,    52,    -1,    54,    55,
      -1,    57,    58,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    -1,    29,    -1,    70,    32,    33,    -1,    74,    -1,
      37,    -1,    39,    40,    41,    -1,    -1,    -1,     5,    46,
      47,    48,    -1,    -1,    51,    52,    -1,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    70,    -1,    32,    33,    74,    75,    76,
      37,    -1,    39,    40,    41,     5,    -1,    -1,    -1,    46,
      47,    48,    -1,    -1,    51,    52,    -1,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,    -1,    -1,    -1,    29,
      -1,    -1,    32,    33,    -1,    -1,    -1,    37,    75,    39,
      40,    41,    -1,    -1,    -1,    -1,    46,    47,    48,    -1,
      -1,    51,    52,    -1,    54,    55,    -1,    57,    58,    59,
      60,    61,    62,    -1,    -1,    29,    -1,    -1,    32,    33,
      70,    -1,    -1,    37,    74,    39,    40,    41,    -1,    -1,
      -1,    -1,    46,    47,    48,    -1,    -1,    51,    52,    -1,
      54,    55,    -1,    57,    58,    59,    60,    61,    62,    -1,
      29,    -1,    -1,    32,    33,    69,    -1,    -1,    37,    -1,
      39,    40,    41,    -1,    -1,    -1,    -1,    46,    47,    48,
      -1,    -1,    51,    52,    -1,    54,    55,    91,    57,    58,
      59,    60,    61,    62,    -1,    -1,    -1,    32,    33,    -1,
      -1,    -1,    37,    -1,    39,    -1,    41,    -1,    -1,    -1,
      -1,    46,    47,    -1,    -1,    -1,    51,    52,    -1,    -1,
      55,    -1,    91,    58,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    32,    33,    -1,    -1,    -1,    37,    -1,    39,
      -1,    41,    -1,    -1,    -1,    -1,    46,    47,    -1,    -1,
      -1,    51,    52,    -1,    -1,    55,    -1,    92,    58,    59,
      60,    61,    62,    -1,    -1,    29,    -1,    -1,    32,    33,
      -1,    -1,    -1,    37,    -1,    39,    40,    41,    -1,    -1,
      -1,    -1,    46,    47,    48,    -1,    -1,    51,    52,    -1,
      54,    55,    92,    57,    58,    59,    60,    61,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    70,    -1,    32,    33,
      74,    75,    76,    37,    -1,    39,    40,    41,    -1,    -1,
      -1,    -1,    46,    47,    48,    -1,    -1,    51,    52,    -1,
      54,    55,    -1,    57,    58,    59,    60,    61,    62,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    75,    -1,    32,    33,    -1,    -1,    -1,    37,    -1,
      39,    40,    41,    -1,    -1,    -1,    -1,    46,    47,    48,
      -1,    -1,    51,    52,    -1,    54,    55,    -1,    57,    58,
      59,    60,    61,    62,    29,    -1,    -1,    32,    33,    -1,
      -1,    -1,    37,    -1,    39,    40,    41,    -1,    -1,    -1,
      -1,    46,    47,    48,    -1,    -1,    51,    52,    -1,    54,
      55,    -1,    57,    58,    59,    60,    61,    62,    32,    33,
      -1,    -1,    -1,    37,    -1,    39,    -1,    41,    -1,    -1,
      -1,    -1,    46,    47,    -1,    -1,    -1,    51,    52,    -1,
      -1,    55,    -1,    -1,    58,    59,    60,    61,    62
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
       5,    91,   115,    91,   114,   115,   146,   149,    74,    76,
     132,     0,   156,    91,     5,   128,   129,   130,   133,    75,
      79,    90,    69,   146,   149,    91,   119,   122,   123,   124,
     130,    92,   147,   131,   114,   146,     5,    75,   115,   135,
     136,   137,   138,     4,     5,     6,     8,     9,    53,    68,
      70,    74,    77,    80,    81,    82,    83,    94,    95,    97,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   113,   128,    69,    79,    92,   117,    91,    97,
     110,   111,   142,   146,   122,   124,    92,   123,    89,   125,
     126,   131,   124,     5,    30,    31,    34,    35,    36,    42,
      43,    44,    50,    56,    63,    90,   111,   112,   144,   145,
     146,   148,   149,   150,   151,   152,   153,   154,    74,    76,
     131,   133,   140,   141,    75,    79,    75,    79,    74,    97,
      97,    74,    97,    99,    99,   112,   124,   139,    99,    99,
      99,    99,     7,     8,     9,    74,    76,    78,    70,    71,
      84,    68,    80,    10,    11,    12,    13,    85,    86,    14,
      15,    83,    73,    87,    16,    17,    88,    77,    92,   113,
     129,   142,   143,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    69,    92,   113,    79,    90,    89,    89,
      90,   113,    90,    89,   144,    74,     5,    74,    90,   112,
      74,    74,    79,    90,    92,   149,   150,   150,   144,    75,
     135,   140,    77,   113,   141,    74,    76,    18,   137,     5,
     139,    75,    74,   133,   140,    75,     5,    75,    96,   111,
     112,     5,    99,    99,    99,   100,   100,   101,   101,   102,
     102,   102,   102,   103,   103,   104,   105,   106,   107,   108,
     112,    79,    92,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   126,   113,   144,    89,   144,    63,
     151,    90,   112,    90,   112,   112,   111,    75,    75,    77,
      75,   135,    77,   113,    75,    99,    75,    79,    77,    89,
      92,   142,   144,    74,   151,    75,    75,    75,    75,    77,
      98,   111,   110,   112,    75,   112,   144,   144,   144,    75,
     144,    75,    38,    90,   144,   144
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    93,    94,    94,    94,    94,    95,    95,    95,    95,
      95,    95,    95,    95,    96,    96,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    98,    97,    99,    99,
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
     145,   145,   146,   147,   146,   148,   148,   148,   148,   148,
     149,   149,   150,   150,   151,   151,   152,   152,   152,   153,
     153,   153,   153,   154,   154,   154,   154,   154,   155,   155,
     156,   156,   157,   157,   157,   157
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     3,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     0,     5,     1,     4,
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
       4,     3,     2,     0,     4,     1,     1,     2,     2,     2,
       1,     2,     1,     2,     1,     2,     5,     7,     5,     5,
       7,     6,     7,     3,     2,     2,     2,     3,     1,     2,
       1,     1,     4,     3,     3,     2
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
#line 67 "myParser.y" /* yacc.c:1646  */
    {
			if(containsSymbol(currentTable, (yyvsp[0].stringBuff)))
				(yyval.num.intBuff) = getSymbolValue(currentTable, (yyvsp[0].stringBuff));
			else
				yyerror("Symbol not found\n");
			}
#line 1812 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 74 "myParser.y" /* yacc.c:1646  */
    {yyerror("Strings not supported.");}
#line 1818 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 75 "myParser.y" /* yacc.c:1646  */
    {}
#line 1824 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 95 "myParser.y" /* yacc.c:1646  */
    {}
#line 1830 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 96 "myParser.y" /* yacc.c:1646  */
    { (yyval.num.intBuff) = -(yyvsp[0].num.intBuff); }
#line 1836 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 97 "myParser.y" /* yacc.c:1646  */
    { (yyval.num.intBuff) = (yyvsp[0].num.intBuff);  printf("exprval=%lld\n",(yyval.num.intBuff)); }
#line 1842 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 98 "myParser.y" /* yacc.c:1646  */
    { (yyval.num.intBuff) = !(yyvsp[0].num.intBuff); }
#line 1848 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 99 "myParser.y" /* yacc.c:1646  */
    { (yyval.num.intBuff) = ~(yyvsp[0].num.intBuff); }
#line 1854 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 100 "myParser.y" /* yacc.c:1646  */
    { (yyval.num.intBuff) = (long long) &(yyvsp[0].num.intBuff); }
#line 1860 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 101 "myParser.y" /* yacc.c:1646  */
    { (yyval.num.intBuff) = (yyvsp[0].num.intBuff); }
#line 1866 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 102 "myParser.y" /* yacc.c:1646  */
    { (yyval.num.intBuff) = ++(yyvsp[0].num.intBuff); }
#line 1872 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 103 "myParser.y" /* yacc.c:1646  */
    { (yyval.num.intBuff) = --(yyvsp[0].num.intBuff); }
#line 1878 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 104 "myParser.y" /* yacc.c:1646  */
    {}
#line 1884 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 105 "myParser.y" /* yacc.c:1646  */
    {}
#line 1890 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 105 "myParser.y" /* yacc.c:1646  */
    { (yyval.num.intBuff) = sizeof(long long); }
#line 1896 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 118 "myParser.y" /* yacc.c:1646  */
    {}
#line 1902 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 119 "myParser.y" /* yacc.c:1646  */
    {}
#line 1908 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 130 "myParser.y" /* yacc.c:1646  */
    {}
#line 1914 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 171 "myParser.y" /* yacc.c:1646  */
    {}
#line 1920 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 186 "myParser.y" /* yacc.c:1646  */
    {}
#line 1926 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 187 "myParser.y" /* yacc.c:1646  */
    { (yyval.num.intBuff) = (yyvsp[0].num.intBuff);printf( "exprval=%lld\n", (yyval.num.intBuff)); }
#line 1932 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 188 "myParser.y" /* yacc.c:1646  */
    {(yyval.num.intBuff) = (yyvsp[-2].num.intBuff) + (yyvsp[0].num.intBuff);(yyvsp[-2].num.intBuff) = (yyval.num.intBuff); }
#line 1938 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 189 "myParser.y" /* yacc.c:1646  */
    { (yyval.num.intBuff) = (yyvsp[-2].num.intBuff) - (yyvsp[0].num.intBuff);(yyvsp[-2].num.intBuff) = (yyval.num.intBuff);}
#line 1944 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 190 "myParser.y" /* yacc.c:1646  */
    { (yyval.num.intBuff) = (yyvsp[-2].num.intBuff) * (yyvsp[0].num.intBuff);(yyvsp[-2].num.intBuff) = (yyval.num.intBuff); }
#line 1950 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 191 "myParser.y" /* yacc.c:1646  */
    { (yyval.num.intBuff) = (yyvsp[-2].num.intBuff) / (yyvsp[0].num.intBuff);(yyvsp[-2].num.intBuff) = (yyval.num.intBuff); }
#line 1956 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 192 "myParser.y" /* yacc.c:1646  */
    { (yyval.num.intBuff) = (yyvsp[-2].num.intBuff) % (yyvsp[0].num.intBuff);(yyvsp[-2].num.intBuff) = (yyval.num.intBuff); }
#line 1962 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 193 "myParser.y" /* yacc.c:1646  */
    { (yyval.num.intBuff) = (yyvsp[-2].num.intBuff) << (yyvsp[0].num.intBuff);(yyvsp[-2].num.intBuff) = (yyval.num.intBuff); }
#line 1968 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 194 "myParser.y" /* yacc.c:1646  */
    { (yyval.num.intBuff) = (yyvsp[-2].num.intBuff) >> (yyvsp[0].num.intBuff);(yyvsp[-2].num.intBuff) = (yyval.num.intBuff); }
#line 1974 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 195 "myParser.y" /* yacc.c:1646  */
    { (yyval.num.intBuff) = (yyvsp[-2].num.intBuff) & (yyvsp[0].num.intBuff);(yyvsp[-2].num.intBuff) = (yyval.num.intBuff); }
#line 1980 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 196 "myParser.y" /* yacc.c:1646  */
    { (yyval.num.intBuff) = (yyvsp[-2].num.intBuff) | (yyvsp[0].num.intBuff);(yyvsp[-2].num.intBuff) = (yyval.num.intBuff); }
#line 1986 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 197 "myParser.y" /* yacc.c:1646  */
    { (yyval.num.intBuff) = (yyvsp[-2].num.intBuff) ^ (yyvsp[0].num.intBuff);(yyvsp[-2].num.intBuff) = (yyval.num.intBuff); }
#line 1992 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 335 "myParser.y" /* yacc.c:1646  */
    {
				if(!containsSymbol(currentTable, (yyvsp[0].stringBuff))) {
					installSymbol(currentTable, (yyvsp[0].stringBuff), filename, line, NUM);
				} else {
					yyerror("Redeclaration of variable");
					}
			}
#line 2004 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 380 "myParser.y" /* yacc.c:1646  */
    {printf("%s\n", "identifier list");}
#line 2010 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 409 "myParser.y" /* yacc.c:1646  */
    {}
#line 2016 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 410 "myParser.y" /* yacc.c:1646  */
    {}
#line 2022 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 435 "myParser.y" /* yacc.c:1646  */
    {
				if(currentTable->scope == GLOBAL_SCOPE) {
					currentTable = enterScope(FUNCTION_SCOPE, line, filename, currentTable);
				} else {
					currentTable = enterScope(BLOCK_SCOPE, line, filename, currentTable);
				}
			}
#line 2034 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 442 "myParser.y" /* yacc.c:1646  */
    {currentTable = leaveScope(currentTable, 0);}
#line 2040 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 495 "myParser.y" /* yacc.c:1646  */
    {printf("Left function!\n");}
#line 2046 "myParser.tab.c" /* yacc.c:1646  */
    break;


#line 2050 "myParser.tab.c" /* yacc.c:1646  */
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
#line 506 "myParser.y" /* yacc.c:1906  */


void yyerror(const char* s) {
	fprintf(stderr, "Error: %s\n", s);
}

int main() {
	printf("[Parser Begin]\n");
	strcpy(filename, "Placeholder.c");
	currentTable = enterScope(GLOBAL_SCOPE, 0, "TestFileName.c", NULL);
	yyparse();
}

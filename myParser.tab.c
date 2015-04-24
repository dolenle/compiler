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

char currentSym[128]; //probably not the proper way to do this

#line 86 "myParser.tab.c" /* yacc.c:339  */

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
#line 23 "myParser.y" /* yacc.c:355  */

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
		} typeFlag;
		enum signtype {
			SIGNED_T,
			UNSIGNED_T
		} signFlag;
	} num;

#line 216 "myParser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MYPARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 233 "myParser.tab.c" /* yacc.c:358  */

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
#define YYLAST   1524

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  93
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  213
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  351

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
       0,    69,    69,    78,    87,    88,    92,    93,    94,    95,
      96,    97,    98,    99,   103,   104,   108,   117,   118,   119,
     120,   121,   121,   125,   126,   127,   128,   129,   130,   134,
     135,   139,   140,   141,   142,   146,   147,   148,   152,   153,
     154,   158,   159,   160,   161,   162,   166,   167,   168,   172,
     173,   177,   178,   182,   183,   187,   188,   192,   193,   197,
     198,   202,   216,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   234,   235,   239,   243,   244,   248,
     249,   250,   251,   252,   253,   257,   258,   262,   263,   267,
     268,   269,   270,   271,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   290,   291,   292,   296,
     297,   301,   302,   306,   310,   311,   312,   313,   317,   318,
     322,   323,   324,   328,   329,   330,   334,   335,   339,   340,
     344,   345,   349,   350,   354,   361,   362,   363,   364,   365,
     366,   370,   371,   372,   373,   377,   378,   383,   384,   388,
     389,   393,   394,   395,   399,   400,   404,   405,   409,   410,
     411,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     427,   428,   429,   433,   434,   438,   439,   440,   441,   442,
     443,   447,   448,   449,   453,   454,   455,   456,   482,   483,
     487,   488,   492,   493,   497,   498,   499,   503,   504,   505,
     506,   510,   511,   512,   513,   514,   518,   519,   523,   524,
     528,   529,   530,   531
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
  "')'", "'['", "']'", "'.'", "','", "'&'", "'-'", "'~'", "'!'", "'%'",
  "'<'", "'>'", "'|'", "'?'", "':'", "';'", "'{'", "'}'", "$accept",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "$@1", "unary_operator", "cast_expression",
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
  "function_definition", YY_NULLPTR
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

#define YYPACT_NINF -193

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-193)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1136,  -193,  -193,  -193,  -193,  -193,     1,  -193,  -193,  -193,
    -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,
    -193,  -193,   -10,     9,  -193,     8,  1431,  1431,  -193,     6,
    -193,  1431,  1207,   125,    19,  1020,  -193,  -193,   -53,    40,
    -193,  -193,   -10,   -22,  -193,   -33,  -193,  1172,  -193,  -193,
      31,  1462,  -193,   286,  -193,     8,  -193,  1207,  1099,   798,
     125,  -193,  -193,    40,    12,   -15,  -193,  -193,  -193,  -193,
       9,  -193,   627,  -193,  1207,  1462,  1462,  1241,  -193,    29,
    1462,  -193,    38,  -193,   931,   931,    60,   947,    93,    55,
     584,   112,   207,   143,   651,   965,   156,   159,  -193,  -193,
     731,  -193,  -193,  -193,  -193,  -193,  -193,  -193,    61,   201,
     947,  -193,    -9,    -1,    94,     5,   238,   193,   175,   187,
     259,    24,  -193,  -193,    57,  -193,  -193,  -193,   353,   420,
    -193,  -193,  -193,  -193,   208,  -193,  -193,  -193,  -193,    54,
     203,   197,  -193,    27,  -193,  -193,  -193,  -193,   202,    -6,
     947,    40,  -193,  -193,   627,  -193,  -193,  -193,  1276,  -193,
    -193,  -193,   947,    97,  -193,   191,  -193,   584,   947,  -193,
    -193,  -193,   192,  -193,   584,   219,   677,   194,   947,  -193,
      98,   731,  -193,   947,   947,    66,    72,   210,   278,  -193,
    -193,   814,   947,   281,  -193,  -193,  -193,  -193,  -193,  -193,
    -193,  -193,  -193,  -193,  -193,   947,  -193,   947,   947,   947,
     947,   947,   947,   947,   947,   947,   947,   947,   947,   947,
     947,   947,   947,   947,   947,   947,   947,  -193,  -193,   487,
    -193,  -193,  1059,   830,  -193,    39,  -193,   128,  -193,  1397,
    -193,   283,  -193,  -193,  -193,  -193,  -193,    59,  -193,  -193,
      29,  -193,   947,  -193,   584,  -193,   222,   677,  -193,   106,
    -193,   218,   114,   116,  -193,  1312,   167,  -193,   947,  -193,
    -193,   121,  -193,   168,  -193,  -193,  -193,  -193,  -193,    -9,
      -9,    -1,    -1,    94,    94,    94,    94,     5,     5,   238,
     193,   175,   187,   259,   -42,  -193,  -193,  -193,   223,   224,
    -193,   220,   128,  1352,   848,  -193,  -193,  -193,   530,  -193,
    -193,  -193,  -193,   947,   915,   584,  -193,   584,   584,  -193,
    -193,   947,  -193,   947,  -193,  -193,  -193,  -193,   226,  -193,
     225,  -193,  -193,   135,   584,   165,   266,  -193,  -193,  -193,
    -193,  -193,  -193,  -193,   215,  -193,   584,   584,  -193,  -193,
    -193
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   134,    92,    95,   130,   100,     0,    90,    99,    97,
      98,    93,    96,   101,    91,   109,    89,   105,   110,   102,
      94,   131,   141,     0,   209,     0,    79,    81,   103,     0,
     104,    83,     0,   133,     0,     0,   206,   208,   125,     0,
     145,   143,   142,     0,    77,     0,    85,    87,    80,    82,
     108,     0,    84,     0,   188,     0,   213,     0,     0,     0,
     132,     1,   207,     0,   128,     0,   126,   146,   144,   135,
       0,    78,     0,   211,     0,     0,   115,     0,   111,     0,
     117,     4,     2,     3,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    25,    24,
       0,    23,    26,    27,    28,   192,   184,     6,    16,    29,
       0,    31,    35,    38,    41,    46,    49,    51,    53,    55,
      57,    59,    61,    74,     0,   190,   175,   176,     0,     0,
     177,   178,   179,   180,    87,   189,   212,   154,   140,   153,
       0,   147,   149,     0,     2,   137,    29,    76,     0,     0,
       0,     0,   123,    86,     0,   170,    88,   210,     0,   114,
     107,   112,     0,     0,   118,   120,   116,     0,     0,    18,
      19,   203,     0,   202,     0,     0,     0,     0,     0,   204,
       0,     0,    20,     0,     0,     0,   156,     0,     0,    12,
      13,     0,     0,     0,    64,    65,    66,    67,    68,    69,
      70,    71,    73,    72,    63,     0,    17,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   193,   186,     0,
     185,   191,     0,     0,   151,   158,   152,   159,   138,     0,
     139,     0,   136,   124,   129,   127,   173,     0,   106,   121,
       0,   113,     0,   181,     0,   183,     0,     0,   201,     0,
     205,     0,     0,     0,     5,     0,   158,   157,     0,    11,
       8,     0,    14,     0,    10,    62,    32,    33,    34,    36,
      37,    39,    40,    44,    45,    42,    43,    47,    48,    50,
      52,    54,    56,    58,     0,    75,   187,   166,     0,     0,
     162,     0,   160,     0,     0,   148,   150,   155,     0,   171,
     119,   122,   182,     0,     0,     0,    21,     0,     0,    30,
       9,     0,     7,     0,   167,   161,   163,   168,     0,   164,
       0,   172,   174,     0,     0,     0,   194,    22,   196,   197,
      15,    60,   169,   165,     0,   199,     0,     0,   198,   200,
     195
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -193,  -193,  -193,  -193,   -55,  -193,  -193,   -88,    49,    51,
      41,    53,    86,    87,    85,    88,    89,  -193,   -54,   -21,
    -193,   -52,   -62,    15,     0,  -193,   239,  -193,   131,  -193,
    -193,   235,   -74,   -64,  -193,    64,  -193,   261,   180,    34,
     -16,   -32,   -14,  -193,   -57,  -193,    96,  -193,   169,  -120,
    -192,  -133,  -193,   -80,  -193,   162,    18,   227,  -156,  -193,
    -193,  -193,  -193,   316,  -193
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   107,   108,   271,   109,   337,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     205,   124,   148,    54,    55,    45,    46,    26,    27,    28,
      29,    77,    78,    79,   163,   164,    30,    65,    66,    31,
      32,    33,    34,    42,   298,   141,   142,   143,   187,   299,
     237,   156,   247,   125,   126,   127,    57,   129,   130,   131,
     132,   133,    35,    36,    37
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      25,   140,    60,   161,   146,   147,    38,    43,    41,    47,
     175,    50,   159,     1,     1,    24,   166,   214,   215,   236,
     257,   246,   206,     4,     1,   172,    48,    49,    68,   169,
     170,    52,   146,   147,     1,    25,   186,   226,    63,   134,
     182,   224,   180,   302,     1,    64,    70,   323,   185,   231,
      24,   155,    21,    69,   134,   146,    40,    71,   139,     1,
      22,   207,   208,   165,   151,    74,   267,   210,   188,   189,
     190,   128,   135,   151,   302,   209,    67,   152,    22,    22,
     211,   150,    23,    23,   161,    80,   243,   253,   244,   135,
     216,   217,    39,    23,   255,   146,   147,    51,    44,    22,
     249,   314,   240,    23,   212,   213,   241,   146,   147,    80,
      80,    80,   225,   232,    80,   233,   185,   186,   162,   276,
     277,   278,    75,   234,    22,   235,   259,   167,   232,   185,
     233,   262,   263,   155,    80,   191,   226,   192,   308,   193,
     273,   264,    22,   135,   174,   226,   265,   227,   233,   231,
     171,   309,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     272,   301,   266,   294,   312,   332,   250,   226,   146,   147,
     319,   315,    76,   173,   275,   226,   176,   251,   260,   317,
     311,   318,    80,   226,    56,   226,   320,   146,   147,    58,
     321,    59,   303,    60,   304,   295,    76,    76,    76,    73,
     344,    76,   177,   146,   226,    80,    43,   178,   235,   136,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     183,    76,   139,   184,   165,   336,   157,   338,   339,   139,
     346,   265,   330,   233,   226,   322,   328,   226,   221,   146,
     147,   266,   218,   219,   345,   283,   284,   285,   286,   279,
     280,   333,   335,   281,   282,   139,   349,   350,   146,   341,
     204,   287,   288,   220,   222,   223,   239,    72,   238,   242,
     252,   254,   256,   269,   258,   268,   274,   155,   307,    76,
      81,    82,    83,   316,    84,    85,   313,   326,   324,   325,
     340,   342,   343,   139,   347,   348,   289,   291,   290,   153,
     158,   292,    76,   293,   310,     2,    86,    87,     3,     4,
      88,    89,    90,     5,   149,     6,     7,     8,    91,    92,
      93,   245,     9,    10,    11,   306,    94,    12,    13,    95,
      14,    15,    96,    16,    17,    18,    19,    20,    21,    97,
     261,    62,     0,     0,    98,   229,    99,    81,    82,    83,
     100,    84,    85,     0,     0,     0,   101,   102,   103,   104,
       0,     0,     0,     0,     0,     0,   105,    53,   106,     0,
       0,     0,     2,    86,    87,     3,     4,    88,    89,    90,
       5,     0,     6,     7,     8,    91,    92,    93,     0,     9,
      10,    11,     0,    94,    12,    13,    95,    14,    15,    96,
      16,    17,    18,    19,    20,    21,    97,     0,     0,     0,
       0,    98,     0,    99,    81,    82,    83,   100,    84,    85,
       0,     0,     0,   101,   102,   103,   104,     0,     0,     0,
       0,     0,     0,   105,    53,   228,     0,     0,     0,     0,
      86,    87,     0,     0,    88,    89,    90,     0,     0,     0,
       0,     0,    91,    92,    93,     0,     0,     0,     0,     0,
      94,     0,     0,    95,     0,     0,    96,     0,     0,     0,
       0,     0,     0,    97,     0,     0,     0,     0,    98,     0,
      99,    81,    82,    83,   100,    84,    85,     0,     0,     0,
     101,   102,   103,   104,     0,     0,     0,     0,     0,     0,
     105,    53,   230,     0,     0,     0,     0,    86,    87,     0,
       0,    88,    89,    90,     0,     0,     0,     0,     0,    91,
      92,    93,     0,     0,    81,   144,    83,    94,    84,    85,
      95,     0,     0,    96,     0,     0,     0,     0,     0,     0,
      97,     0,     0,     0,     0,    98,     0,    99,     0,     0,
       0,   100,     0,     0,     0,     0,     0,   101,   102,   103,
     104,     0,     0,     0,     0,     0,     0,   105,    53,   296,
       0,     0,     0,    95,     0,     0,     0,     0,    81,    82,
      83,     0,    84,    85,     0,     0,     0,     0,    98,     0,
      99,     0,     0,     0,   100,     0,     0,     0,     0,     0,
     101,   102,   103,   104,    86,    87,     0,     0,    88,    89,
      90,   154,   331,     0,     0,     0,    91,    92,    93,     0,
       0,    81,   144,    83,    94,    84,    85,    95,     0,     0,
      96,     0,     0,     0,     0,     0,     0,    97,     0,     0,
       0,     0,    98,     0,    99,    81,   144,    83,   100,    84,
      85,     0,     0,     0,   101,   102,   103,   104,     0,     0,
       0,     0,     0,     0,   105,    53,     0,     0,     0,     0,
      95,    81,   144,    83,     0,    84,    85,     0,     0,     0,
       0,     0,     0,     0,     0,    98,     0,    99,     0,     0,
       0,   100,     0,     0,    95,     0,     0,   101,   102,   103,
     104,     0,     0,     0,     0,     0,     0,     0,   154,    98,
       0,    99,     0,     0,     0,   100,     0,     0,     0,     0,
      95,   101,   102,   103,   104,    81,   144,    83,     0,    84,
      85,   179,     0,     0,     0,    98,     0,    99,     0,     0,
       0,   100,     0,     0,     0,     0,     0,   101,   102,   103,
     104,     0,     0,     3,     4,     0,     0,   105,     5,     0,
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
       0,    58,    34,    77,    59,    59,     5,    23,    22,    25,
      90,     5,    76,     5,     5,     0,    80,    12,    13,   139,
     176,   154,   110,    33,     5,    87,    26,    27,    42,    84,
      85,    31,    87,    87,     5,    35,   100,    79,    91,    55,
      95,    17,    94,   235,     5,     5,    79,    89,   100,   129,
      35,    72,    62,    75,    70,   110,    22,    90,    58,     5,
      70,    70,    71,    79,    79,    47,   186,    68,     7,     8,
       9,    53,    57,    79,   266,    84,    42,    92,    70,    70,
      81,    69,    74,    74,   158,    51,    92,   167,   150,    74,
      85,    86,    91,    74,   174,   150,   150,    91,    90,    70,
     162,   257,    75,    74,    10,    11,    79,   162,   162,    75,
      76,    77,    88,    74,    80,    76,   168,   181,    89,   207,
     208,   209,    91,   139,    70,   139,   178,    89,    74,   181,
      76,   183,   184,   154,   100,    74,    79,    76,    79,    78,
     192,    75,    70,   128,    89,    79,    74,    90,    76,   229,
      90,    92,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     191,   233,   186,   225,   254,   308,    79,    79,   233,   233,
     268,    75,    51,    90,   205,    79,    74,    90,    90,    75,
     252,    75,   158,    79,    32,    79,    75,   252,   252,    74,
      79,    76,    74,   235,    76,   226,    75,    76,    77,    47,
      75,    80,     5,   268,    79,   181,   232,    74,   232,    57,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      74,   100,   232,    74,   250,   315,    74,   317,   318,   239,
      75,    74,   304,    76,    79,    77,   303,    79,    73,   304,
     304,   265,    14,    15,   334,   214,   215,   216,   217,   210,
     211,   313,   314,   212,   213,   265,   346,   347,   323,   323,
      69,   218,   219,    80,    87,    16,    79,    69,    75,    77,
      89,    89,    63,     5,    90,    75,     5,   308,     5,   158,
       4,     5,     6,    75,     8,     9,    74,    77,    75,    75,
     321,    75,    77,   303,    38,    90,   220,   222,   221,    70,
      75,   223,   181,   224,   250,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    63,    39,    40,    41,    42,    43,
      44,   151,    46,    47,    48,   239,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
     181,    35,    -1,    -1,    68,   128,    70,     4,     5,     6,
      74,     8,     9,    -1,    -1,    -1,    80,    81,    82,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    92,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    39,    40,    41,    42,    43,    44,    -1,    46,
      47,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    -1,    -1,
      -1,    68,    -1,    70,     4,     5,     6,    74,     8,     9,
      -1,    -1,    -1,    80,    81,    82,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    91,    92,    -1,    -1,    -1,    -1,
      30,    31,    -1,    -1,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,
      50,    -1,    -1,    53,    -1,    -1,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    68,    -1,
      70,     4,     5,     6,    74,     8,     9,    -1,    -1,    -1,
      80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      90,    91,    92,    -1,    -1,    -1,    -1,    30,    31,    -1,
      -1,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    42,
      43,    44,    -1,    -1,     4,     5,     6,    50,     8,     9,
      53,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    68,    -1,    70,    -1,    -1,
      -1,    74,    -1,    -1,    -1,    -1,    -1,    80,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    92,
      -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    -1,    68,    -1,
      70,    -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,
      80,    81,    82,    83,    30,    31,    -1,    -1,    34,    35,
      36,    91,    92,    -1,    -1,    -1,    42,    43,    44,    -1,
      -1,     4,     5,     6,    50,     8,     9,    53,    -1,    -1,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    68,    -1,    70,     4,     5,     6,    74,     8,
       9,    -1,    -1,    -1,    80,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    91,    -1,    -1,    -1,    -1,
      53,     4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    70,    -1,    -1,
      -1,    74,    -1,    -1,    53,    -1,    -1,    80,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    68,
      -1,    70,    -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,
      53,    80,    81,    82,    83,     4,     5,     6,    -1,     8,
       9,    90,    -1,    -1,    -1,    68,    -1,    70,    -1,    -1,
      -1,    74,    -1,    -1,    -1,    -1,    -1,    80,    81,    82,
      83,    -1,    -1,    32,    33,    -1,    -1,    90,    37,    -1,
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
      61,    62,    70,    74,   116,   117,   120,   121,   122,   123,
     129,   132,   133,   134,   135,   155,   156,   157,     5,    91,
     132,   135,   136,   133,    90,   118,   119,   133,   117,   117,
       5,    91,   117,    91,   116,   117,   148,   149,    74,    76,
     134,     0,   156,    91,     5,   130,   131,   132,   135,    75,
      79,    90,    69,   148,   149,    91,   121,   124,   125,   126,
     132,     4,     5,     6,     8,     9,    30,    31,    34,    35,
      36,    42,    43,    44,    50,    53,    56,    63,    68,    70,
      74,    80,    81,    82,    83,    90,    92,    94,    95,    97,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   114,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   133,   116,   148,     5,    75,   117,
     137,   138,   139,   140,     5,    77,    97,   111,   115,   130,
      69,    79,    92,   119,    91,   112,   144,   148,   124,   126,
      92,   125,    89,   127,   128,   133,   126,    89,    74,    97,
      97,    90,   115,    90,    89,   146,    74,     5,    74,    90,
     114,    74,    97,    74,    74,   114,   126,   141,     7,     8,
       9,    74,    76,    78,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    69,   113,   100,    70,    71,    84,
      68,    81,    10,    11,    12,    13,    85,    86,    14,    15,
      80,    73,    87,    16,    17,    88,    79,    90,    92,   150,
      92,   146,    74,    76,   133,   135,   142,   143,    75,    79,
      75,    79,    77,    92,   115,   131,   144,   145,    92,   115,
      79,    90,    89,   146,    89,   146,    63,   151,    90,   114,
      90,   141,   114,   114,    75,    74,   135,   142,    75,     5,
      75,    96,   112,   114,     5,   112,   100,   100,   100,   101,
     101,   102,   102,   103,   103,   103,   103,   104,   104,   105,
     106,   107,   108,   109,   114,   112,    92,    75,   137,   142,
      77,   115,   143,    74,    76,    18,   139,     5,    79,    92,
     128,   115,   146,    74,   151,    75,    75,    75,    75,   100,
      75,    79,    77,    89,    75,    75,    77,    75,   137,    77,
     115,    92,   144,   114,    75,   114,   146,    98,   146,   146,
     112,   111,    75,    77,    75,   146,    75,    38,    90,   146,
     146
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    93,    94,    94,    94,    94,    95,    95,    95,    95,
      95,    95,    95,    95,    96,    96,    97,    97,    97,    97,
      97,    98,    97,    99,    99,    99,    99,    99,    99,   100,
     100,   101,   101,   101,   101,   102,   102,   102,   103,   103,
     103,   104,   104,   104,   104,   104,   105,   105,   105,   106,
     106,   107,   107,   108,   108,   109,   109,   110,   110,   111,
     111,   112,   112,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   114,   114,   115,   116,   116,   117,
     117,   117,   117,   117,   117,   118,   118,   119,   119,   120,
     120,   120,   120,   120,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   122,   122,   122,   123,
     123,   124,   124,   125,   126,   126,   126,   126,   127,   127,
     128,   128,   128,   129,   129,   129,   130,   130,   131,   131,
     132,   132,   133,   133,   134,   134,   134,   134,   134,   134,
     134,   135,   135,   135,   135,   136,   136,   137,   137,   138,
     138,   139,   139,   139,   140,   140,   141,   141,   142,   142,
     142,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     144,   144,   144,   145,   145,   146,   146,   146,   146,   146,
     146,   147,   147,   147,   148,   148,   148,   148,   149,   149,
     150,   150,   151,   151,   152,   152,   152,   153,   153,   153,
     153,   154,   154,   154,   154,   154,   155,   155,   156,   156,
     157,   157,   157,   157
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     3,     1,     2,     2,     2,
       2,     0,     5,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       5,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     2,     3,     1,
       2,     1,     2,     1,     2,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     4,     2,     1,
       1,     1,     2,     3,     2,     1,     2,     1,     1,     3,
       1,     2,     3,     4,     5,     2,     1,     3,     1,     3,
       1,     1,     2,     1,     1,     3,     4,     3,     4,     4,
       3,     1,     2,     2,     3,     1,     2,     1,     3,     1,
       3,     2,     2,     1,     1,     3,     1,     2,     1,     1,
       2,     3,     2,     3,     3,     4,     2,     3,     3,     4,
       1,     3,     4,     1,     3,     1,     1,     1,     1,     1,
       1,     3,     4,     3,     2,     3,     3,     4,     1,     2,
       1,     2,     1,     2,     5,     7,     5,     5,     7,     6,
       7,     3,     2,     2,     2,     3,     1,     2,     1,     1,
       4,     3,     3,     2
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
#line 69 "myParser.y" /* yacc.c:1646  */
    {
				if(containsSymbol(currentTable, (yyvsp[0].stringBuff))) {
					(yyval.num.intBuff) = getSymbolValue(currentTable, (yyvsp[0].stringBuff));
					strcpy(currentSym, (yyvsp[0].stringBuff));
					printf("exprval: %i\n",(yyval.num.intBuff));
				} else {
					yyerror("Symbol not found\n");
				}
			}
#line 1838 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 78 "myParser.y" /* yacc.c:1646  */
    {
					if (yylval.num.typeFlag == INT_T || yylval.num.typeFlag == LONG_T || yylval.num.typeFlag == LONGLONG_T)
                        (yyval.num.intBuff) = yylval.num.intBuff;
                else {
                        (yyval.num.intBuff) = (long long)yylval.num.realBuff;
                        fprintf(stderr,"Truncating real number %Lg to integer %lld\n",yylval.num.realBuff,(yyval.num.intBuff));
                        printf("exprval=%lld\n",(yyval.num.intBuff));
                }
				}
#line 1852 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 87 "myParser.y" /* yacc.c:1646  */
    {yyerror("Strings not supported.");}
#line 1858 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 88 "myParser.y" /* yacc.c:1646  */
    {}
#line 1864 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 108 "myParser.y" /* yacc.c:1646  */
    {}
#line 1870 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 118 "myParser.y" /* yacc.c:1646  */
    { (yyval.num.intBuff) = ++(yyvsp[0].num.intBuff); }
#line 1876 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 119 "myParser.y" /* yacc.c:1646  */
    { (yyval.num.intBuff) = --(yyvsp[0].num.intBuff); }
#line 1882 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 120 "myParser.y" /* yacc.c:1646  */
    {}
#line 1888 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 121 "myParser.y" /* yacc.c:1646  */
    {}
#line 1894 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 121 "myParser.y" /* yacc.c:1646  */
    { (yyval.num.intBuff) = sizeof(long long); }
#line 1900 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 134 "myParser.y" /* yacc.c:1646  */
    {}
#line 1906 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 135 "myParser.y" /* yacc.c:1646  */
    {}
#line 1912 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 146 "myParser.y" /* yacc.c:1646  */
    {}
#line 1918 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 187 "myParser.y" /* yacc.c:1646  */
    {}
#line 1924 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 202 "myParser.y" /* yacc.c:1646  */
    {}
#line 1930 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 354 "myParser.y" /* yacc.c:1646  */
    {
				if(!containsSymbol(currentTable, (yyvsp[0].stringBuff))) {
					installSymbol(currentTable, (yyvsp[0].stringBuff), filename, line, NUM);
				} else {
					yyerror("Redeclaration of variable");
					}
			}
#line 1942 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 399 "myParser.y" /* yacc.c:1646  */
    {printf("%s\n", "identifier list");}
#line 1948 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 428 "myParser.y" /* yacc.c:1646  */
    {}
#line 1954 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 429 "myParser.y" /* yacc.c:1646  */
    {}
#line 1960 "myParser.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 523 "myParser.y" /* yacc.c:1646  */
    {printf("Left function!\n");}
#line 1966 "myParser.tab.c" /* yacc.c:1646  */
    break;


#line 1970 "myParser.tab.c" /* yacc.c:1646  */
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
#line 534 "myParser.y" /* yacc.c:1906  */


void yyerror(const char* s) {
	fprintf(stderr, "Error: %s\n", s);
}

int main() {
	printf("[Parser Begin]\n");
	strcpy(filename, "Placeholder.c");
	currentTable = enterScope(GLOBAL_SCOPE, 0, "TestFileName.c", NULL);
	yyparse();
}

/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 23 "myParser.y" /* yacc.c:1909  */

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

#line 144 "myParser.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MYPARSER_TAB_H_INCLUDED  */
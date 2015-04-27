/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
/* Line 1529 of yacc.c.  */
#line 208 "myParser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;


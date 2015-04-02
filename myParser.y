%error_verbose
%debug
%{

#include "syms.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

extern int yylex();
//extern int yyparse();
int line;
char filename[4096];
char currentSym[128];

#define YYDEBUG 1
int yydebug = 0;
void yyerror(const char* s);
symbolTable* currentTable;
%}

%union {
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
}

/* BISON Declarations */

%token <charBuff> CHARLIT
%token <stringBuff> STRING IDENT
%token <num.intBuff> NUMBER
%token <noval> INDSEL PLUSPLUS MINUSMINUS SHL SHR LTEQ GTEQ EQEQ NOTEQ LOGAND LOGOR
ELLIPSIS TIMESEQ DIVEQ MODEQ PLUSEQ MINUSEQ SHLEQ SHREQ ANDEQ OREQ XOREQ AUTO BREAK
CASE CHAR CONST CONTINUE DEFAULT DO DOUBLE ELSE ENUM EXTERN FLOAT FOR GOTO IF INLINE
INT LONG REGISTER RESTRICT RETURN SHORT SIGNED SIZEOF STATIC STRUCT SWITCH TYPEDEF
TYPEDEF_NAME UNION UNSIGNED VOID VOLATILE WHILE _BOOL _COMPLEX _IMAGINARY

%left '_' '+' '='
%left '*' '/'
%left NEG     /* negation__unary minus */
%right '^'    /* exponentiation        */

%type <num.intBuff> initializer primary_expression unary_expression cast_expression
shift_expression relational_expression equality_expression bit_or_expression 
bit_xor_expression bit_and_expression logical_or_expression logical_and_expression
additive_expression assignment_expression expression

%start translation_unit;


%%

translation_unit: 
	  declaration
	| translation_unit declaration
	;

declaration:
	  declaration_specifier initialized_declarator_list ';'
	;

initialized_declarator_list:
	  initialized_declarator
	| initialized_declarator_list ',' initialized_declarator
	;

initialized_declarator:
	  declarator
	| declarator '=' initializer	{
										if(setSymbolValue(currentTable, currentSym, $3) == -1)
											printf("Error - symbol not found\n");
										else
											printf("Symbol value set\n");
									}							
	;

declaration_specifier:
	  type_specifier
	| type_specifier declaration_specifier
	;

type_specifier:
	  INT
	;

declarator:
	  direct_declarator
	;

direct_declarator:
	  simple_declarator
	| '(' declarator ')'
	| function_declarator
	| array_declarator
	;

initializer:
	  assignment_expression
	/*| NUMBER {$$=yylval.num.intBuff;}*/
	;
	
function_declarator:
	  direct_declarator '(' ')' {printf("function!");}
	/*| direct_declarator '(' parameter_type_list ')'*/
	/*| direct_declarator '(' identifier_list ')'*/
	;

array_declarator:
	  direct_declarator '[' ']'	{printf("Arrays not supported.\n");}
	/*| direct_declarator '[' constant_expression ']'*/
	;

simple_declarator:
	  identifier 
	;

identifier:
	IDENT {installSymbol(currentTable, $1, filename, line, NUM); strcpy(currentSym, $1);}
	;

/*
 *		EXPRESSION GRAMMAR
 */
 
primary_expression:
	  identifier
	| NUMBER
	| '(' expression ')'
	;

cast_expression:
	  unary_expression
	| '(' type_name ')' cast_expression {$$ = (int)$4; } 
	;

postfix_expression:
	  primary_expression
	| postfix_expression PLUSPLUS
	| postfix_expression MINUSMINUS
	;

unary_expression:
	  postfix_expression
	| SIZEOF '(' type_name ')' { $$ = sizeof(long long); }
	| SIZEOF '(' unary_expression ')' {  }
	| '-' cast_expression { $$ = -$2; }
	| '+' cast_expression { $$ = $2;  printf("exprval=%lld\n",$$); }
	| '!' cast_expression { $$ = !$2; }
	| '~' cast_expression { $$ = ~$2; }
	| '&' cast_expression { $$ = (long long) &$2; }
	| '*' cast_expression { $$ = $2; }
	| PLUSPLUS unary_expression { $$ = ++$2; }
	| MINUSMINUS unary_expression { $$ = --$2; }
	;

type_name:
	  INT
	;

multiplicative_expression:
	  cast_expression
	| multiplicative_expression '*' cast_expression
	| multiplicative_expression '/' cast_expression
	| multiplicative_expression '%' cast_expression
	;

additive_expression:
	  multiplicative_expression
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
	;

shift_expression:
	  additive_expression
	| shift_expression SHL additive_expression { $$ = $1 << $3; }
	| shift_expression SHR additive_expression { $$ = $1 >> $3; }
	;

relational_expression:
	  shift_expression
	| relational_expression '<' shift_expression { $$ = $1 < $3; }
	| relational_expression LTEQ shift_expression { $$ = $1 <= $3; }
	| relational_expression '>' shift_expression { $$ = $1 > $3; }
	| relational_expression GTEQ shift_expression { $$ = $1 >= $3; }
	;

equality_expression:
	  relational_expression
	| equality_expression EQEQ relational_expression { $$ = $1 == $3; }
	| equality_expression NOTEQ relational_expression { $$ = $1 != $3; }
	;

bit_or_expression:
	  bit_xor_expression
	| bit_or_expression '|' bit_xor_expression { $$ = $1 | $3; }
	;

bit_xor_expression:
	  bit_and_expression
	| bit_xor_expression '^' bit_and_expression { $$ = $1 ^ $3; }
	;

bit_and_expression:
	  equality_expression
	| bit_and_expression '&' equality_expression { $$ = $1 & $3; }
	;

logical_or_expression:
	  logical_and_expression
	| logical_or_expression LOGOR logical_and_expression { $$ = $1 || $3; }
	;

logical_and_expression:
	  bit_or_expression
	| logical_and_expression LOGAND bit_or_expression { $$ = $1 && $3; }
	;

assignment_expression:
	  /*conditional_expression*/
	  unary_expression '=' assignment_expression { $$ = $3;printf( "exprval=%lld\n", $$); }
	| unary_expression PLUSEQ assignment_expression {$$ = $1 + $3;$1 = $$; }
	| unary_expression MINUSEQ assignment_expression { $$ = $1 - $3;$1 = $$;}
	| unary_expression TIMESEQ assignment_expression { $$ = $1 * $3;$1 = $$; }
	| unary_expression DIVEQ assignment_expression { $$ = $1 / $3;$1 = $$; }
	| unary_expression MODEQ assignment_expression { $$ = $1 % $3;$1 = $$; }
	| unary_expression SHLEQ assignment_expression { $$ = $1 << $3;$1 = $$; }
	| unary_expression SHREQ assignment_expression { $$ = $1 >> $3;$1 = $$; }
	| unary_expression ANDEQ assignment_expression { $$ = $1 & $3;$1 = $$; }
	| unary_expression OREQ assignment_expression { $$ = $1 | $3;$1 = $$; }
	| unary_expression XOREQ assignment_expression { $$ = $1 ^ $3;$1 = $$; }
	;

expression:
	  assignment_expression
	| expression ',' assignment_expression { $$ = $3; }
	;

%%

void yyerror(const char* s) {
	fprintf(stderr, "Error: %s\n", s);
}

int main() {
	printf("[Parser Test]\n");
	strcpy(filename, "Placeholder.c");
	currentTable = enterScope(GLOBAL_SCOPE, 0, "TestFileName.c", NULL);
	yyparse();
}
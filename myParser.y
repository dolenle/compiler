%define parse.error verbose
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

#define YYDEBUG 1
int yydebug = 0;
void yyerror(const char* s);
symbolTable* currentTable;

char currentSym[128]; //probably not the proper way to do this
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
		} typeFlag;
		enum signtype {
			SIGNED_T,
			UNSIGNED_T
		} signFlag;
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

%left '_' '+' '=' '*' '/'
%left NEG     /* negation__unary minus */
%right '^'    /* exponentiation        */

%type <num.intBuff> initializer primary_expression unary_expression cast_expression
shift_expression relational_expression equality_expression logical_or_expression
logical_and_expression additive_expression assignment_expression expression

%start translation_unit;

%%

primary_expression
	: IDENT {
				if(containsSymbol(currentTable, $1)) {
					$$ = getSymbolValue(currentTable, $1);
					strcpy(currentSym, $1);
					printf("exprval: %i\n",$$);
				} else {
					yyerror("Symbol not found\n");
				}
			}
	| NUMBER 	{
					if (yylval.num.typeFlag == INT_T || yylval.num.typeFlag == LONG_T || yylval.num.typeFlag == LONGLONG_T)
                        $$ = yylval.num.intBuff;
                else {
                        $$ = (long long)yylval.num.realBuff;
                        fprintf(stderr,"Truncating real number %Lg to integer %lld\n",yylval.num.realBuff,$$);
                        printf("exprval=%lld\n",$$);
                }
				}
	| STRING {yyerror("Strings not supported.");}
	| '(' expression ')' {}
	;
	
postfix_expression
	: primary_expression
	| postfix_expression '[' expression ']'
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')'
	| postfix_expression '.' IDENT
	| postfix_expression INDSEL IDENT
	| postfix_expression PLUSPLUS
	| postfix_expression MINUSMINUS
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;

unary_expression
	: postfix_expression {}
	| '-' cast_expression { $$ = -$2; }
	| '+' cast_expression { $$ = $2;  printf("exprval=%lld\n",$$); }
	| '!' cast_expression { $$ = !$2; }
	| '~' cast_expression { $$ = ~$2; }
	| '&' cast_expression { $$ = (long long) &$2; }
	| '*' cast_expression { $$ = $2; }
	| PLUSPLUS unary_expression { $$ = ++$2; }
	| MINUSMINUS unary_expression { $$ = --$2; }
	| SIZEOF unary_expression {}
	| SIZEOF '(' type_name ')' {} { $$ = sizeof(long long); }
	;

unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	;

cast_expression
	: unary_expression {}
	| '(' type_name ')' cast_expression {}
	;

multiplicative_expression
	: cast_expression 
	| multiplicative_expression '*' cast_expression
	| multiplicative_expression '/' cast_expression
	| multiplicative_expression '%' cast_expression
	;

additive_expression
	: multiplicative_expression {}
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
	;

shift_expression
	: additive_expression
	| shift_expression SHL additive_expression
	| shift_expression SHR additive_expression
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression LTEQ shift_expression
	| relational_expression GTEQ shift_expression
	;

equality_expression
	: relational_expression
	| equality_expression EQEQ relational_expression
	| equality_expression NOTEQ relational_expression
	;

and_expression
	: equality_expression
	| and_expression '&' equality_expression
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression
	;

logical_and_expression
	: inclusive_or_expression {}
	| logical_and_expression LOGAND inclusive_or_expression
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression LOGOR logical_and_expression
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression
	;

assignment_expression
	: conditional_expression {}
	| unary_expression '=' assignment_expression { $$ = $3; setSymbolValue(currentTable, currentSym, (long long) $3); printf( "exprval=%lld\n", $$); }
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

assignment_operator
	: '='
	| TIMESEQ
	| DIVEQ
	| MODEQ
	| PLUSEQ
	| MINUSEQ
	| SHLEQ
	| SHREQ
	| ANDEQ
	| XOREQ
	| OREQ
	;

expression
	: assignment_expression
	| expression ',' assignment_expression
	;

constant_expression
	: conditional_expression
	;

declaration
	: declaration_specifiers ';'
	| declaration_specifiers init_declarator_list ';'
	;

declaration_specifiers
	: storage_class_specifier
	| storage_class_specifier declaration_specifiers
	| type_specifier
	| type_specifier declaration_specifiers
	| type_qualifier
	| type_qualifier declaration_specifiers
	;

init_declarator_list
	: init_declarator
	| init_declarator_list ',' init_declarator
	;

init_declarator
	: declarator
	| declarator '=' initializer
	;

storage_class_specifier
	: TYPEDEF
	| EXTERN
	| STATIC
	| AUTO
	| REGISTER
	;

type_specifier
	: VOID
	| CHAR
	| SHORT
	| INT
	| LONG
	| FLOAT
	| DOUBLE
	| SIGNED
	| UNSIGNED
	| struct_or_union_specifier
	| enum_specifier
	| TYPEDEF_NAME
	;

struct_or_union_specifier
	: struct_or_union IDENT '{' struct_declaration_list '}'
	| struct_or_union '{' struct_declaration_list '}'
	| struct_or_union IDENT
	;

struct_or_union
	: STRUCT
	| UNION
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	| type_qualifier specifier_qualifier_list
	| type_qualifier
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list ',' struct_declarator
	;

struct_declarator
	: declarator
	| ':' constant_expression
	| declarator ':' constant_expression
	;

enum_specifier
	: ENUM '{' enumerator_list '}'
	| ENUM IDENT '{' enumerator_list '}'
	| ENUM IDENT
	;

enumerator_list
	: enumerator
	| enumerator_list ',' enumerator
	;

enumerator
	: IDENT
	| IDENT '=' constant_expression
	;

type_qualifier
	: CONST
	| VOLATILE
	;

declarator
	: pointer direct_declarator
	| direct_declarator
	;

direct_declarator
	: IDENT {
				if(!containsSymbol(currentTable, $1)) {
					installSymbol(currentTable, $1, filename, line, NUM);
				} else {
					yyerror("Redeclaration of variable");
					}
			}
	| '(' declarator ')' 
	| direct_declarator '[' constant_expression ']'
	| direct_declarator '[' ']'
	| direct_declarator '(' parameter_type_list ')'
	| direct_declarator '(' identifier_list ')'
	| direct_declarator '(' ')'
	;

pointer
	: '*'
	| '*' type_qualifier_list
	| '*' pointer
	| '*' type_qualifier_list pointer
	;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
	;


parameter_type_list
	: parameter_list
	| parameter_list ',' ELLIPSIS
	;

parameter_list
	: parameter_declaration
	| parameter_list ',' parameter_declaration
	;

parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers abstract_declarator
	| declaration_specifiers
	;

identifier_list
	: IDENT {printf("%s\n", "identifier list");}
	| identifier_list ',' IDENT
	;

type_name
	: specifier_qualifier_list
	| specifier_qualifier_list abstract_declarator
	;

abstract_declarator
	: pointer
	| direct_abstract_declarator
	| pointer direct_abstract_declarator
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'
	| '[' ']'
	| '[' constant_expression ']'
	| direct_abstract_declarator '[' ']'
	| direct_abstract_declarator '[' constant_expression ']'
	| '(' ')'
	| '(' parameter_type_list ')'
	| direct_abstract_declarator '(' ')'
	| direct_abstract_declarator '(' parameter_type_list ')'
	;

initializer
	: assignment_expression
	| '{' initializer_list '}' {}
	| '{' initializer_list ',' '}' {}
	;

initializer_list
	: initializer
	| initializer_list ',' initializer
	;

statement
	: labeled_statement
	| compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;

labeled_statement
	: IDENT ':' statement
	| CASE constant_expression ':' statement
	| DEFAULT ':' statement
	;

compound_statement
	: '{' '}'
	| '{' 	{
				if(currentTable->scope == GLOBAL_SCOPE) {
					currentTable = enterScope(FUNCTION_SCOPE, line, filename, currentTable);
				} else {
					currentTable = enterScope(BLOCK_SCOPE, line, filename, currentTable);
				}
			}
		declaration_or_statement_list '}' {currentTable = leaveScope(currentTable, 0);}
	;
	
declaration_or_statement_list
	: statement_list
	| declaration_list
	| declaration_or_statement_list declaration_list
	| declaration_or_statement_list statement_list
	| declaration_list statement_list
	;

declaration_list
	: declaration
	| declaration_list declaration
	;

statement_list
	: statement
	| statement_list statement
	;

expression_statement
	: ';'
	| expression ';'
	;

selection_statement
	: IF '(' expression ')' statement
	| IF '(' expression ')' statement ELSE statement
	| SWITCH '(' expression ')' statement
	;

iteration_statement
	: WHILE '(' expression ')' statement
	| DO statement WHILE '(' expression ')' ';'
	| FOR '(' expression_statement expression_statement ')' statement
	| FOR '(' expression_statement expression_statement expression ')' statement
	;

jump_statement
	: GOTO IDENT ';'
	| CONTINUE ';'
	| BREAK ';'
	| RETURN ';'
	| RETURN expression ';'
	;

translation_unit
	: external_declaration
	| translation_unit external_declaration
	;

external_declaration
	: function_definition {printf("Left function!\n");}
	| declaration
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement
	| declaration_specifiers declarator compound_statement
	| declarator declaration_list compound_statement
	| declarator compound_statement
	;

%%

void yyerror(const char* s) {
	fprintf(stderr, "Error: %s\n", s);
}

int main() {
	printf("[Parser Begin]\n");
	strcpy(filename, "Placeholder.c");
	currentTable = enterScope(GLOBAL_SCOPE, 0, "TestFileName.c", NULL);
	yyparse();
}
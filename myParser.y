/*%define parse.error verbose*/
%debug
%{
#include "globls.h"
#include "syms.h"
#include "ast.h"
#include "quad.h"
#include "print.h"
#include <stdio.h>
#include <stdlib.h>

#define YYDEBUG 1
int yydebug = 0;
int print_decl = 0; //1 to print declaration ast

void yyerror(const char* s);

void doScopeThing();
node* doIdentThing(char* id);
void traverseAST(node* start, int tabs);

extern int yylex();
extern int line;

char filename[4096];

symbolTable* currentTable;
namespaceType currentNamespace = DEFAULT_SPACE;

char currentSym[128]; //probably not the proper way to do this
%}

%union {
	char charBuff;
	char* stringBuff;
	void* noval;
	
	struct node* astNode;
	struct ast ast;
	
	struct num {
		long long intBuff;
		long double realBuff;
		numType typeFlag;
		signType signFlag;
	} num;
}

/* BISON Declarations */

%token <charBuff> CHARLIT
%token <stringBuff> STRING IDENT
%token <num> NUMBER
%token <noval> INDSEL PLUSPLUS MINUSMINUS SHL SHR LTEQ GTEQ EQEQ NOTEQ LOGAND LOGOR
ELLIPSIS TIMESEQ DIVEQ MODEQ PLUSEQ MINUSEQ SHLEQ SHREQ ANDEQ OREQ XOREQ AUTO BREAK
CASE CHAR CONST CONTINUE DEFAULT DO DOUBLE ELSE ENUM EXTERN FLOAT FOR GOTO IF INLINE
INT LONG REGISTER RESTRICT RETURN SHORT SIGNED SIZEOF STATIC STRUCT SWITCH TYPEDEF
TYPEDEF_NAME UNION UNSIGNED VOID VOLATILE WHILE _BOOL _COMPLEX _IMAGINARY

%left IF
%left ELSE

%type <astNode> type_specifier storage_class_specifier primary_expression cast_expression
multiplicative_expression shift_expression relational_expression equality_expression
logical_or_expression logical_and_expression additive_expression assignment_expression
unary_expression postfix_expression expression and_expression exclusive_or_expression
inclusive_or_expression declaration_or_statement conditional_expression statement
expression_statement selection_statement iteration_statement jump_statement

%type <ast> init_declarator init_declarator_list declarator direct_declarator pointer
declaration_specifiers declaration_or_statement_list declaration compound_statement
argument_expression_list function_definition

%start translation_unit;

%%

primary_expression
	: IDENT {
			if(containsSymbol(currentTable, $1)) {
				//$$ = getSymbolValue(currentTable, $1);
				//strcpy(currentSym, $1);
				//printf("exprval: %lli\n",$$);
				$$ = getNode(currentTable, $1);
			} else {
				symbolTable* parent = searchSymbol(currentTable, $1);
				if(parent) {
					//printf("Symbol found in outer scope\n");
					$$ = getNode(parent, $1);
				} else {
					yyerror("Symbol not found");
					$$ = NULL;
				}
			}
		}
	| NUMBER {
			$$ = ast_newNode(NUMBER_NODE);
			if ($1.typeFlag == INT_T || $1.typeFlag == LONG_T || $1.typeFlag == LONGLONG_T) {
				//$$ = yylval.num.intBuff;
				$$->u.number.value = $1.intBuff;
			} else {
				yyerror("Real types not supported. Casting to int");
				$$->u.number.value = (long long)$1.realBuff;
			}
			$$->u.number.typeFlag = $1.typeFlag;
			$$->u.number.signFlag = $1.signFlag;
		}
	| STRING {yyerror("Strings not supported.");}
	| '(' expression ')' {$$ = $2;}
	;
	
postfix_expression
	: primary_expression {
			//$$ = appendNode($$, $1);
			$$=$1;
		}
	| postfix_expression '[' expression ']' {
		if($1->type == UNOP_NODE && ($1->u.unop.type == SIZEOF_OP || $1->u.unop.type == ADDR_OP)) {
			printf("Something is not implemented\n");
		} else {
			//CONVERT TO *(E1+E2)
			$$ = ast_newNode(UNOP_NODE);
			$$->u.unop.type = DEREF_OP;
			node *n = ast_newNode(BINOP_NODE);
			$$->u.unop.operand = n;
			n->u.binop.type = PLUS_OP;
			n->u.binop.left = $1;
			n->u.binop.right = $3;
		}
	}
	| postfix_expression '(' ')' {
			//Function call without arguments
			$$ = ast_newNode(CALL_NODE);
			$$->u.call.function = $1;
			$$->u.call.argnum = 0;
		}
	| postfix_expression '(' argument_expression_list ')' {
			$$ = ast_newNode(CALL_NODE);
			$$->u.call.function = $1;
			$$->u.call.args = $3.topNode;
			//Compute # of arguments
			int argnum = 0;
			node* argptr = $3.topNode;
			while(argptr) {
				argnum++;
				if(argptr->next) {
					argptr = argptr->next;
				} else {
					break;
				}
			}
			$$->u.call.argnum = argnum;
		}
	| postfix_expression '.' IDENT {
			yyerror("Unimplemented Struct/Union Selector");
		}
	| postfix_expression INDSEL IDENT {
			yyerror("Unimplemented Struct/Union Indirect Selector");
		}
	| postfix_expression PLUSPLUS {
			$$ = ast_newNode(UNOP_NODE);
			$$->u.unop.type = POSTINC_OP;
			$$->u.unop.operand = $1;
		}
	| postfix_expression MINUSMINUS {
			$$ = ast_newNode(UNOP_NODE);
			$$->u.unop.type = POSTDEC_OP;
			$$->u.unop.operand = $1;
		}
	;

argument_expression_list
	: assignment_expression {
			node* n = ast_newNode(LIST_NODE);
			n->u.list.start = $1;
			initAST(&$$);
			$$ = appendNode($$, n);
		}
	| argument_expression_list ',' assignment_expression {
			node* n = ast_newNode(LIST_NODE);
			n->u.list.start = $3;
			$$ = appendNode($1, n);
		}
	;

unary_expression
	: postfix_expression {
			$$ = $1;
		}
	| '&' cast_expression {
			$$ = ast_newNode(UNOP_NODE);
			$$->u.unop.type = ADDR_OP;
			$$->u.unop.operand = $2;
		}
	| '*' cast_expression {
			$$ = ast_newNode(UNOP_NODE);
			$$->u.unop.type = DEREF_OP;
			$$->u.unop.operand = $2;
		}
	| '+' cast_expression {
			$$ = ast_newNode(UNOP_NODE);
			$$->u.unop.type = POS_OP;
			$$->u.unop.operand = $2;	
		}
	| '-' cast_expression {
			$$ = ast_newNode(UNOP_NODE);
			$$->u.unop.type = NEG_OP;
			$$->u.unop.operand = $2;
		}
	| '~' cast_expression {
			$$ = ast_newNode(UNOP_NODE);
			$$->u.unop.type = NOT_OP;
			$$->u.unop.operand = $2;
		}
	| '!' cast_expression {
			$$ = ast_newNode(UNOP_NODE);
			$$->u.unop.type = LOGNOT_OP;
			$$->u.unop.operand = $2;
		}
	| PLUSPLUS unary_expression {
			$$ = ast_newNode(UNOP_NODE);
			$$->u.unop.type = PREINC_OP;
			$$->u.unop.operand = $2;
		}
	| MINUSMINUS unary_expression {
			$$ = ast_newNode(UNOP_NODE);
			$$->u.unop.type = PREDEC_OP;
			$$->u.unop.operand = $2;
		}
	| SIZEOF unary_expression {
			$$ = ast_newNode(UNOP_NODE);
			$$->u.unop.type = SIZEOF_OP;
			$$->u.unop.operand = $2;
		}
	| SIZEOF '(' type_specifier ')' {
			$$ = ast_newNode(UNOP_NODE);
			$$->u.unop.type = SIZEOF_OP;
			$$->u.unop.operand = $3;
		}
	;

cast_expression
	: unary_expression {$$ = $1;}
	| '(' type_name ')' cast_expression {yyerror("We only do ints. sorry.");}
	;

multiplicative_expression
	: cast_expression 
	| multiplicative_expression '*' cast_expression {
			$$ = ast_newNode(BINOP_NODE);
			$$->u.binop.type = MULT_OP;
			$$->u.binop.left = $1;
			$$->u.binop.right = $3;
		}
	| multiplicative_expression '/' cast_expression {
			$$ = ast_newNode(BINOP_NODE);
			$$->u.binop.type = DIV_OP;
			$$->u.binop.left = $1;
			$$->u.binop.right = $3;
		}
	| multiplicative_expression '%' cast_expression {
			node* n = ast_newNode(BINOP_NODE);
			$$->u.binop.type = MULT_OP;
			$$->u.binop.left = $1;
			$$->u.binop.right = $3;
		}
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression {
			$$ = ast_newNode(BINOP_NODE);
			$$->u.binop.type = PLUS_OP;
			$$->u.binop.left = $1;
			$$->u.binop.right = $3;
		}
	| additive_expression '-' multiplicative_expression {
			$$ = ast_newNode(BINOP_NODE);
			$$->u.binop.type = MINUS_OP;
			$$->u.binop.left = $1;
			$$->u.binop.right = $3;
		}
	;

shift_expression
	: additive_expression
	| shift_expression SHL additive_expression {
			$$ = ast_newNode(BINOP_NODE);
			$$->u.binop.type = SHL_OP;
			$$->u.binop.left = $1;
			$$->u.binop.right = $3;
		}
	| shift_expression SHR additive_expression {
			$$ = ast_newNode(BINOP_NODE);
			$$->u.binop.type = SHR_OP;
			$$->u.binop.left = $1;
			$$->u.binop.right = $3;
		}
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression {
			$$ = ast_newNode(BINOP_NODE);
			$$->u.binop.type = LT_OP;
			$$->u.binop.left = $1;
			$$->u.binop.right = $3;
		}
	| relational_expression '>' shift_expression {
			$$ = ast_newNode(BINOP_NODE);
			$$->u.binop.type = GT_OP;
			$$->u.binop.left = $1;
			$$->u.binop.right = $3;
		}
	| relational_expression LTEQ shift_expression {
			$$ = ast_newNode(BINOP_NODE);
			$$->u.binop.type = LTEQ_OP;
			$$->u.binop.left = $1;
			$$->u.binop.right = $3;
		}
	| relational_expression GTEQ shift_expression {
			$$ = ast_newNode(BINOP_NODE);
			$$->u.binop.type = GTEQ_OP;
			$$->u.binop.left = $1;
			$$->u.binop.right = $3;
		}
	;

equality_expression
	: relational_expression
	| equality_expression EQEQ relational_expression {
			$$ = ast_newNode(BINOP_NODE);
			$$->u.binop.type = EQEQ_OP;
			$$->u.binop.left = $1;
			$$->u.binop.right = $3;
		}
	| equality_expression NOTEQ relational_expression {
			$$ = ast_newNode(BINOP_NODE);
			$$->u.binop.type = NOTEQ_OP;
			$$->u.binop.left = $1;
			$$->u.binop.right = $3;
		}
	;

and_expression
	: equality_expression
	| and_expression '&' equality_expression {
			$$ = ast_newNode(BINOP_NODE);
			$$->u.binop.type = AND_OP;
			$$->u.binop.left = $1;
			$$->u.binop.right = $3;
		}
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression {
			$$ = ast_newNode(BINOP_NODE);
			$$->u.binop.type = XOR_OP;
			$$->u.binop.left = $1;
			$$->u.binop.right = $3;
		}
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression {
			$$ = ast_newNode(BINOP_NODE);
			$$->u.binop.type = IOR_OP;
			$$->u.binop.left = $1;
			$$->u.binop.right = $3;
		}
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression LOGAND inclusive_or_expression {
			$$ = ast_newNode(BINOP_NODE);
			$$->u.binop.type = LOGAND_OP;
			$$->u.binop.left = $1;
			$$->u.binop.right = $3;
		}
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression LOGOR logical_and_expression {
			$$ = ast_newNode(BINOP_NODE);
			$$->u.binop.type = LOGOR_OP;
			$$->u.binop.left = $1;
			$$->u.binop.right = $3;
		}
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression {
			yyerror("Unimplemented ternary operator");
		}
	;

assignment_expression
	: conditional_expression
	| unary_expression '=' assignment_expression {
			$$ = ast_newNode(ASSIGN_NODE);
			$$->u.assign.type = EQ_OP;
			$$->u.assign.left = $1;
			$$->u.assign.right = $3;
		}
	| unary_expression PLUSEQ assignment_expression {
			$$ = ast_newNode(ASSIGN_NODE);
			$$->u.assign.type = PLUSEQ_OP;
			$$->u.assign.left = $1;
			$$->u.assign.right = $3;
		}
	| unary_expression MINUSEQ assignment_expression {
			$$ = ast_newNode(ASSIGN_NODE);
			$$->u.assign.type = MINUSEQ_OP;
			$$->u.assign.left = $1;
			$$->u.assign.right = $3;
		}
	| unary_expression TIMESEQ assignment_expression {
			$$ = ast_newNode(ASSIGN_NODE);
			$$->u.assign.type = TIMESEQ_OP;
			$$->u.assign.left = $1;
			$$->u.assign.right = $3;
		}
	| unary_expression DIVEQ assignment_expression {
			$$ = ast_newNode(ASSIGN_NODE);
			$$->u.assign.type = DIVEQ_OP;
			$$->u.assign.left = $1;
			$$->u.assign.right = $3;
		}
	| unary_expression MODEQ assignment_expression {
			$$ = ast_newNode(ASSIGN_NODE);
			$$->u.assign.type = MODEQ_OP;
			$$->u.assign.left = $1;
			$$->u.assign.right = $3;
		}
	| unary_expression SHLEQ assignment_expression {
			$$ = ast_newNode(ASSIGN_NODE);
			$$->u.assign.type = SHLEQ_OP;
			$$->u.assign.left = $1;
			$$->u.assign.right = $3;
		}
	| unary_expression SHREQ assignment_expression {
			$$ = ast_newNode(ASSIGN_NODE);
			$$->u.assign.type = SHREQ_OP;
			$$->u.assign.left = $1;
			$$->u.assign.right = $3;
		}
	| unary_expression ANDEQ assignment_expression {
			$$ = ast_newNode(ASSIGN_NODE);
			$$->u.assign.type = ANDEQ_OP;
			$$->u.assign.left = $1;
			$$->u.assign.right = $3;
		}
	| unary_expression OREQ assignment_expression {
			$$ = ast_newNode(ASSIGN_NODE);
			$$->u.assign.type = OREQ_OP;
			$$->u.assign.left = $1;
			$$->u.assign.right = $3;
		}
	| unary_expression XOREQ assignment_expression {
			$$ = ast_newNode(ASSIGN_NODE);
			$$->u.assign.type = XOREQ_OP;
			$$->u.assign.left = $1;
			$$->u.assign.right = $3;
		}
	;

expression
	: assignment_expression
	| expression ',' assignment_expression
	;

constant_expression
	: conditional_expression
	;

declaration
	: declaration_specifiers ';' {
			yyerror("useless and empty declaration");
		}
	| declaration_specifiers init_declarator_list ';' {
			if(!$1.errorFlag && !$2.errorFlag) {
				//Chokes on "int * const i"
				if(print_decl) printf("\nparsing AST....\n\n");
				node* dc = $2.topNode; //declarator
				initAST(&$$);
				node* nextID = NULL;
				do {
					node* ds = $1.topNode; //specifier
					
					if(dc->type == IDENT_NODE) {
						if(ds->type == STORAGE_NODE) { //set storage class
							if(currentTable->scope == GLOBAL_SCOPE &&
								ds->u.storage.type != SG_STATIC && ds->u.storage.type != SG_EXTERN) {
								yyerror("Invalid file-scope declaration, defaulting to STATIC");
								dc->u.ident.stor = SG_STATIC;
							} else {
								dc->u.ident.stor = ds->u.storage.type;
							}
							if(ds != $1.botNode) {
								ds = ds->next;
							}
						} else if(currentTable->scope == GLOBAL_SCOPE) {
							dc->u.ident.stor = SG_STATIC;
						} else {
							dc->u.ident.stor = SG_AUTO;
						}
						if(print_decl) printf("identifier \"%s\" declared on line %i, storage class %s\n",
						dc->u.ident.id, dc->u.ident.line, storageText[dc->u.ident.stor]);
						
						$$ = appendNode($$, dc);
						//printf("APPENDING IDENT...%s\n", dc->u.ident.id);
					} else {
						yyerror("Expected Identifier");
					}

					while(dc != $2.botNode) {
						if(dc->next->type == ARRAY_NODE) {
							dc = dc->next;
							$$ = appendNode($$, dc);
							if(print_decl) printf("array of length %i containing \n", dc->u.array.length);
						} else if(dc->next->type == POINTER_NODE) {
							if(print_decl) printf("pointer to\n");
							dc = dc->next;
							$$ = appendNode($$, dc);
						} else if(dc->next->type == FUNCTION_NODE) {
							if(print_decl) printf("function returning\n");
							dc = dc->next;
							$$ = appendNode($$, dc);
						} else if(dc->next->type == IDENT_NODE) {
							nextID = dc->next; //preserve the next one
							break;
						} else {
							break;
						}
					}
					do {
						if(ds->type == SCALAR_NODE) {
							if(print_decl) printf("scalar type %s\n", scalarText[ds->u.scalar.type]);
							//copy the type node to the declaration list
							node* cpy = ast_newNode(SCALAR_NODE);
							$$ = appendNode($$, (node*) memcpy((void*) cpy,(void*) ds, sizeof(node)));
						} else {
							if(print_decl) printf("Expected type specifier, got %i\n", ds->type);
						}
						if(ds != $1.botNode)
							ds = ds->next;
					} while(ds != $1.botNode);
					
					if(print_decl) printf("\n");
					if(dc != $2.botNode && nextID != NULL) {
						dc = nextID; 
					} else {
						break;
					}
				} while(1);
			} else {
				$$.errorFlag = 1;
			}
		}
	;

declaration_specifiers
	: storage_class_specifier {
			initAST(&$$);
			$$ = prependNode($$, $1);
			$$.errorFlag = 0;
		}
	| storage_class_specifier declaration_specifiers {
			if($2.topNode->type == STORAGE_NODE) {
				yyerror("Multiple storage class specifiers");
				$$.errorFlag = 1;
			} else {
				$$ = prependNode($2, $1);
			}
		}
	| type_specifier	{
			initAST(&$$);
			$$ = appendNode($$, $1);
			$$.errorFlag = 0;
		}
	| type_specifier declaration_specifiers {
			node* ts = $2.botNode; //get current type specifier from bottom
			switch($1->u.scalar.type) {
				case S_INT:
					{
						int x = ts->u.scalar.type;
						if(!(x==S_SHORT || x==S_USHORT || x==S_LONG || x==S_ULONG || 
							x==S_LONGLONG || x==S_ULONGLONG)) {
							goto err;
						}
						break;
					}
				case S_LONG:
					switch(ts->u.scalar.type) {
						case S_INT:
							ts->u.scalar.type=S_LONG;
							break;
						case S_LONG:
							ts->u.scalar.type=S_LONGLONG;
							break;
						case S_DOUBLE:
							ts->u.scalar.type=S_LONGDOUBLE;
							break;
						default:
							goto err;
					}
					break;
				case S_SHORT:
					if(ts->u.scalar.type != S_INT) {
						goto err;
					}
					break;
				case S_SIGNED: //integer types only, signed by default
					if(ts->u.scalar.type < S_CHAR || ts->u.scalar.type > S_LONGLONG)
						goto err;
					break;
				case S_UNSIGNED:
					if(ts->u.scalar.type >= S_CHAR && ts->u.scalar.type <= S_LONGLONG) {
						ts->u.scalar.type = ts->u.scalar.type*2;
						//printf("newType=%i",ts->u.scalar.type);
						break;
					} else {
						goto err;
					}
			err:
				default:
					$$.errorFlag = 1;
					yyerror("Invalid type specifier");
					break;
			}
			if($$.topNode->type != SCALAR_NODE) {
				$$.topNode->next = ts;
			} else {
				$$.topNode = ts;
			}
			$$.botNode = ts;
			//printf("newType=%i",$$.botNode->u.scalar.type);
		}
	| type_qualifier {yyerror("Unimplemented Type Qualifier"); $$.errorFlag = 1;}
	| type_qualifier declaration_specifiers {yyerror("Unimplemented Type Qualifier"); $$.errorFlag = 1;}
	;

init_declarator_list
	: init_declarator {
			if($1.errorFlag != 1) {
				$$ = $1;
			} else {
				$$.errorFlag = 1;
			}
		}
	| init_declarator_list ',' init_declarator {
			if($3.errorFlag != 1) {
				$$ = appendAST($1, $3);
			} else {
				$$.errorFlag = 1;
			}
		}
	;

init_declarator
	: declarator {$$ = $1;}
	| declarator '=' initializer {
			yyerror("Unimplemented initialized declarator");
			$$.errorFlag = 1;
			if($1.topNode->type == IDENT_NODE) {
				removeSymbol(currentTable, $1.topNode->u.ident.id);
			}
		}
	;

storage_class_specifier
	: TYPEDEF {
			$$ = ast_newNode(STORAGE_NODE);
			$$->u.scalar.type = SG_TYPEDEF;
		}
	| EXTERN {
			$$ = ast_newNode(STORAGE_NODE);
			$$->u.scalar.type = SG_EXTERN;
		}
	| STATIC {
			$$ = ast_newNode(STORAGE_NODE);
			$$->u.scalar.type = SG_STATIC;
		}
	| AUTO {
			$$ = ast_newNode(STORAGE_NODE);
			$$->u.scalar.type = SG_AUTO;
		}
	| REGISTER {
			$$ = ast_newNode(STORAGE_NODE);
			$$->u.scalar.type = SG_REGISTER;
		}
	;

type_specifier
	: VOID	{
				$$ = ast_newNode(SCALAR_NODE);
				$$->u.scalar.type = S_VOID;
			}
	| CHAR	{
				$$ = ast_newNode(SCALAR_NODE);
				$$->u.scalar.type = S_CHAR;
			}
	| SHORT	{
				$$ = ast_newNode(SCALAR_NODE);
				$$->u.scalar.type = S_SHORT;
			}
	| INT	{
				$$ = ast_newNode(SCALAR_NODE);
				$$->u.scalar.type = S_INT;
			}
	| LONG	{
				$$ = ast_newNode(SCALAR_NODE);
				$$->u.scalar.type = S_LONG;
			}
	| FLOAT	{
				$$ = ast_newNode(SCALAR_NODE);
				$$->u.scalar.type = S_FLOAT;
			}
	| DOUBLE	{
					$$ = ast_newNode(SCALAR_NODE);
					$$->u.scalar.type = S_DOUBLE;
				}
	| SIGNED	{
					$$ = ast_newNode(SCALAR_NODE);
					$$->u.scalar.type = S_SIGNED;
				}
	| UNSIGNED	{
					$$ = ast_newNode(SCALAR_NODE);
					$$->u.scalar.type = S_UNSIGNED;
				}
	| struct_or_union_specifier {yyerror("Unimplemented struct or union");}
	| enum_specifier {yyerror("Unimplemented enum");}
	| TYPEDEF_NAME {yyerror("Unimplemented typedef");}
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
	: pointer direct_declarator {
			if(!$2.errorFlag && !$1.errorFlag) {
				$$ = appendAST($2, $1);
			} else {
				$$.errorFlag = 1;
			}
		}
	| direct_declarator {$$ = $1;}
	;

direct_declarator
	: IDENT {
			node* n = doIdentThing($1);
			initAST(&$$);
			if(n) {
				$$ = prependNode($$, n);
			} else {
				$$.errorFlag = 1;
			}
		}
	| '(' declarator ')' {$$=$2;}
	| direct_declarator '[' NUMBER ']' {
			//Array Declarator
			if ($3.typeFlag == INT_T && $3.intBuff >= 0) {
				node* n = ast_newNode(ARRAY_NODE);
				n->u.array.length = $3.intBuff;
				$$ = appendNode($1, n);
			} else {
				yyerror("invalid array declaration");
			}
		}
	| direct_declarator '[' ']' {
			//Array Declarator
			node* n = ast_newNode(ARRAY_NODE);
			n->u.array.length = -1;
			$$ = appendNode($1, n);
		}
	| direct_declarator '(' parameter_type_list ')' {yyerror("Unimplemented function prototype");}
	| direct_declarator '(' identifier_list ')' {yyerror("Unimplemented function prototype");}
	| direct_declarator '(' ')' {
			node* n = ast_newNode(FUNCTION_NODE);
			$$ = appendNode($1, n);
		}
	;

pointer
	: '*' {
			initAST(&$$);
			$$ = appendNode($$, ast_newNode(POINTER_NODE));
		}
	| '*' type_qualifier_list {}
	| '*' pointer {
			$$ = appendNode($2, ast_newNode(POINTER_NODE));
		}
	| '*' type_qualifier_list pointer {/*type qualifier Not Implemented*/}
	;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
	;

parameter_type_list
	: parameter_list
	| parameter_list ',' ELLIPSIS {yyerror("Unimplemented variadic function");}
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
	: IDENT
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
	: assignment_expression {/*NOT IMPLEMENTED*/}
	| '{' initializer_list '}' {}
	| '{' initializer_list ',' '}' {}
	;

initializer_list
	: initializer
	| initializer_list ',' initializer {}
	;

statement
	: labeled_statement {yyerror("Unimplemented Labels");}
	| compound_statement {$$ = $1.topNode;}
	| expression_statement /*do/for/while*/
	| selection_statement /*switch and if stmt*/
	| iteration_statement /*do/for/while*/
	| jump_statement /*goto, return and break*/
	;

labeled_statement
	: IDENT ':' statement
	| CASE constant_expression ':' statement
	| DEFAULT ':' statement
	;

declaration_list
	: declaration
	| declaration_list declaration
	;

compound_statement
	: '{' '}' {
			yyerror("empty block");
		}
	| '{' {
			doScopeThing();
		} declaration_or_statement_list '}' {
			currentTable = leaveScope(currentTable, 0);
			$$ = $3;
			
			// node* tmp = $$.topNode;
			// while(tmp!= $$.botNode) {
			// 	printf("Node Type %i (%s)\n", tmp->type, nodeText[tmp->type]);
			// 	if(tmp->type == LIST_NODE) {
			// 		node* n = tmp->u.list.start;
			// 		traverseAST(n, 1);
			// 	}
			// 	tmp = tmp->next;
			// }
			// printf("Node Type %i (%s)\n", tmp->type, nodeText[tmp->type]);
			// traverseAST(tmp->u.list.start, 1);
		}
	;

declaration_or_statement_list
	: declaration_or_statement {
			if($1 != NULL) {
			/*
				node* curr = $1;
				initAST(&$$);
				while(curr->next) {
					if(curr->type == IDENT_NODE) {
						node* n = ast_newNode(LIST_NODE);
						n->u.list.start = curr;
						$$ = appendNode($$, n);
					}
					curr = curr->next;
				}
			*/
				if($1->type == IDENT_NODE) {
					node* curr = $1;
					initAST(&$$);
					
					node* n = ast_newNode(LIST_NODE);
					n->u.list.start = curr;
					$$ = appendNode($$, n);
					curr = curr->next;
					while(curr->next) {
						//printf("appending %i...\n", curr->next->type);
						if(curr->type == IDENT_NODE) {
							node* n = ast_newNode(LIST_NODE);
							n->u.list.start = curr;
							$$ = appendNode($$, n);
						}
						curr = curr->next;
					}
				} else {
					node* n = ast_newNode(LIST_NODE);
					n->u.list.start = $1;
					initAST(&$$);
					$$ = appendNode($$, n);
				}
			}
		}
	| declaration_or_statement_list declaration_or_statement {
			if($2 != NULL) {
				node* n = ast_newNode(LIST_NODE);
				n->u.list.start = $2;
				$$ = appendNode($1, n);
			}
		}
	;

declaration_or_statement
	: declaration {
			if(!$1.errorFlag) {
				$$ = $1.topNode;
			} else {
				$$ = NULL;
				yyerror("Declaration error");
			}
		}
	| statement
	;

expression_statement
	: ';' {}
	| expression ';' {$$ = $1;};
	;

selection_statement
	: IF '(' expression ')' statement %prec IF {
			$$ = ast_newNode(IF_NODE);
			$$->u.if_stmt.condition = $3;
			if($5->type == LIST_NODE) {
				$$->u.if_stmt.if_block = $5;
			} else {
				node* n = ast_newNode(LIST_NODE);
				n->u.list.start = $5;
				$$->u.if_stmt.if_block = n;
			}
		}
	| IF '(' expression ')' statement ELSE statement {
			$$ = ast_newNode(IFELSE_NODE);
			$$->u.ifelse_stmt.condition = $3;
			if($5->type == LIST_NODE) {
				$$->u.ifelse_stmt.if_block = $5;
			} else {
				node* n = ast_newNode(LIST_NODE);
				n->u.list.start = $5;
				$$->u.ifelse_stmt.if_block = n;
			}
			if($7->type == LIST_NODE) {
				$$->u.ifelse_stmt.else_block = $7;
			} else {
				node* n = ast_newNode(LIST_NODE);
				n->u.list.start = $7;
				$$->u.ifelse_stmt.else_block = n;
			}
		}
	| SWITCH '(' expression ')'  statement {yyerror("Unimplemented switch statement");}
	;

iteration_statement
	: WHILE '(' expression ')' statement {
			$$ = ast_newNode(WHILE_NODE);
			$$->u.while_stmt.condition = $3;
			$$->u.while_stmt.body = $5;
			$$->u.while_stmt.do_stmt = 0;
		}
	| DO statement WHILE '(' expression ')' ';' {
			$$ = ast_newNode(WHILE_NODE);
			$$->u.while_stmt.body = $2;
			$$->u.while_stmt.condition = $5;
			$$->u.while_stmt.do_stmt = 1;
		}
	| FOR '(' expression_statement expression_statement ')' statement {
			$$ = ast_newNode(FOR_NODE);
			if($3->type == LIST_NODE) {
				$$->u.for_stmt.init = $3;
			} else {
				node* n = ast_newNode(LIST_NODE);
				n->u.list.start = $3;
				$$->u.for_stmt.init = n;
			}
			$$->u.for_stmt.condition = $4;
			$$->u.for_stmt.afterthought = NULL;
			if($6->type == LIST_NODE) {
				$$->u.for_stmt.body = $6;
			} else {
				node* n = ast_newNode(LIST_NODE);
				n->u.list.start = $6;
				$$->u.for_stmt.body = n;
			}
		}
	| FOR '(' expression_statement expression_statement expression ')' statement {
			$$ = ast_newNode(FOR_NODE);
			if($3->type == LIST_NODE) {
				$$->u.for_stmt.init = $3;
			} else {
				node* n = ast_newNode(LIST_NODE);
				n->u.list.start = $3;
				$$->u.for_stmt.init = n;
			}
			$$->u.for_stmt.condition = $4;
			if($5->type == LIST_NODE) {
				$$->u.for_stmt.afterthought = $5;
			} else {
				node* n = ast_newNode(LIST_NODE);
				n->u.list.start = $5;
				$$->u.for_stmt.afterthought = n;
			}
			if($7->type == LIST_NODE) {
				$$->u.for_stmt.body = $7;
			} else {
				node* n = ast_newNode(LIST_NODE);
				n->u.list.start = $7;
				$$->u.for_stmt.body = n;
			}
		}
	;

jump_statement
	: GOTO IDENT ';' {yyerror("Labels are unimplemented, and so are GOTOs");}
	| CONTINUE ';' {
			$$ = ast_newNode(JUMP_NODE);
			$$->u.jump.type = CONTINUE_JP;
		}
	| BREAK ';' {
			$$ = ast_newNode(JUMP_NODE);
			$$->u.jump.type = BREAK_JP;
		}
	| RETURN ';' {
			$$ = ast_newNode(JUMP_NODE);
			$$->u.jump.type = RETURN_JP;
		}
	| RETURN expression ';' {
			$$ = ast_newNode(JUMP_NODE);
			$$->u.jump.type = RETURN_JP;
			$$->u.jump.target = $2;
		}
	;

translation_unit
	: external_declaration
	| translation_unit external_declaration
	;

external_declaration
	: function_definition {
			printf("\nFunction \"%s\" Definition\n", $1.topNode->u.ident.id);
			traverseAST($1.topNode, 0);
			function_block($1.botNode->u.function.body);
		}
	| declaration {
			if(print_decl) traverseAST($1.topNode, 0);
		}
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement {printf("func1\n");}
	| declaration_specifiers declarator compound_statement {
			if($2.botNode->type == FUNCTION_NODE && $2.topNode->type == IDENT_NODE) {
				if($1.botNode->type == SCALAR_NODE) {
					$2.botNode->next = $1.botNode; //set return type
					$2.botNode->u.function.body = $3.topNode;
				}
			} else {
				printf("Expected function declarator!\n");
			}
			$$ = $2;
		}
	| declarator declaration_list compound_statement {printf("func3\n");}
	| declarator compound_statement {
			if($1.botNode->type == FUNCTION_NODE && $1.topNode->type == IDENT_NODE) {
				node* t = ast_newNode(SCALAR_NODE);
				t->u.scalar.type = S_INT; //default return type;
				$1.botNode->next = t; //set return type
				$1.botNode->u.function.body = $2.topNode;
			} else {
				printf("Expected function declarator!\n");
			}
			$$ = $1;
		}
	;

%%

node* doIdentThing(char* id) { //identifier declared
	node* n = ast_newNode(IDENT_NODE);
	n->u.ident.ns = currentNamespace;
	n->u.ident.line = line;
	n->u.ident.id = id;
	//TODO: dont install if unnamed struct
	if(!containsSymbol(currentTable, id)) {
		installSymbol(currentTable, id);
		setNode(currentTable, id, n);
		return n;
	} else {
		char* buf = malloc(1024);
		sprintf(buf, "Redeclaration of variable %s", id);
		yyerror(buf);
		return NULL;
	}
}

void doScopeThing() {
	if(currentTable -> scope == GLOBAL_SCOPE) {
		currentTable = enterScope(FUNCTION_SCOPE, line, filename, currentTable);
	} else {
		currentTable = enterScope(BLOCK_SCOPE, line, filename, currentTable);
	}
}

void traverseAST(node* n, int tabs) { //Recursively print AST
	int i;
	if(n != NULL) {
		for(i=0; i<tabs; i++) printf("\t");
		printf("Node Type %i (%s)\n", n->type, nodeText[n->type]);
		if(n->type == BINOP_NODE) {
			for(i=0; i<tabs; i++) printf("\t");
			printf("Binary Type %i (%s)\n", n->u.binop.type, binopText[n->u.binop.type]);
			for(i=0; i<tabs; i++) printf("\t");
			printf("Binary Left Operand\n");
			traverseAST(n->u.binop.left, tabs+1);
			for(i=0; i<tabs; i++) printf("\t");
			printf("Binary Right Operand\n");
			traverseAST(n->u.binop.right, tabs+1);
		} else if(n->type == UNOP_NODE) {
			for(i=0; i<tabs; i++) printf("\t");
			printf("Unary Type %i (%s)\n", n->u.unop.type, unopText[n->u.unop.type]);
			for(i=0; i<tabs; i++) printf("\t");
			printf("Unary Operand\n");
			traverseAST(n->u.unop.operand, tabs+1);
		} else if(n->type == ASSIGN_NODE) {
			for(i=0; i<tabs; i++) printf("\t");
			printf("Assign Type %i (%s)\n", n->u.assign.type, assignText[n->u.assign.type]);
			for(i=0; i<tabs; i++) printf("\t");
			printf("Assign Left\n");
			traverseAST(n->u.assign.left, tabs+1);
			for(i=0; i<tabs; i++) printf("\t");
			printf("Assign Right\n");
			traverseAST(n->u.assign.right, tabs+1);
		} else if(n->type == NUMBER_NODE) {
			for(i=0; i<tabs; i++) printf("\t");
			printf("Number value %lli\n", n->u.number.value);
		} else if(n->type == IDENT_NODE) {
			for(i=0; i<tabs; i++) printf("\t");
			printf("Identifier \"%s\"\n", n->u.ident.id);
			traverseAST(n->next, tabs+1);
		} else if(n->type == SCALAR_NODE) {
			for(i=0; i<tabs; i++) printf("\t");
			printf("Scalar type %s\n", scalarText[n->u.scalar.type]);
		} else if(n->type == POINTER_NODE) {
			for(i=0; i<tabs; i++) printf("\t");
			printf("Pointer to\n");
			traverseAST(n->next, tabs+1);
		} else if(n->type == ARRAY_NODE) {
			for(i=0; i<tabs; i++) printf("\t");
			printf("Array of length %i containing \n", n->u.array.length);
			traverseAST(n->next, tabs+1);
		} else if(n->type == IF_NODE) {
			for(i=0; i<tabs; i++) printf("\t");
			printf("If Statement Condition\n");
			traverseAST(n->u.if_stmt.condition, tabs+1);
			for(i=0; i<tabs; i++) printf("\t");
			printf("If Statement Body\n");
			traverseAST(n->u.if_stmt.if_block, tabs+1);
		} else if(n->type == FOR_NODE) {
			for(i=0; i<tabs; i++) printf("\t");
			printf("For Loop Initializer\n");
			traverseAST(n->u.for_stmt.init, tabs+1);
			for(i=0; i<tabs; i++) printf("\t");
			printf("For Loop Condition\n");
			traverseAST(n->u.for_stmt.condition, tabs+1);
			for(i=0; i<tabs; i++) printf("\t");
			printf("For Loop Afterthought\n");
			traverseAST(n->u.for_stmt.afterthought, tabs+1);
			for(i=0; i<tabs; i++) printf("\t");
			printf("For Loop Body\n");
			traverseAST(n->u.for_stmt.body, tabs+1);
		} else if(n->type == LIST_NODE) {
			traverseAST(n->u.list.start, tabs+1);
			if(n->next && n->next->type == LIST_NODE) {
				traverseAST(n->next, tabs);
			}
		} else if(n->type == JUMP_NODE) {
			for(i=0; i<tabs; i++) printf("\t");
			switch(n->u.jump.type) {
				case GOTO_JP:
					printf("Jump Type GOTO\n");
					break;
				case CONTINUE_JP:
					printf("Jump Type CONTINUE\n");
					break;
				case BREAK_JP:
					printf("Jump Type BREAK\n");
					break;
				case RETURN_JP:
					printf("Jump Type RETURN\n");
					if(n->u.jump.target) {
						for(i=0; i<tabs; i++) printf("\t");
						printf("Return Target\n");
						traverseAST(n->u.jump.target, tabs+1);
					}
					break;
			}
		} else if(n->type == CALL_NODE) {
			int argnum = n->u.call.argnum;
			for(i=0; i<tabs; i++) printf("\t");
			printf("%i Arguments\n", argnum);
			if(argnum) {
				traverseAST(n->u.call.args, tabs+1);
			}
		} else if(n->type == FUNCTION_NODE) {
			for(i=0; i<tabs; i++) printf("\t");
			traverseAST(n->u.function.body, tabs+1);
		} else {
			for(i=0; i<tabs; i++) printf("\t");
			printf("Something else?\n");
		}
	} else {
		for(i=0; i<tabs; i++) printf("\t");
		printf("WARNING: NULL NODE PTR\n");
	}
	return;
}

void yyerror(const char* s) {
	fprintf(stderr, "Error: %s on line %i\n", s, line);
}

int main(int argc, char** argv) {
	printf("[C--, The Shitty C Parser]\n");
	strcpy(filename, "Placeholder.c");
	currentTable = enterScope(GLOBAL_SCOPE, 0, "TestFileName.c", NULL);
	yyparse();
	return 0;
}
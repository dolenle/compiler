/*%define parse.error verbose*/
%debug
%{
#include "globls.h"
#include "syms.h"
#include "ast.h"
#include "print.h"
#include <stdio.h>
#include <stdlib.h>

#define YYDEBUG 1
int yydebug = 0;
int print_decl = 0;

void yyerror(const char* s);

void doScopeThing();
node* doIdentThing(char* id);
void traverseAST(node* start, int tabs);

void initAST(struct ast *a);
struct ast prependNode(struct ast a, node* t);
struct ast appendNode(struct ast a, node* t);
struct ast prependAST(struct ast a, struct ast b);
struct ast appendAST(struct ast a, struct ast b);

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

%left ELSE
%left IF

%type <astNode> type_specifier storage_class_specifier primary_expression cast_expression
multiplicative_expression shift_expression relational_expression equality_expression
logical_or_expression logical_and_expression additive_expression assignment_expression
unary_expression postfix_expression expression and_expression exclusive_or_expression
inclusive_or_expression declaration_or_statement conditional_expression
expression_statement statement selection_statement

%type <ast> init_declarator init_declarator_list declarator direct_declarator pointer
declaration_specifiers declaration_or_statement_list declaration compound_statement

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
					printf("Symbol found in outer scope\n");
					$$ = getNode(parent, $1);
				} else {
					yyerror("Symbol not found");
				}
			}
		}
	| NUMBER {
			$$ = ast_newNode(NUMBER_NODE);
			printf("Number Node\n");
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
	| '(' expression ')' {}
	;
	
postfix_expression
	: primary_expression {
			//$$ = appendNode($$, $1);
			$$=$1;
		}
	| postfix_expression '[' expression ']' {
		//CONVERT TO *(E1+E2)
		$$ = ast_newNode(UNOP_NODE);
		$$->u.unop.type = DEREF_OP;
		node *n = ast_newNode(BINOP_NODE);
		$$->u.unop.operand = n;
		n->u.binop.type = PLUS_OP;
		n->u.binop.lvalue = $1;
		n->u.binop.rvalue = $3;
	}
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')'
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
	: assignment_expression
	| argument_expression_list ',' assignment_expression
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
	| SIZEOF unary_expression {}
	| SIZEOF '(' type_name ')' {}
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
			$$->u.binop.lvalue = $1;
			$$->u.binop.rvalue = $3;
		}
	| multiplicative_expression '/' cast_expression {
			$$ = ast_newNode(BINOP_NODE);
			$$->u.binop.type = DIV_OP;
			$$->u.binop.lvalue = $1;
			$$->u.binop.rvalue = $3;
		}
	| multiplicative_expression '%' cast_expression {
			node* n = ast_newNode(BINOP_NODE);
			$$->u.binop.type = MULT_OP;
			$$->u.binop.lvalue = $1;
			$$->u.binop.rvalue = $3;
		}
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression {
			$$ = ast_newNode(BINOP_NODE);
			$$->u.binop.type = PLUS_OP;
			$$->u.binop.lvalue = $1;
			$$->u.binop.rvalue = $3;
		}
	| additive_expression '-' multiplicative_expression {
			$$ = ast_newNode(BINOP_NODE);
			$$->u.binop.type = MINUS_OP;
			$$->u.binop.lvalue = $1;
			$$->u.binop.rvalue = $3;
		}
	;

shift_expression
	: additive_expression
	| shift_expression SHL additive_expression {
			$$ = ast_newNode(BINOP_NODE);
			$$->u.binop.type = SHL_OP;
			$$->u.binop.lvalue = $1;
			$$->u.binop.rvalue = $3;
		}
	| shift_expression SHR additive_expression {
			$$ = ast_newNode(BINOP_NODE);
			$$->u.binop.type = SHR_OP;
			$$->u.binop.lvalue = $1;
			$$->u.binop.rvalue = $3;
		}
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression {
			$$ = ast_newNode(BINOP_NODE);
			$$->u.binop.type = LT_OP;
			$$->u.binop.lvalue = $1;
			$$->u.binop.rvalue = $3;
		}
	| relational_expression '>' shift_expression {
			$$ = ast_newNode(BINOP_NODE);
			$$->u.binop.type = GT_OP;
			$$->u.binop.lvalue = $1;
			$$->u.binop.rvalue = $3;
		}
	| relational_expression LTEQ shift_expression {
			$$ = ast_newNode(BINOP_NODE);
			$$->u.binop.type = LTEQ_OP;
			$$->u.binop.lvalue = $1;
			$$->u.binop.rvalue = $3;
		}
	| relational_expression GTEQ shift_expression {
			$$ = ast_newNode(BINOP_NODE);
			$$->u.binop.type = GTEQ_OP;
			$$->u.binop.lvalue = $1;
			$$->u.binop.rvalue = $3;
		}
	;

equality_expression
	: relational_expression
	| equality_expression EQEQ relational_expression {
			$$ = ast_newNode(BINOP_NODE);
			$$->u.binop.type = EQEQ_OP;
			$$->u.binop.lvalue = $1;
			$$->u.binop.rvalue = $3;
		}
	| equality_expression NOTEQ relational_expression {
			$$ = ast_newNode(BINOP_NODE);
			$$->u.binop.type = NOTEQ_OP;
			$$->u.binop.lvalue = $1;
			$$->u.binop.rvalue = $3;
		}
	;

and_expression
	: equality_expression
	| and_expression '&' equality_expression {
			$$ = ast_newNode(BINOP_NODE);
			$$->u.binop.type = AND_OP;
			$$->u.binop.lvalue = $1;
			$$->u.binop.rvalue = $3;
		}
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression {
			$$ = ast_newNode(BINOP_NODE);
			$$->u.binop.type = XOR_OP;
			$$->u.binop.lvalue = $1;
			$$->u.binop.rvalue = $3;
		}
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression {
			$$ = ast_newNode(BINOP_NODE);
			$$->u.binop.type = IOR_OP;
			$$->u.binop.lvalue = $1;
			$$->u.binop.rvalue = $3;
		}
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression LOGAND inclusive_or_expression {
			$$ = ast_newNode(BINOP_NODE);
			$$->u.binop.type = LOGAND_OP;
			$$->u.binop.lvalue = $1;
			$$->u.binop.rvalue = $3;
		}
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression LOGOR logical_and_expression {
			$$ = ast_newNode(BINOP_NODE);
			$$->u.binop.type = LOGOR_OP;
			$$->u.binop.lvalue = $1;
			$$->u.binop.rvalue = $3;
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
				
				if(print_decl) {
					printf("\n$$ PRINTOUT\n");
					node* tmp = $$.topNode;
					while(tmp!= $$.botNode) {
						printf("Declarator Node Type %i (%s)\n", tmp->type, nodeText[tmp->type]);
						if(tmp->type == IDENT_NODE)
							printf("id = %s\n", tmp->u.ident.id);
						tmp = tmp->next;
					}
					printf("Declarator Node Type %i (%s)\n", tmp->type, nodeText[tmp->type]);
				}
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
	| type_qualifier {yyerror("Unimplemented Type Qualifier");}
	| type_qualifier declaration_specifiers {yyerror("Unimplemented Type Qualifier");}
	;

init_declarator_list
	: init_declarator {$$ = $1;}
	| init_declarator_list ',' init_declarator {
			if(!$3.errorFlag) {
				$$ = appendAST($1, $3);
			}
		}
	;

init_declarator
	: declarator {$$ = $1;}
	| declarator '=' initializer {yyerror("Unimplemented initialized declarator");}
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
	: assignment_expression {/*NOT IMPLEMENTED*/}
	| '{' initializer_list '}' {}
	| '{' initializer_list ',' '}' {}
	;

initializer_list
	: initializer
	| initializer_list ',' initializer
	;

statement
	: labeled_statement {yyerror("Unimplemented Labels");}
	| compound_statement {$$ = $1.topNode;}
	| expression_statement {/*do/for/while*/}
	| selection_statement {/*switch and if stmt*/}
	| iteration_statement {/*do/for/while*/}
	| jump_statement {/*goto, return and break*/}
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
			printf("\n$$ PRINTOUT\n");
			
			node* tmp = $$.topNode;
			while(tmp!= $$.botNode) {
				printf("Node Type %i (%s)\n", tmp->type, nodeText[tmp->type]);
				if(tmp->type == LIST_NODE) {
					node* n = tmp->u.list.start;
					traverseAST(n, 1);
				}
				tmp = tmp->next;
			}
			printf("Node Type %i (%s)\n", tmp->type, nodeText[tmp->type]);
			traverseAST(tmp->u.list.start, 1);
		}
	;

declaration_or_statement_list
	: declaration_or_statement {
			node* n = ast_newNode(LIST_NODE);
			n->u.list.start = $1;
			initAST(&$$);
			$$ = appendNode($$, n);
		}
	| declaration_or_statement_list declaration_or_statement {
			node* n = ast_newNode(LIST_NODE);
			n->u.list.start = $2;
			$$ = appendNode($1, n);
		}
	;

declaration_or_statement
	: declaration {$$ = $1.topNode;}
	| statement
	;

expression_statement
	: ';' {}
	| expression ';' {$$ = $1;};
	;

selection_statement
	: IF '(' expression ')' statement {
			$$ = ast_newNode(IF_NODE);
			$$->u.if_stmt.condition = $3;
			$$->u.if_stmt.if_block = $5;
		}
	| IF '(' expression ')' statement ELSE statement {
			$$ = ast_newNode(IFELSE_NODE);
			$$->u.ifelse_stmt.condition = $3;
			$$->u.ifelse_stmt.if_block = $5;
			$$->u.ifelse_stmt.else_block = $7;
		}
	| SWITCH '(' expression ')' statement {yyerror("Unimplemented switch statement");}
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
	: declaration_specifiers declarator declaration_list compound_statement {printf("func1\n");}
	| declaration_specifiers declarator compound_statement {printf("func2\n");}
	| declarator declaration_list compound_statement {printf("func3\n");}
	| declarator compound_statement {printf("func4\n");}
	;

%%
void initAST(struct ast *a) {
	a->topNode = NULL;
	a->botNode = NULL;
	a->errorFlag = 0;
}

struct ast prependNode(struct ast a, node* t) {
	node* currentTop = a.topNode;
	t->next = currentTop;
	a.topNode = t;
	if(!a.botNode) {
		a.botNode = t;
	}
	return a;
}

struct ast appendNode(struct ast a, node* t) {
	if(a.botNode) {
		node* currentBot = a.botNode;
		currentBot->next = t;
	}
	a.botNode = t;
	if(!a.topNode) {
		a.topNode = t;
	}
	return a;
}

struct ast prependAST(struct ast a, struct ast b) {
	a = prependNode(a, b.botNode);
	a.topNode = b.topNode;
	return a;
}

struct ast appendAST(struct ast a, struct ast b) {
	a = appendNode(a, b.topNode);
	a.botNode = b.botNode;
	return a;
}

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

void traverseAST(node* n, int tabs) {
	int i;
	for(i=0; i<tabs; i++) printf("\t");
	printf("Node Type %i (%s)\n", n->type, nodeText[n->type]);
	if(n->type == BINOP_NODE) {
		for(i=0; i<tabs; i++) printf("\t");
		printf("Binary Type %i\n", n->u.binop.type);
		for(i=0; i<tabs; i++) printf("\t");
		printf("Binary Left\n");
		traverseAST(n->u.binop.lvalue, tabs+1);
		for(i=0; i<tabs; i++) printf("\t");
		printf("Binary Right\n");
		traverseAST(n->u.binop.rvalue, tabs+1);
	} else if(n->type == UNOP_NODE) {
		for(i=0; i<tabs; i++) printf("\t");
		printf("Unary Type %i\n", n->u.unop.type);
		for(i=0; i<tabs; i++) printf("\t");
		printf("Unary Operand\n");
		traverseAST(n->u.unop.operand, tabs+1);
	} else if(n->type == ASSIGN_NODE) {
		for(i=0; i<tabs; i++) printf("\t");
		printf("Assign Type %i\n", n->u.assign.type);
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
		printf("Identifier %s\n", n->u.ident.id);
		traverseAST(n->next, tabs+1);
	} else if(n->type == SCALAR_NODE) {
		for(i=0; i<tabs; i++) printf("\t");
		printf("Scalar type %s\n", scalarText[n->u.scalar.type]);
	} else if(n->type == IF_NODE) {
		for(i=0; i<tabs; i++) printf("\t");
		printf("If Statement Condition\n");
		traverseAST(n->u.if_stmt.condition, tabs+1);
		for(i=0; i<tabs; i++) printf("\t");
		printf("If Statement Body\n");
		traverseAST(n->u.if_stmt.if_block, tabs+1);
	} else {
		for(i=0; i<tabs; i++) printf("\t");
		printf("Something else?\n");
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
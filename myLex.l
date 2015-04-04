/* ECE466 Compilers Lexical Analysis
 * Dolen Le
*/

%{
#include <string.h>
#include <stdlib.h>
#include "myParser.tab.h"

#define SIZE 1024
#define OPCHAR -2

int line = 1;

static char filename[SIZE];

YYSTYPE yylval;
%}

%x intmode realmode directmode charmode charmode_end stringmode
%option noyywrap

letter [a-zA-z]
digit [0-9]
decimal [1-9][0-9_]*
octal 0[0-7]+
hex 0[xX][0-9]*[a-fA-F]*[0-9]*
alphanumeric [a-zA-z0-9]
zero 0+

unsignedlong 		([uU]|[lL])+
unsignedlonglong	([uU][lL][lL])|([lL][lL][uU])
%%

	/*keyword matching*/
auto		{return AUTO;}
break		{return BREAK;}
case		{return CASE;}
char		{return CHAR;}
const		{return CONST;}
continue	{return CONTINUE;}
default		{return DEFAULT;}
do			{return DO;}
double		{return DOUBLE;}
else		{return ELSE;}
enum		{return ENUM;}
extern		{return EXTERN;}
float		{return FLOAT;}
for			{return FOR;}
goto		{return GOTO;}
if			{return IF;}
inline		{return INLINE;}
int			{return INT;}
long		{return LONG;}
register	{return REGISTER;}
restrict	{return RESTRICT;}
return		{return RETURN;}
short		{return SHORT;}
signed		{return SIGNED;}
sizeof		{return SIZEOF;}
static		{return STATIC;}
struct		{return STRUCT;}
switch		{return SWITCH;}
typedef		{return TYPEDEF;}
union		{return UNION;}
unsigned	{return UNSIGNED;}
void		{return VOID;}
volatile	{return VOLATILE;}
while		{return WHILE;}
_Bool		{return _BOOL;}
_Complex	{return _COMPLEX;}
_Imaginary	{return _IMAGINARY;}

	/*operator matching*/
"++"		{return PLUSPLUS;}
"--"		{return MINUSMINUS;}
"..."		{return ELLIPSIS;}
"=="		{return EQEQ;}
"!="		{return NOTEQ;}
"+="		{return PLUSEQ;}
"-="		{return MINUSEQ;}
"/="		{return DIVEQ;}
"*="		{return TIMESEQ;}
"^="		{return XOREQ;}
"|="		{return OREQ;}
"&="		{return ANDEQ;}
"%="		{return MODEQ;}
"->"		{return INDSEL;}
"&&"		{return LOGAND;}
"||"		{return LOGOR;}
"<="		{return LTEQ;}
">="		{return GTEQ;}
"<<="		{return SHLEQ;}
"<<"		{return SHL;}
">>="		{return SHREQ;}
">>"		{return SHR;}

	/*filename matching*/
#[ ]{decimal}[ ]\"					{BEGIN(directmode); line = atoi(yytext+2);}
<directmode>[^<].*\.{letter}		strncpy(filename, yytext, SIZE-1);
<directmode>\"\n?					BEGIN(INITIAL);
#[ ]{digit}[ ]\"<.*				/*do nothing*/

	/*char op matching*/
\[|\]|\{|\}|\(|\)|\.|\+|\-|&|\*|~|!|\/|%|<|>|\^|\||\?|:|;|,|=	{return *yytext;}

	/*number matching*/
<INITIAL>{decimal}|{hex}|{octal}|{zero} {
	BEGIN(intmode);
	yylval.num.typeFlag=INT_T;
	yylval.num.signFlag=SIGNED_T;
	yylval.num.intBuff=strtoll(yytext, NULL, 0);
}
<intmode>{
	[uU]				{BEGIN(INITIAL); yylval.num.signFlag=UNSIGNED_T; return NUMBER;}
	[lL]				{BEGIN(INITIAL); yylval.num.typeFlag=LONG_T; return NUMBER;}
	[lL][lL]			{BEGIN(INITIAL); yylval.num.typeFlag=LONGLONG_T; return NUMBER;}
	{unsignedlonglong}	{BEGIN(INITIAL); yylval.num.signFlag=UNSIGNED_T; yylval.num.typeFlag=LONGLONG_T; return NUMBER;}
	{unsignedlong}		{BEGIN(INITIAL); yylval.num.signFlag=UNSIGNED_T; yylval.num.typeFlag=LONG_T; return NUMBER;}
}

<INITIAL>({decimal}|{zero})*((\.{digit}*)|[eE](\+?|\-?){digit}+)|(({hex}|{octal})[pP](\+?|\-?){digit}+) {
	//printf("----%s\n",yytext);
	BEGIN(realmode);
	yylval.num.typeFlag=DOUBLE;
	yylval.num.realBuff=atof(yytext);
}
<realmode>{
	[fF]				{BEGIN(INITIAL); yylval.num.typeFlag=FLOAT_T; return NUMBER;}
	[lL]				{BEGIN(INITIAL); yylval.num.typeFlag=LONGDOUBLE_T; return NUMBER;}
}
<intmode,realmode>.|\n	{BEGIN(INITIAL); unput(*yytext); return NUMBER;}

[A-Za-z_][A-Za-z0-9_]*	{yylval.stringBuff=strdup(yytext); return IDENT;}

\n	{line++;}

 /*char literals*/
L?\'	BEGIN(charmode);
<charmode>{
	\'		{fprintf(stderr, "Empty char at line %d\n", line);}
	\\0		{yylval.charBuff=*yytext; BEGIN(charmode_end);}
	\\a		{yylval.charBuff=*yytext; BEGIN(charmode_end);}
	\\b		{yylval.charBuff=*yytext; BEGIN(charmode_end);}
	\\f		{yylval.charBuff=*yytext; BEGIN(charmode_end);}
	\\n		{yylval.charBuff=*yytext; BEGIN(charmode_end);}
	\\r		{yylval.charBuff=*yytext; BEGIN(charmode_end);}
	\\t		{yylval.charBuff=*yytext; BEGIN(charmode_end);}
	\\v		{yylval.charBuff=*yytext; BEGIN(charmode_end);}
	\\'		{yylval.charBuff=*yytext; BEGIN(charmode_end);}
	\\\"	{yylval.charBuff=*yytext; BEGIN(charmode_end);}
	\\\?	{yylval.charBuff=*yytext; BEGIN(charmode_end);}
	\\\\	{yylval.charBuff=*yytext; BEGIN(charmode_end);}
	.		{yylval.charBuff=*yytext; BEGIN(charmode_end);}
}
<charmode_end>\'	{BEGIN(INITIAL); return CHARLIT;}
<charmode_end>.|\n	{fprintf(stderr, "Expected ' on line %d\n", line);}


 /*string literals*/
L?\"	BEGIN(stringmode);
<stringmode>{
	\\0		{strcat(yylval.stringBuff, "\\0");}
	\\a		{strcat(yylval.stringBuff, "\\a");}
	\\b		{strcat(yylval.stringBuff, "\\b");}
	\\f		{strcat(yylval.stringBuff, "\\f");}
	\\n		{strcat(yylval.stringBuff, "\\n");}
	\\r		{strcat(yylval.stringBuff, "\\r");}
	\\t		{strcat(yylval.stringBuff, "\\t");}
	\\v		{strcat(yylval.stringBuff, "\\v");}
	\\\"	{strcat(yylval.stringBuff, "\\\"");}
	\\		{strcat(yylval.stringBuff, "\\");}
	\\\?	{strcat(yylval.stringBuff, "?");}
	\\[0-7]{1,3}		{
							char s[6] = "\\377";
							int x = strtoll(yytext+1,NULL,8);
							if(x<255) {
								char c = (char) x;
								if(isprint(c)) {
									s[0]=c;
									s[1]=0;
								} else {
									sprintf(s, "\\%03o", x);
								}
							} else {
								fprintf(stderr, "Octal sequence too long on line %d\n", line);
							}
							strcat(yylval.stringBuff,s);
						}
	\\x[0-9a-fA-F]+		{
							yytext[0]='0';
							char s[6]="\\377";
							int x=strtoll(yytext, NULL, 0);
							if(x<255) {
								char c = (char) x;
								if(isprint(c)) {
									s[0]=c;
									s[1]=0;
								} else {
									sprintf(s, "\\%03o", x);
								}
							} else {
								fprintf(stderr, "Hex sequence too long on line %d\n", line);
							}
							strcat(yylval.stringBuff,s);
						}
	\"		{BEGIN(INITIAL); return STRING;}
	.		{strcat(yylval.stringBuff, yytext);}
}

<charmode,stringmode>{
	
}

[ \t\n\r]
.	{fprintf(stderr, "Foobar on line %d: %s\n", line, yytext);}
%%



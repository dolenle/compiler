parser: myParser.tab.o lex.yy.o syms.o hash.o
	gcc -o parser myParser.tab.o lex.yy.o syms.o hash.o

lex.yy.o: myLex.l
	flex myLex.l
	gcc -c lex.yy.c

myParser.tab.o: myParser.y
	bison -vd myParser.y
	gcc -c myParser.tab.c
	
syms: hash.o syms.c syms.h
	gcc -o syms syms.c hash.o
	
syms.o: syms.c syms.h
	gcc -c syms.c

hash.o: hash.c hash.h
	gcc -c hash.c

clean: rm *.o myParser.tab.* lex.yy.* *.out
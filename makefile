c--: myParser.tab.o lex.yy.o syms.o hash.o ast.o quad.o asm.o
	gcc -o c-- myParser.tab.o lex.yy.o syms.o hash.o ast.o quad.o asm.o

tester: tester.o syms.o hash.o
	gcc -o tester tester.o syms.o hash.o
	
lex.yy.o: myLex.l
	flex myLex.l
	gcc -c lex.yy.c

myParser.tab.o: myParser.y
	bison -vd myParser.y
	gcc -c myParser.tab.c

asm.o: asm.c asm.h ast.h quad.h
	gcc -c asm.c

quad.o: quad.c quad.h ast.h
	gcc -c quad.c
	
tester.o: tester.c syms.o
	gcc -c tester.c
	
syms: hash.o syms.c syms.h ast.h
	gcc -o syms syms.c hash.o
	
syms.o: syms.c syms.h
	gcc -c syms.c

hash.o: hash.c hash.h
	gcc -c hash.c
	
ast.o: ast.c ast.h
	gcc -c ast.c

clean: rm *.o myParser.tab.* lex.yy.* *.out

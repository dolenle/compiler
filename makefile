scc: myParser.tab.o lex.yy.o syms.o hash.o ast.o quad.o asm.o
	gcc -m32 -o c-- myParser.tab.o lex.yy.o syms.o hash.o ast.o quad.o asm.o

tester: tester.o syms.o hash.o
	gcc -m32 -o tester tester.o syms.o hash.o
	
lex.yy.o: myLex.l
	flex myLex.l
	gcc -m32 -c lex.yy.c

myParser.tab.o: myParser.y
	bison -vd myParser.y
	gcc -m32 -c myParser.tab.c

asm.o: asm.c asm.h ast.h quad.h
	gcc -m32 -c asm.c

quad.o: quad.c quad.h ast.h
	gcc -m32 -c quad.c
	
tester.o: tester.c syms.o
	gcc -m32 -c tester.c
	
syms: hash.o syms.c syms.h ast.h
	gcc -m32 -o syms syms.c hash.o
	
syms.o: syms.c syms.h
	gcc -m32 -c syms.c

hash.o: hash.c hash.h
	gcc -m32 -c hash.c
	
ast.o: ast.c ast.h
	gcc -m32 -c ast.c

clean: rm *.o myParser.tab.* lex.yy.* *.out

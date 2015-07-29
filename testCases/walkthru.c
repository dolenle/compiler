int x, a1[10];
char* name;

main() {
	x = 0;
	printf("Welcome to C--, the Shitty C Compiler.\n");
	printf("I will show you what this compiler can do...\n");
	printf("(It really isn't much.)\n");
	printf("To begin, enter your name: ");
	name = inputText();
	printf("Hello, %s!\n\n", name);
	
	printf("To start off, let's do some basic math.\n");
	printf("Simple operators are supported. If they weren't, the compiler would be named F--.\n");
	basics();
	
	printf("\nFunction calls work. Library functions printf() and scanf() are used here with arguments.\n");
	printf("Function prototypes and function definitions with parameters are not implemented, however.\n");
	
	printf("\nLocally declared static variables can also be declared and used within their scope.\n");
	printf("The following function declares a static variable 'x' and toggles it each time it is called.\n");
	staticLocal();
	printf("\nCall the same function again...\n");
	staticLocal();
	
	printf("\nConditional statements (IF/WHILE/FOR) are supported, and can be nested.\n");
	printf("Short-circuit logical AND and OR are implemented, as is logical NOT.\n");
	printf("Switch statements are not implemented.\n");
	condExpr();
	
	printf("Pointers have already been implicitly used in previous demos, but here is an explicit example.\n");
	pointers();
	
	printf("\nThat's pretty much all there is to it. Goodbye, %s!", name);
}

inputInt() {
	int a;
	printf("Enter a non-negative integer: ");
	while(!scanf("%d", &a)) ;
	return a;
}

inputText() {
	char* buf;
	buf = malloc(100);
	while(!scanf("%s", buf)) ;
	return buf;
}

basics() {
	int i;
	printf("C-- only supports unsigned integers. No floats or negatives.\n");
	i = inputInt();
	int j;
	j = (7*(i+26)/3)%69-1;
	printf("(7*(%i+26)/3)%69-1 = %i\n",i,j);
	
	printf("\nBoolean expressions are also evaluated to 1 or 0.\n");
	i = inputInt();
	printf("!(%i > 50) = %i\n", i, !(i>50));
	
	printf("\nThe SIZEOF operator is implemented for integer, array, and pointer types.\n");
	printf("int k, a[10][3], *p;\n");
	int k, a[10][3], *p;
	printf("sizeof(k) = %i\n", sizeof(k));
	printf("sizeof(a) = %i\n", sizeof(a));
	printf("sizeof(p) = %i\n", sizeof(p));
	printf("sizeof(int*) = %i\n", sizeof(int*));
}

staticLocal() { //toggle x between 0 and 100
	static int xx;
	if(xx != 0) {
		xx = 0;
	} else {
		xx = 100;
	}
	printf("Local static variable x is %i\n", x);
}

condExpr() {
	int m;
	printf("Menu - enter one of the following:\n");
	printf("\t1 to demo IF-ELSE statements\n");
	printf("\t2 to demo WHILE loops\n");
	printf("\t3 to demo FOR loops\n");
	printf("\t4 to demo FOR loops and ARRAYS\n");
	printf("Enter 0 to leave this demo.\n");
	while(1) {
		printf("\n\n");
		m = inputInt();
		if(m == 1) {
			printf("Well this is already an if statement, but here's an IF-ELSE:\n");
			int x;
			x = inputInt();
			if(x>=20) {
				printf("%i is greater than or equal to 20\n", x);
			} else {
				int y;
				printf("Enter another number to compare with the previous...\n");
				y = inputInt();
				if(x < y) {
					printf("%i is less than %i\n", x, y);
				} else if (x==y) {
					printf("The two numbers are equal.\n");
				} else {
					printf("%i is greater than %i\n", x, y);
				}
			}
		} else if(m == 2) {
			printf("Again, this example already uses a WHILE loop.\n");
			printf("Here is an additional demo which increments a global variable.\n");
			int j;
			j = 0;
			int y;
			y = inputInt();
			printf("x is now %i\n", x);
			printf("Running loop...\n");
			while(j < y) {
				x++;
				j++;
			}
			printf("x is now %i\n", x);
			printf("You can try this option again and increase x further.\n");
		} else if(m == 3) {
			printf("Enter the number of iterations of Fibonacci numbers (FOR loop): ");
			int iterations;
			while(!scanf("%d", &iterations)) ;
			int i, a, b, c;
			a = 1;
			b = 1;
			for(i=0; i<iterations; i++) {
				c = a+b;
				a = b;
				b = c;
				printf("%i ", c);
			}
			printf("\n");
		} else if(m == 4) {
			printf("Setting the values of a locally declared array...\n");
			int factor;
			factor = inputInt();
			int arr[10];
			int y;
			for(y=0; y<10; y++) {
				arr[y] = y*factor;
			}
			for(y=0; y<10; y++) {
				printf("%i ", arr[y]);
			}
			printf("\n");
			printf("Copying to a globally declared array...\n");
			for(y=0; y<10; y++) {
				a1[y] = arr[y];
			}
			for(y=0; y<10; y++) {
				printf("%i ", a1[y]);
			}
			printf("\n");
			printf("Multidimensional arrays are not supported by C--.\n");
		} else if(m == 0) {
			printf("BREAK out of WHILE loop\n");
			break;
		} else {
			printf("Invalid option, try again: ");
		}
	}
}

pointers() {
	int *m;
	m = malloc(sizeof(int));
	int y;
	int z;
	printf("Setting and getting integer via pointer...\n");
	y = inputInt();
	*m = y;
	printf("(Assigning *m) *m is %i\n", *m);
	z = inputInt();
	m = &z;
	printf("(Assigning m) *m is %i\n", *m);
}
int a[10], *p;
char* user;
int x;
main() {
	printf("Welcome to C--, the Shitty C Compiler. Please enter your name: ");
	user = inputText();
	printf("Hello, %s!\n", user);
	
	printf("\nTesting basic operations...\n");
	basics();
	
	printf("\nTesting local static variable...\n");
	staticLocal();
	staticLocal();
	staticLocal();
	
	printf("\nTesting nested for loops...\n");
	nestedFor();
	
	printf("\nTesting pointers...\n");
	pointers();
	
	printf("\nTesting arrays and pointers...\n");
	arrayPtr();
	
	condExpr();
	
	printf("\nGoodbye, %s!\n", user);
}

basics() {
	int i;
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
	printf("Local static variable xx is %i\n", xx);
}

nestedFor() {
	int i,j;
	for(i=0; i<=10; i++) {
		for(j=0; j<=10; j++) {
			printf("%i\t", i*j);
		}
		printf("\n");
	}
}

inputInt() {
	int a;
	printf("Enter an integer: ");
	while(!scanf("%d", &a)) ;
	return a;
}

inputText() {
	char* buf;
	buf = malloc(100);
	while(!scanf("%s", buf)) ;
	return buf;
}

arrayPtr() {
	int i;
	printf("Setting array using for loop\n");
	for(i = 0; i<10; i++) {
		a[i] = i*2;
		printf("loop1: a[%i]=%i\n", i, a[i]);
	}
	printf("Copying array using memcpy()\n");
	int a2[10];
	memcpy(a2, a, sizeof(a));
	for(i = 0; i<10; i++) {
		printf("loop2: a2[%i]=%i\n", i, a2[i]);
	}
	p = &a[2];
	printf("a[2] = %i\n", *p);
	int* p2;
	p2 = &a2[2];
	printf("a2[2] = %i\n", *p2);
	if((*p2)/(*p) == 1) {
		printf("it should be equal...\n");
	} else {
		printf("You should not see this!!!\n");
	}
}

pointers() {
	int *m;
	m = malloc(sizeof(int));
	int y;
	int z;
	printf("Setting and getting number via pointer...\n");
	y = inputInt();
	*m = y;
	printf("(*m = %i) *m is %i\n", y, *m);
	z = inputInt();
	m = &z;
	printf("z = %i\n", z);
	printf("(m = &z) *m is %i\n", *m);
}

condExpr() {
	int m;
	printf("\nMenu - enter one of the following:\n");
	printf("\t1 to demo IF-ELSE statements\n");
	printf("\t2 to demo WHILE loops\n");
	printf("\t3 to demo FOR loops\n");
	printf("\t0 to leave this demo.\n");
	while(1) {
		printf("\n");
		
		m = inputInt();
		if(m == 1) {
			printf("Enter a number less than 20... ");
			int x;
			x = inputInt();
			if(x>=20) {
				printf("I said less than 20, you dingus\n");
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
			printf("This demo increments a global variable.\n");
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
		} else if(m == 0) {
			printf("Breaking out of WHILE loop\n");
			break;
		} else {
			printf("Invalid option, try again: ");
		}
	}
}

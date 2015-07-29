int a[10], *p;
char* s;
main() {
	int i;
	for(i = 0; i<10; i++) {
		a[i] = i*2;
	}
	int a2[10];
	memcpy(a2, a, sizeof(a));
	for(i = 0; i<10; i++) {
		printf("%i %i\n", a[i], a2[i]);
		a2[i] = a[i]*i;
	}
	memcpy(a, a2, sizeof(a));
	for(i = 0; i<10; i++) {
		printf("%i %i\n", a[i], a2[i]);
		a2[i] = a[i]*i;
	}
	p = &a[2];
	printf("a[2] = %i\n", *p);
	int* p2;
	p2 = &a2[2];
	printf("a2[2] = %i\n", *p2);
	if((*p2)/(*p) == 1) {
		printf("it should be equal...\n");
	}
}

int a2[10][20];
int x,y,z;
f() {
	z=a2[x][y];
}

// int x, ss;
// 
// main() {
// 	x = 2;
// 	printf("x=%i\n", x);
// 	ifTest();
// 	f();
// 	printf("now x=%i\n", x);
// 
// 	ifTest();
// 	ss = 0;
// 	ssEval();
// 	staticVar();
// 	staticVar();
// 	fibo();
// 	
// 	printf("\nTesting Pointers and Dynamic Memory\n");
// 	char* buf;
// 	buf = malloc(15);
// 	sprintf(buf, "hello world!\n");
// 	printf("This text was buffered: %s", buf);
// 	
// 	basics();
// 	
// 	while(1)
// 		printf("dolen is the man\n");
// }
// 
// arrays() {
// 	printf("\nTesting arrays\n");
// 	int arr[10];
// 	int y;
// 	for(y=0; y<10; y++) {
// 		arr[y] = y*2;
// 	}
// 	for(y=0; y<10; y++) {
// 		printf("%i\n",arr[y]);
// 	}
// }
// 
// f() {
// 	int i;
// 	for(i = 0; i<100; i++)
// 		x++;
// 	printf("f() has incremented x 100 times\n");
// }
// 
// ifTest() {
// 	int arg;
// 	arg = x;
// 	if(arg > 10) {
// 		printf("%i is greater than ten\n", arg);
// 	} else {
// 		printf("%i is less than or equal to ten\n", arg);
// 	}
// }
// 
// input()
// {
//    int a;
//    printf("Please enter a positive integer: ");
//    scanf("%d", &a);
//    printf("You entered: %d\n", a);
//    return a;
// }
// 
// ssEval() {
// 	printf("Testing short circuit evaluation\n");
// 	if(x<10 && ss++) {
// 		printf("ss=%i\n",ss);
// 		return;
// 	} else {
// 		printf("ss=%i\n",ss);
// 		x = 9;
// 		ssEval();
// 		return;
// 	}
// }
// 
// staticVar() {
// 	printf("Testing local static variable\n");
// 	static int v;
// 	if(v != 0) {
// 		v = 0;
// 	} else {
// 		v = 100;
// 	}
// 	printf("v=%i\n",v);
// }
// 
// fibo() {
// 	printf("Generating Fibonacci Sequence\n");
// 	int iterations;
// 	iterations = input();
// 	int i, a, b, c;
// 	a = 1;
// 	b = 1;
// 	for(i=0; i<iterations; i++) {
// 		c = a+b;
// 		a = b;
// 		b = c;
// 		printf("%i ", c);
// 	}
// 	printf("\n");
// }
// 
// basics() {
// 	printf("\nTesting basic operations\n");
// 	int i;
// 	i = input();
// 	int j;
// 	j = (7*(i+26)/3)%69-1;
// 	printf("(7*(%i+26)/3)%69-1 = %i\n",i,j);
// 	i = input();
// 	printf("!(%i > 100) = %i\n", i, !(i>100));
// }
// 
// g() {
// 	return 1;
// }
// 
// f() {
// 	int i;
// 	while(!g()) {
// 		i++;
// 	}
// }	
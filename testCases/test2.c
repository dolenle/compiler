int x;
int y;
f() {
	y = 123;
	for(x = 0; x<100; x++) {
		if(y < x) {
			y++;
		}
	}
	x=20;
}
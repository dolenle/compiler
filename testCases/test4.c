int x;
int y;
f() {
	y = 4;
	while(x < 100) {
		if(y-x > 9) {
			y=3;
		}
		x++;
	}
	x=1;
}
g() {
	x = 2;
	do {
		x++;
		if(x<100) {
			y = 7;
		} else {
			y = 4;
		}
		y-=2;
	} while(y>x);
	x=0;
}
h() {
	if(!x) {
		int z;
		z = 100;
		while(z>0) {
			while(x>0) {
				x--;
			}
		}
		y++;
	}
	return y;
}
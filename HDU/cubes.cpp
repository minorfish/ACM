#include <stdio.h>

const int N = 30005;

int p, f[N], c[N], num[N];

void init () {

	for (int i = 0; i < N; i++) {

		f[i] = i;
		c[i] = 0;
		num[i] = 1;
	}
}

int getfather (int x) {

	if ( x != f[x]) {

		int t = f[x];
		f[x] = getfather (f[x]);
		c[x] =  c[x] + c[t];

	}
	return f[x];
}

void unions (int p , int q) {

	f[p] = q;
	c[p] = num[q];
	num[q] += num[p];

}

int main () {
	
	scanf ("%d", &p);
	char s[10];
	int x, y;
	init ();
	while (p--) {

		scanf ("%s", s);
		if (s[0] == 'M') {

			scanf ("%d%d", &x, &y);
			int q = getfather (x);
			int p = getfather (y);
//			printf ("%d %d\n", q, p);
			if (p != q) 
				unions (p, q);

		} else {

			scanf ("%d", &x);
			int q = getfather (x);
//			printf ("%d %d\n", num[q], c[x]);
			printf ("%d\n", num[q] - c[x] - 1);
		}
	}
	return 0;
}

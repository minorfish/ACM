#include <stdio.h>

const int N = 50005;
int n, m, f[N], c[N];

void init () {

	for (int i = 0; i <= n; i++) {

		f[i] = i;
		c[i] = 0;
	}
}

int getfather (int x) {

	if (x != f[x]) {

		int t = f[x];
		f[x] = getfather (f[x]);
		c[x] = (c[x] + c[t]) % 3;
	}
	return f[x];
}

int main () {
	
	scanf ("%d%d", &n, &m);
	init ();
	int x, y, z, count = 0;
	for (int i = 0; i < m; i++) {
		
		scanf ("%d%d%d", &z, &x, &y);
		if (x > n || y > n) {

			count++;
			continue;
		}
		if (z == 2 && x == y) {
			
			count++;
		//	printf ("%d\n", i + 1);
			continue;
		}
		int p = getfather (x);
		int q = getfather (y);
		if (p == q) {

			if ( (c[x] + z - 1 + 3) % 3 != c[y])
				count ++;
		} else {

			f[q] = p;
			c[q] = (c[x] - c[y] + z - 1 + 3 ) % 3; 
		}
	}
				
	printf ("%d\n", count);	
	return 0;
}

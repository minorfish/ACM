#include <stdio.h>
#include <string.h>

const int N = 30005;
int n, m , t, f[N], c[N];

void init () {

	for (int i = 0; i <= n; i++ ) {

		f[i] = i;
		c[i] = 1;
	}
}
	
int  getfather (int x) {

 	return	f[x] = ( f[x] == x ) ? x : getfather (f[x]);
}

int main () {

	scanf ("%d", &t);
	while (t--) {
	
		scanf ("%d%d", &n, &m);
		int x, y;
		init();
		for (int i = 0; i < m; i++) {

			scanf ("%d%d", &x, &y);
			int p = getfather(x);
			int q = getfather(y);
			if (p !=  q){
				
				c[p] += c[q];
				f[q] = p;
			}

		}
		int max = 0;
		for (int i = 1; i <= n; i++)
			if (i == f[i] && max < c[i])
				max = c[i];
		printf ("%d\n", max);	

	}
	return 0;
}

#include <stdio.h>

const int N = 100005;
int t, n, m, f[N], c[N];

void init () {

	for (int i = 0; i <= n; i++) {

		f[i] = i;
		c[i] = 0;
	}
}

int getfather (int x) {

	if ( x == f[x] ) 
		return x;
	else  {

		int t = f[x];
		f[x] = getfather (f[x]);
		c[x] = (c[x] + c[t]) % 2;
		return f[x];
	}
}


int main () {

	scanf ("%d", &t);
	int x, y;
	while (t--) {

		scanf ("%d%d", &n, &m);
		init();
		char s[10];
		for (int i = 0; i < m; i++) {

			scanf ("%s", s);
			if (s[0] == 'D') {
				
				scanf ("%d%d", &x, &y);
				int p = getfather(x);
				int q = getfather(y);
				f[p] = q;
				c[p] = (c[y] + c[x] + 1) % 2;
			}
			else  {
	
				scanf ("%d%d", &x, &y);
				int p = getfather(x);
				int q = getfather(y);
				if (p != q)
					printf("Not sure yet.\n");
				else if (c[x] == c[y])
					printf ("In the same gang.\n");
				else
					printf ("In different gangs.\n");
			}

		}
	}
}

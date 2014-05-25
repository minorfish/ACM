#include <stdio.h>
#include <string.h>
#include <math.h>

const int N = 1005;

struct MAP {

	double xi, yi;
}s[N];

int f[N], fix[N], g[N][N], c[N], n;
double d;

double dis (double i, double j) {

	return sqrt(i * i + j * j);
}

int getfather ( int x) {

	return  f[x] = (x == f[x]) ? x : getfather (f[x]);
}

void init () {

	memset (fix, 0, sizeof (fix));
	memset (c, 0, sizeof (c));
	for (int i = 0; i <= n; i++)
		f[i] = i;
	for (int i = 1; i <= n; i++) {

		scanf ("%lf%lf", &s[i].xi, &s[i].yi);
		for (int j = 1; j < i; j++) {

			double di = dis (s[i].xi - s[j].xi, s[i].yi - s[j].yi);
			if (d - di >= -1e-9)  {

				g[i][c[i]++] = j;
				g[j][c[j]++] = i;
			}	
		}
	}
}

int main () {

		scanf ("%d%lf", &n, &d);

		init();		
		char str[10];
    	int x, y;
		while (scanf ("%s", str) == 1) {

			if (str[0] == 'O') {
				
				scanf ("%d", &x);
				fix[x] = 1;
				int p = getfather(x);
				for (int i = 0; i < c[x]; i++) {
					
					if (fix[g[x][i]] == 0)
						continue;
					int q = getfather(g[x][i]);
					if (p != q)
						f[q] = p;
				}

			}else {

				scanf ("%d%d", &x, &y);
				int p = getfather(x);
				int q = getfather(y);
				if (p == q)
					printf ("SUCCESS\n");
				else
					printf ("FAIL\n");
			}
		}
	
	return 0;
}

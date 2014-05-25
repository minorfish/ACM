#include <stdio.h>

const int N = 2005;

int f[N], value[N], n, m;

void init () {

	for (int i = 0; i <= n; i++) {

		f[i] = i;
		value[i] = 0;
	}
}

int getfather (int x) {

	if (x == f[x])  
		return x;
	else  {
		
		int t = f[x];
		f[x] = getfather (f[x]);
		value[x] = (value[x] + value[t]) % 2;
		return f[x];
	}
}

int main () {

	int cas = 0, t, x, y;
	bool flag = 0;
	scanf ("%d", &t);
	while (t--) {
		
		flag = 0;	
		scanf ("%d%d", &n, &m);
		init();
//		for (int i = 0; i <= n; i++)
//			printf ("%3d", f[i]);
//		printf ("\n");

		for (int i = 0; i < m; i++) {

			scanf ("%d%d", &x, &y);
			int p = getfather (x);
			int q = getfather (y);
			if (q != p) {

				f[p] = q;
				value[p] = (value[y] + 1 + value[x]) % 2;
			}
			else {
				
				if (value[x] == value[y])
					flag = 1;
			}

		}
		
//		for (int i = 1; i <= n; i++)
//			printf("%3d%3d\n", f[i], value[i]);

		printf ("Scenario #%d:\n", ++cas);
		if (flag)
			printf ("Suspicious bugs found!\n");
		else
			printf ("No suspicious bugs found!\n");
		if (t)
			printf ("\n");
	}
	return 0;
}

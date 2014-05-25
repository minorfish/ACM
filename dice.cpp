#include <stdio.h>
#include <string.h>
#include <math.h>

const int N = 205;
int s[N], n, m, vis[N];

int main () {
	
	while (scanf ("%d", &n ) == 1) {

		for (int i = 0; i < n; i++)
			scanf ("%d", &s[i]);
		scanf ("%d", &m);

		int x, m1 = m;
		memset (vis, 0, sizeof (vis));
		for (int i = 0; i < m; i++) {

			scanf ("%d", &x);
			if (!vis[x])
				vis[x] = 1;
			else
				m1--;
		}
		m = m1;
		double q =  (double) m/  (double) n;
		double a0 = 0;
		for (int i = 0; i < n; i++)
			a0 += s[i];
		a0 = a0 / n;	

		if (fabs(a0) == 0)
			printf ("0.00\n");
		else if (fabs(1 - q) < 1e-6)
			printf ("inf\n");
		else 
			printf ("%.2f\n", a0 / ( 1 - q ));
	}
	return 0;
}

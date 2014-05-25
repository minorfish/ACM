#include <stdio.h>

const int N = 50005;
int f[N];

void init (int n) {

	for (int i = 0; i <= n; i++)
		f[i] = i;
}

int getfather (int x) {

	return f[x] = (f[x] == x) ? x: getfather (f[x]);
}

int main () {

	int n, m, x, y, cas = 0;
	while ( scanf ("%d%d", &n, &m), n || m) {

		init(n);
		for (int i = 0; i < m; i++) {

			scanf ("%d%d", &x, &y);
			int p = getfather (x);
			int q = getfather (y);
			if (p != q)
				f[p] = q;

		}
		int count = 0;
		for (int i = 1; i <= n; i++)
			if (f[i] == i)
				count++;
		printf ("Case %d: %d\n", ++cas, count);
	}
	return 0;
}

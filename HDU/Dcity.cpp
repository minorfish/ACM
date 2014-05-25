#include <stdio.h>

const int N = 10005;
const int M = 100005;

int f[N], n, m, s[M][2], ans[M];

void init () {

	for (int i = 0; i < n; i++)
		f[i] = i;
}

int getfather(int x) {

	return  x == f[x] ? x: f[x] = getfather (f[x]);
}

int main () {
		
	while (scanf ("%d%d", &n, &m) != EOF) {
		
		init ();
		int temp = n;
		for (int i = 0; i < m; i++)
			scanf ("%d%d", &s[i][0], &s[i][1]);
		ans[m] = n;
		for (int i = m - 1; i >= 0; i--) {

			int p = getfather (s[i][0]);
			int q = getfather (s[i][1]);
			if (q == p)
				ans[i] = temp;
			else {

				f[p] = q;
				ans[i] = --temp;
			}
		}
		for (int i = 1; i <= m; i++)
			printf ("%d\n", ans[i]);
	}
	return 0;
}

#include <stdio.h>

const int N = 30005;

int f[N], c[N], group[N];

void init (int n) {

	for (int i = 0; i < n; i++) {
		
		f[i] = i;
		c[i] = 1;
	}
}

int getfather (int x) {

	return f[x] = (x == f[x] ) ? x :getfather (f[x]);
}

int main () {

	int n, m, num;
	while (scanf ("%d%d", &n, &m) , n || m) {

		init(n);
		for (int i = 0; i < m; i++) {
			
			scanf ("%d", &num);
			for (int j = 0; j < num; j++) 
				scanf ("%d", &group[j]);
			int r = getfather(group[0]);
			for (int j = 1; j < num; j++) {

				int p = getfather(group[j]);
				if (p != r) {

					if (!p) {

						f[r] = p;
						c[p] += c[r];
						r = p;
					}
					else {

						f[p] = r;
						c[r] += c[p];
					}
				}
			}
		}
		printf ("%d\n", c[0]);
	}
	return 0;	
}

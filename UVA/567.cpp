#include <cstdio>

const int maxn = 21;
const int INF = 0x3f3f3f3f;

int G[maxn][maxn];

void Floyd () {

	for (int k = 1; k < maxn; k++)
		for (int i = 1; i < maxn; i++)
			for (int j = 1; j < maxn; j++)
				if (G[i][j] > G[i][k] + G[k][j])
					G[i][j] = G[j][i] = G[i][k] + G[k][j];
}

int main () {

	int n, m, u, v, cas = 0;

	while (scanf ("%d", &n) != EOF) {
		
		for (int i = 1; i < maxn; i++)
			for (int j = 1; j < maxn; j++)
				G[i][j] = (i == j) ? 0 : INF;

		for (int i = 0; i < n; i++) {
			scanf ("%d", &v);
			G[1][v] = G[v][1] = 1;
		}

		for (int i = 2; i < 20; i++) {
			scanf ("%d", &n);
			for (int j = 0; j < n; j++) {
				scanf ("%d", &v);
				G[i][v] = G[v][i] = 1;
			}
		}	

		Floyd();

		scanf ("%d", &m);
		printf ("Test Set #%d\n", ++cas);
		while (m--) {
			
			scanf ("%d%d", &u, &v);
			printf ("%2d to %2d: %d\n", u, v, G[u][v]);
		}
		printf ("\n");

	}
	return 0;
}

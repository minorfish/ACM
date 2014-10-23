#include <cstdio>
#include <cstring>
#include <cstdlib>

typedef long long ll;
const int N = 205;
const int M = 35;
const ll INF = 1e13;

int n, m;
int d[N];
ll dis[N][N];
ll f[M][N];
int path[M][N][2];

void init () {

	int mid;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++) {
			dis[i][j] = 0;
			mid = (j + i) / 2;
			for (int k = i; k <= j; k++) 	
				dis[i][j] += labs (d[k] - d[mid]);
		}
}

void printf_ans (int k, int j) {

			if (!k)
				return;
			printf_ans (k - 1, path[k][j][1] - 1);
			if (path[k][j][1] != j)
				printf("Depot %d at restaurant %d serves restaurants %d to %d\n", k, path[k][j][0], path[k][j][1], j);
			else
				printf("Depot %d at restaurant %d serves restaurant %d\n", k, path[k][j][0], j);
				
}

int main () {

	int cas = 0;
	while (scanf ("%d%d", &n, &m) , n || m) {

		for (int i = 1; i <= n; i++)
			scanf ("%d", &d[i]);

		init ();	

		for (int i = 1; i <= n; i++) {

			f[1][i] = dis[1][i];
			path[1][i][0] = (1 + i) / 2;
			path[1][i][1] = 1; 
		}

		for (int k = 2; k <= m; k++)
			for (int j = k; j <= n; j++) {

				f[k][j] = INF;
				for (int i = j - 1; i >= k - 1; i--) {
					
					if (f[k - 1][i] + dis[i + 1][j] < f[k][j]) {
					
						f[k][j] = f[k - 1][i] + dis[i + 1][j];
						path[k][j][0] = (i + j + 1) / 2;
						path[k][j][1] = i + 1;
					}
				}
			}

		printf ("Chain %d\n", ++cas);
		printf_ans (m, n);
		printf ("Total distance sum = %lld\n\n", f[m][n]);
	}
	return 0;
}

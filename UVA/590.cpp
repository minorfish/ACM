#include <cstdio>
#include <cstring>

const int N = 15;
const int M = 35;
const int maxn = 1005;
const int INF = 0x3f3f3f3f;

int n, k;
int t[N][N];
int v[N][N][M];
int dp[maxn][N];
int Min (const int a, const int b) { return a < b? a: b; }

int main () {

	int cas = 0;
	while (scanf ("%d%d", &n, &k), n || k) {

		for (int i = 1; i <= n; i++) {	
			for (int j = 1; j <= n; j++) {

				if (i == j)
					continue;
				scanf ("%d", &t[i][j]);
				for (int d = 0; d < t[i][j]; d++) {

					scanf ("%d", &v[i][j][d]);
					if (v[i][j][d] == 0)
						v[i][j][d] = INF;
				}
			}
		}

		for (int i = 1; i <= k; i++)
			for (int j = 1; j <= n; j++)
				dp[i][j] = INF;

		for (int i = 2; i <= n; i++)
			dp[1][i] = v[1][i][0];

		for (int d = 2; d <= k; d++)
			for (int i = 1; i <= n; i++) 
				for (int j = 1; j <= n; j++) {

					if (i != j && dp[d - 1][j] != INF)
						dp[d][i] = Min (dp[d][i], dp[d - 1][j] + v[j][i][(d - 1) % t[j][i]]);
				}

		//printf ("%lld\n", INF);
		printf ("Scenario #%d\n", ++cas);
		if (dp[k][n] != INF)
			printf ("The best flight costs %d.\n\n", dp[k][n]);
		else
			printf ("No flight possible.\n\n");
	}

	return 0;
}

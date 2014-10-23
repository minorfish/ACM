#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 55;

double dp[maxn][maxn][maxn * maxn];

int main () {

	int T;
	int n, m;

	scanf ("%d", &T);
	while (T--) {

		dp[0][0][0] = 1;

		scanf ("%d%d", &n, &m);			
		
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) 
				for (int k = 0; k < i * j; k++) {
				
					dp[i][j][k + 1] = 0;
					dp[i][j][k + 1]	+= dp[i][j][k] * (i * j - k) / (n * m - k);
					//printf ("%.12lf\n", dp[i][j][k + 1]);
					if (i)
						dp[i][j][k + 1] += dp[i - 1][j][k] * (n - i + 1) * j/ (n * m - k); 
					if (j)
						dp[i][j][k + 1] += dp[i][j - 1][k] * (i * (m - j + 1)) / (n * m - k);
					if (i && j)
						dp[i][j][k + 1] += dp[i - 1][j - 1][k] * (n - i + 1) * (m - j + 1) / (n * m - k); 
				}

		double ans = max(n, m) * dp[n][m][max(n, m)];
		for (int k = max(n, m) + 1; k <= n * m; k++)
			ans += k * (dp[n][m][k] - dp[n][m][k - 1]);
		
		printf ("%.12lf\n", ans);
	}
	return 0;
}

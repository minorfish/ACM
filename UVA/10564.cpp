#include <cstdio>
#include <cstring>

const int N = 50;
const int maxn = 520;

typedef long long ll;

int n1[N][N];
int n2[N][N];
ll dp[maxn][N][N];
int n, s;

void printf_ans (int num, int x, int y) {

	if (x == 2 * n - 2)
		return;
	if (x == 0) {
		printf ("%d ", y);
	} 
	if (x < n - 1) {

		if (y && dp[num - n1[x][y]][x + 1][y - 1]) {
			printf ("L");
			printf_ans (num - n1[x][y], x + 1, y - 1);
		} else if (dp[num - n1[x][y]][x + 1][y]) {
			printf ("R");
			printf_ans (num - n1[x][y], x + 1, y);
		}
	} else {

		if (dp[num - n2[x - n + 1][y]][x + 1][y]) {
			printf ("L");
			printf_ans (num - n2[x - n + 1][y], x + 1, y);	
		} else if (dp[num - n2[x - n + 1][y]][x + 1][y + 1]) {

			printf ("R");
			printf_ans (num - n2[x - n + 1][y], x + 1, y + 1);
		}
	}
}

int main () {

	while (scanf ("%d%d", &n, &s), n||s) {

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n - i; j++)
				scanf ("%d", &n1[i][j]);

		for (int i = 1; i < n; i++)
			for (int j = 0; j <= i; j++)
				scanf ("%d", &n2[i][j]);

		n2[0][0] = n1[n-1][0];
		memset (dp, 0, sizeof (dp));

		for (int i = 0; i < n; i++) 
			dp[n2[n - 1][i]][2 * n - 2][i] = 1;


		for (int i = n - 2; i >= 0; i--)
			for (int j = 0; j <= i; j++) 
				for (int m = n2[i][j]; m <= s; m++) {

					dp[m][i + n - 1][j] = dp[m - n2[i][j]][i + n][j] + dp[m - n2[i][j]][i + n][j + 1];
				}

		for (int i = n - 2; i >= 0; i--)
			for (int j = 0; j < n - i; j++) 
				for (int m = n1[i][j]; m <= s; m++) {

						dp[m][i][j] = dp[m - n1[i][j]][i + 1][j];
						if (j)
							dp[m][i][j] += dp[m - n1[i][j]][i + 1][j - 1];
				}

		ll ans = 0;
		for (int i = 0; i < n; i++) {
			if (dp[s][0][i]) 
				ans += dp[s][0][i];
			//printf ("%lld\n", dp[s][0][i]);
		}

		if (!ans)
			printf ("%lld\n\n", ans);
		else {

			printf ("%lld\n", ans);
			for (int i = 0; i < n; i++)
				if (dp[s][0][i]) {
					printf_ans(s, 0, i);
					break;
				}
			printf ("\n");
		}					 
	}
	return 0;
}

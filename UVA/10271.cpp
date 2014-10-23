#include <cstdio>
#include <cstring>

typedef long long ll;
const int N = 5005;
const int M = 1010;
const ll INF = 1e13;

ll dp[M][N];
int c[N];

ll Min (const ll a, const ll b) { return a < b? a: b; }

int W (const int a, const int b ) { return (a - b) * (a - b); }

int main () {

	int t;
	int k, n;
	scanf ("%d", &t);
	while (t--) {
		
		scanf ("%d%d", &k, &n);
		for (int i = n; i >= 1; i--)
			scanf ("%d", &c[i]);
		k += 8;

		for (int i = 1; i <= n; i++)
			dp[0][i] = 0;
		for (int i = 1; i <= k; i++)
			for (int j = 1; j <= n; j++) {

				dp[i][j] = INF;
				if (i * 3 > j)
					continue;
				if (j - 2 >= 1)
					dp[i][j] = Min (dp[i][j], dp[i - 1][j - 2] + W(c[j], c[j - 1]));
				if (j - 1 >= 1)
					dp[i][j] = Min (dp[i][j], dp[i][j - 1]);
			}
		
		ll ans = INF;
		for (int i = 3 * k; i <= n; i++)
			ans = Min (ans, dp[k][i]);

		printf ("%lld\n", ans);
	}
	return 0;
}

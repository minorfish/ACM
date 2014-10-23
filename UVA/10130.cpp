#include <cstdio>
#include <cstring>

const int N = 10005;
const int maxn = 35;
int dp[maxn];
int object[N][2];

int Max (const int a, const int b) { return a > b ? a: b; }

int main () {

	int t;
	int n, g;
	int w;
	int ans;
	scanf ("%d", &t);
	while (t--) {

		scanf ("%d", &n);
		for (int i = 0; i < n; i++)
			scanf ("%d%d", &object[i][0], &object[i][1]);
		scanf ("%d", &g);

		memset (dp, 0, sizeof (dp));

		for (int i = 0; i < n; i++) 
			for (int j = maxn - 5; j >= object[i][1]; j--)
				dp[j] = Max(dp[j], dp[j - object[i][1]] + object[i][0]);

		ans = 0;
		for (int i = 0; i < g; i++) {

			scanf ("%d", &w);
			ans += dp[w];
		}

		printf ("%d\n", ans);
	}
	return 0;
}

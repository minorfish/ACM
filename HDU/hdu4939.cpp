#include <cstdio>
#include <cstring>

typedef __int64 ll;
//typedef long long ll;

const int N = 1505;
ll n, x, y, z, t;
ll dp[N][N];

ll Max (const ll a, const ll b ) { return a > b ? a: b; }

ll solve () {

	memset (dp, 0, sizeof (dp));
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {

			ll T = t + j * z;
			ll W = T * (i - j) * y;
			dp[i + 1][j + 1] = Max (dp[i + 1][j + 1],dp[i][j] + W);
			dp[i + 1][j] = Max (dp[i + 1][j], dp[i][j] + W);
			ans = Max (ans, dp[i][j] + (n - i) * (x * T + W));
		}
	}

	for (int i = 0; i <= n; i++)
		ans = Max (ans, dp[n][i]);
	return ans;
}

int main () {

	int cas;
	scanf ("%d", &cas);
	for (int i = 1; i <= cas; i++) {
	//	scanf ("%lld%lld%lld%lld%lld", &n, &x, &y, &z, &t);
		scanf ("%I64d%I64d%I64d%I64d%I64d", &n, &x, &y, &z, &t);
		printf ("Case #%d: %I64d\n", i, solve());
	//	printf ("Case #%d: %lld\n", i, solve());
	}
	return 0;
}

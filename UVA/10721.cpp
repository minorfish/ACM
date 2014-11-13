#include <cstdio>
#include <cstring>

const int maxn = 55;

typedef long long ll;
int N, K, M;
ll dp[maxn][maxn][maxn];

void init () {

	memset (dp, -1, sizeof (dp));
}

ll DP (int n, int k, int m) {

	ll& ans = dp[n][k][m];
	if (ans != -1)
		return ans;
	if (n == N) {
		if (k == K)
			return ans = 1;
		return ans = 0;
	}

	ans = 0;
	if (k < K)
		ans += DP(n + 1, k + 1, 1);

	if (m < M)
		ans += DP(n + 1, k, m + 1);
	return ans;
}

int main () {

	while (scanf ("%d%d%d", &N, &K, &M) != EOF) {

		init();
		printf ("%lld\n", DP(1, 1, 1));
	}
	return 0;
}

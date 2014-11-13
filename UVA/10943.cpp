#include <cstdio>
#include <cstring>

const int maxn = 105;
const int MOD = 1e6;
typedef long long ll;

ll dp[maxn][maxn];
int N, K;

void init () {

	memset (dp, -1, sizeof (dp));
}

ll DP (int k, int sum) {

	ll& ans = dp[k][sum];

	if (ans != -1)
		return ans;
	
	if (k == K) {
		if (sum == N)
			return ans = 1;
		return ans = -2;
	}

	ll tmp;
	ans = 0;
	for (int i = 0; i <= N; i++) {
		if (sum + i <= N) {
			tmp = DP(k + 1, sum + i);
			if (tmp != -2)
				ans = (ans + tmp) % MOD; 	
		} else 
			break;
	}

	if (ans == 0)
		return ans = -2;
	return ans;
}

int main () {

	while (scanf ("%d%d", &N, &K) && (N || K)) {

		init();
		printf ("%lld\n", DP(0, 0));
	}
	return 0;
}

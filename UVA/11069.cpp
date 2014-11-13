#include <cstdio>
#include <cstring>

const int maxn = 100;

int n;
int dp[maxn];

void init () {

	memset (dp, 0, sizeof (dp));
}

int solve (int k) {

	if (k + 2 > n)
		return dp[k] = 1;
	if (dp[k])
		return dp[k];

	int &ans = dp[k];
	if (k + 2 <= n)
		ans += solve(k + 2);
	if (k + 3 <= n)
		ans += solve(k + 3);
	return ans;
}

int main () {

	while (scanf ("%d", &n) != EOF) {

		init();
		int ans = solve(1);
		if (n > 1)
			ans += solve(2);
		printf ("%d\n", ans);				
	}
	return 0;
}

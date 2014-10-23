#include <cstdio>
#include <cstring>

const int N = 65;
typedef long long ll;
ll dp[N][N];
char str[N];

void init () {

	int n = strlen (str);
	memset (dp, -1, sizeof (dp));
	for (int i = 0; i < n; i++)
		dp[i][i] = 1;	
}

ll DP (int x, int y) {

	ll& ans = dp[x][y];
	if (ans !=	-1)
		return ans;
	if (str[x] == str[y])
		return ans = DP(x, y - 1) + DP(x + 1, y) + 1;
	else {

		if (x + 1 <= y - 1)
			return ans = DP(x, y - 1) + DP(x + 1, y) - DP(x + 1, y - 1);
		else
			return ans = DP(x, y - 1) + DP(x + 1, y);
	}
}

int main () {

	int t;
	scanf ("%d", &t);
	while (t--) {

		scanf ("%s", str);
		init ();
		printf ("%lld\n", DP (0, strlen (str) - 1));

	}
	return 0;
}

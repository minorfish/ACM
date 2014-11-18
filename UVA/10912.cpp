#include <cstring>
#include <cstdio>

const int maxn = 27;
const int maxm = 355;

int L, S;
int f[maxn][maxn][maxm];

int dp (int n, int sum, int pre) {

	int& ans = f[n][pre][sum];
	if (ans != -1)
		return ans;
	
	if (n == L) {
		if (sum == S)
			return ans = 1;
		return ans = 0;
	}

	ans = 0;
	for (int i = pre + 1; i < maxn; i++) {
		if (sum + i <= S)
			ans += dp(n + 1, sum + i, i);
		else
			break;
	}
	return ans;
}

int main () {

	int cas = 0;
	while (scanf ("%d%d", &L, &S) && (L||S)) {

		printf ("Case %d: ", ++cas);
		if (L >= maxn || S > maxm - 4) {
			printf ("0\n");
			continue;
		}
		
		memset (f, -1, sizeof(f));
		printf ("%d\n", dp(0, 0, 0));
	}
	return 0;
}

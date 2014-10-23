#include <cstdio>
#include <cstring>

const int N = 2;
const int maxn = 10000;

int dp[maxn];
int v[N];
int t;

int Max (const int a, const int b) { return a > b? a: b; }

int main () {
	
	while (scanf ("%d%d%d", &v[0], &v[1], &t) != EOF) {

		memset (dp, -1, sizeof (dp));
		dp[0] = 0;
		for (int i = 0; i <= N - 1; i++) {
			for (int j = 0; j <= t - v[i]; j++) {
			
				if (dp[j] != -1)
					dp[j + v[i]] = Max (dp[j + v[i]], dp[j] + 1);			
			}
		}

		int i;
		for (i = t; i >= 0; i--)
			if (dp[i] != -1)
				break;
		printf ("%d", dp[i]);

		if (i != t)
			printf (" %d\n", t - i);
		else
			printf ("\n");
	}
	return 0;
}

#include <cstdio>
#include <cstring>

const int N = 1005;
const int INF = 0x3f3f3f3f;

int n, L, C;
int t[N];
int num[N];
int dp[N][N];

int f (int free) {

	if (free >= 1 && free <= 10)
		return -C;
	else if (!free)
		return 0;
		return (free - 10) * (free - 10);
}

int Min (const int a, const int b) {return a < b ? a: b; }

int main () {

	int cas = 0;
	while (scanf ("%d", &n) , n) {

		if (cas)
			printf ("\n");
		scanf ("%d%d", &L, &C);
		for (int i = 1; i <= n; i++)
			scanf ("%d", &t[i]);
	
		num[0] = 0;
		for (int i = 1; i <= n; i++) 
			num[i] = num[i - 1] + t[i];
	
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
				dp[i][j] = INF;
		dp[0][0] = 0;

		for (int i = 1; i <= n; i++) { 
			if (dp[i - 1][n] != INF)
				break;
			for (int j = i; j <= n; j++) {
				for (int k = j - 1; k >= i - 1; k--) {
					if (num[j] - num[k] <= L) {
						
						if (dp[i - 1][k] != INF) {
							dp[i][j] = Min (dp[i][j], dp[i - 1][k] + f(L - num[j] + num[k]));
						}
					}
					else
						break;
				}
			}
		}
		int i;
		for (i = 1; i <= n; i++) {
			if (dp[i][n] != INF)
				break;
		}
		printf ("Case %d:\n", ++cas);
		printf ("Minimum number of lectures: %d\n", i);
		printf ("Total dissatisfaction index: %d\n", dp[i][n]);
			
	}
	return 0;
}

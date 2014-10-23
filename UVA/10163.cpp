#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>

using namespace std;

const int N = 1005;
const int M = 35;
const int INF = 3000000;

int p[M];
int dp[N];
int y[N];

int Min (const int a, const int b) {return a < b ? a: b; }

int Max (const int a, const int b) {return a > b ? a: b; }

int main () {

	int n, m;
	while (scanf ("%d%d", &n, &m) , n || m) { 

		for (int i = 1; i <= m; i++)
			scanf ("%d", &p[i]);

		sort (p + 1, p + 1 + m, greater<int>());

		memset (dp, 0, sizeof (dp));
		dp[0] = INF;
		for (int i = 1; i <= m; i++) 
			for (int j = n; j >= 1; j--) {
				for (int k = 1; k <= j; k++) {	
					dp[j] = Max (dp[j], Min (dp[j - k] , p[i] / k));	
				}
			}
		int ans = dp[n];

		if (ans) {
			for (int i = 1; i <= n; i++)
				dp[i] = INF;

			dp[0] = 0;
			for (int i = 1; i <= m; i++)
				for (int j = n; j >= 1; j--) 
					for (int k = Min(p[i]/ans, j); k >= 1; k--) {

						dp[j] = Min (dp[j], dp[j - k] + p[i]);
					}
		} else
			dp[n] = 0;

		printf ("%d %d\n", ans, dp[n]);	

	}
	return 0;
}

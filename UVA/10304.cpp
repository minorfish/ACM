#include <cstdio>
#include <cstring>

const int N = 255;
const int INF = 0x3f3f3f3f;

int v[N];
int num[N];
int dp[N][N];
int n;

int Min (const int a, const int b) { return a < b? a: b; }

int main () {
	
	while (scanf ("%d", &n) != EOF) {

		num[0] = 0;
		for (int i = 1; i <= n; i++) {

			scanf ("%d", &v[i]);
			num[i] = num[i - 1] + v[i];
		}
		
		for (int i = 1; i <= n; i++)
			dp[i][i] = 0;

		int left, right;
		for (int l = 1; l < n; l++)
			for (int i = 1; i + l <= n; i++) {
				
				dp[i][i + l] = INF;
				for (int j = i; j <= i + l; j++) {
					
					if (j != i)
						left = dp[i][j - 1] + num[j - 1] - num[i - 1];
					else
						left = 0;

					if (j != i + l)
						right = dp[j + 1][i + l] + num[i + l] - num[j];
					else
						right = 0;

					dp[i][i + l] = Min (dp[i][i + l], left + right);
				}
			}
		
//		printf ("%d %d\n", INF, 1<<30);
		printf ("%d\n", dp[1][n]);
	}
	return 0;
}

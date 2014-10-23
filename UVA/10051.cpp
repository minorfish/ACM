#include <cstdio>
#include <cstring>

const int N = 505;
const int M = 6;
const char str[M][2 * M] = {"front", "left", "top", "bottom", "right", "back"};

int n;
int cube[N][M];
int dp[N][M];

int next[N], side[N];

int Max (const int a, const int b) {return a > b? a: b;}

bool printf_ans (int d, int k) {

	if (dp[d][k] == 1) {
		next[d] = d;
		return true;
	}

	for (int j = d + 1; j <= n; j++) 
		for (int i = 0; i < M; i++)
			if (cube[d][M - 1 - k] == cube[j][i] && dp[d][k] == dp[j][i] + 1) {
				if (printf_ans(j, i)) {
					next[d] = j;
					side[j] = i;
					return true;
				}
			}
	return false;
}

int main () {

	int cas = 0;
	while (scanf ("%d", &n) , n) {

		if (cas)
			printf ("\n");

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < M/2; j++)
				scanf ("%d%d", &cube[i][j], &cube[i][M - 1 - j]);
		}
		//init	
		for (int j = 1; j <= n; j++)
			for (int i = 0; i < M; i++)
				dp[j][i] = 1;

		int ans = 1;
		int d, k;
		for (int i = n - 1; i >= 1; i--)
			for (int j = 0; j < M; j++) {

				for (int l = i + 1; l <= n; l++) { 
					for (int k = 0; k < M; k++)
						if (cube[i][M - 1 - j] == cube[l][k]) {

							if (dp[l][k] + 1 > dp[i][j]) {

								dp[i][j] = Max (dp[i][j], dp[l][k] + 1);	
							}
						}
				} 

				if (dp[i][j] > ans) {

					d = i;
					k = j;
					ans = dp[i][j];
				}
			}

		printf ("Case #%d\n%d\n", ++cas, ans);

		//path
		if (ans == 1) {

			printf ("1 front\n");
			continue;
		}

		printf_ans (d, k);

		while (1) {

			printf ("%d %s\n", d, str[k]);
			if (d == next[d])
				break;
			d = next[d];
			k = side[d];
		}
	}
	return 0;
}


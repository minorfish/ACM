#include <cstdio>
#include <cstring>

const int N = 1005;
int dp[N][N];
char str[N];

void init (int len) {
	
	for (int i = 0; i < len; i++) {
		
		dp[i][i] = 0;
		if (i + 1 < len) {

			if (str[i] == str[i + 1])
				dp[i][i + 1] = 0;
			else
				dp[i][i + 1] = 1;
		}
	}	
}

int Min (const int a, const int b) { return a < b ? a: b; }

int main () {

	int cas;
	int len;
	scanf ("%d", &cas);
	for (int k = 1; k <= cas; k++) {

		scanf ("%s", str);
		len = strlen (str);
		init (len);

		for (int n = 3; n <= len; n++) {
			for (int i = 0, j = n - 1; j < len; i++, j++) {

				if (str[i] == str[j])
					dp[i][j] = dp[i + 1][j - 1];
				else 
					dp[i][j] = Min (Min (dp[i + 1][j], dp[i][j - 1]), dp[i + 1][j - 1]) + 1; 

			}
		}

		printf ("Case %d: %d\n", k, dp[0][len - 1]);
	}
	return 0;
}

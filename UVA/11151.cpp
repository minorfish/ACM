#include <cstdio>
#include <cstring>

const int N = 1005;
int dp[N][N];
char str[N];

void init (int len) {
	
	for (int i = 0; i < len; i++) {
		
		dp[i][i] = 1;
		if (i + 1 < len) {

			if (str[i] == str[i + 1])
				dp[i][i + 1] = 2;
			else
				dp[i][i + 1] = 1;
		}
	}	
}

int Max (const int a, const int b) { return a > b ? a: b; }

int main () {

	int cas;
	int len;
	scanf ("%d%*c", &cas);
	while (cas--) {

		gets(str);
		len = strlen (str);
		if (!len) {
			printf ("0\n");
			continue;
		}
		init (len);
		for (int n = 3; n <= len; n++) {
			for (int i = 0, j = n - 1; j < len; i++, j++) {

				if (str[i] == str[j])
					dp[i][j] = dp[i + 1][j - 1] + 2;
				else 
					dp[i][j] = Max (dp[i + 1][j], dp[i][j - 1]); 

			}
		}
		
		printf ("%d\n", dp[0][len - 1]);
	}
	return 0;
}

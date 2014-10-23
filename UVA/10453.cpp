#include <cstdio>
#include <cstring>

const int N = 1005;
int dp[N][N];
char str[N];
char ans[N];

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

void printf_ans (int i, int j) {

	if (i == j) {

		ans[0] = str[i];

	} else if (j - i == 1) {

		if (str[i] == str[j]) {

			ans[0] = str[i];	
		} else {

			ans[0] = str[j];
			ans[1] = str[i];
		}
	} else {

		int len = (j - i + dp[i][j]) / 2 + 1;
		if (str[i] == str[j]) {
			
			printf_ans(i + 1, j - 1);
			ans[len - 1] = str[i];	
		} else {

			if (dp[i][j] == dp[i + 1][j] + 1) {
				printf_ans(i + 1, j);
				ans[len - 1] = str[i];
			} else if (dp[i][j] == dp[i][j - 1] + 1) {

				printf_ans(i, j - 1);
				ans[len - 1] = str[j];
			} else {

				printf_ans(i + 1, j - 1);
				ans[len - 2] = str[j];
				ans[len - 1] = str[i];
			}
		}
	}
}

int main () {

	int len;
	while (gets(str) != NULL) {

		len = strlen (str);
		if (!len) {
			printf ("0 %s\n", str);
			continue;
		}

		init (len);
		for (int n = 3; n <= len; n++) {
			for (int i = 0, j = n - 1; j < len; i++, j++) {

				if (str[i] == str[j])
					dp[i][j] = dp[i + 1][j - 1];
				else 
					dp[i][j] = Min (dp[i + 1][j - 1] + 2, Min (dp[i][j - 1],dp[i + 1][j]) + 1); 

			}
		}

		printf ("%d ", dp[0][len - 1]);
		if (dp[0][len - 1] == 0) 
			printf ("%s\n", str);
		else {

			printf_ans(0, len - 1);
			len += dp[0][len - 1];
			if (len % 2) {

				len /= 2;
				for (int i = len; i > 0; i--)
					printf ("%c", ans[i]);
			} else {

				len = len / 2 - 1;
				for (int i = len; i >= 0; i--)
					printf ("%c", ans[i]);
			}

			ans[len + 1] = '\0';
			printf ("%s\n", ans);
		}
	}
	return 0;
}

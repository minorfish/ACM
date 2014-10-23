#include <cstdio>
#include <cstring>

const int N = 10005;
const int M = 85;
const int INF = 0x3f3f3f3f;

int L, n;
int dp[N][M];
int p[N][M];
char str[N];
char word[N][M];
int l[N];

int Min (const int a, const int b) { return a < b ? a: b; }

void handle () {

	int j = 0;
	bool flag = 0;
	for (int i = 0; i <= strlen (str); i++) {

		if (str[i] != ' ' && str[i] != '\0') {
			word[n][j++] = str[i];		
			flag = 1;
		} else {
			if (flag) {
				word[n][j] = '\0'; 
				l[n++] = j;
				j = 0;
				flag = 0;
			}
		}
	}
}

void printf_ans (int x, int y) {

	if (x == n + 1)
		return;
	if (!p[x][y] && !y) {
		printf ("%s", word[x - 1]);
	} else {

		printf ("%s", word[x - 1]);
		if (x != n) {
			for (int i = y + l[x - 1]; i < p[x][y]; i++)
				printf (" ");
		}
	}

	if (!p[x][y] || x == n)
		printf ("\n");
	printf_ans(x + 1, p[x][y]);		
}

int main () {

	int tmp;
	while (scanf ("%d%*c", &L), L) {

		n = 0;
		while (gets(str) && str[0] != '\0') {

			handle();				
		}
		//init
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= L; j++) {
				dp[i][j] = INF;
				p[i][j] = L + 1;
			}
		dp[n][0] = 500;
		p[n][0] = 0; 
		dp[n][L - l[n - 1]] = 0;

		for (int i = n - 1; i >= 1; i--) { 
			for (int j = 0; j <= L - l[i]; j++) {

				if (dp[i + 1][j] == INF)
					continue;
				if (!j) {

					if (dp[i + 1][j] <= dp[i][L - l[i - 1]]) {
						dp[i][L - l[i - 1]] = dp[i + 1][j];
						p[i][L - l[i - 1]] = j;
					}
					tmp = (l[i - 1] == L) ? 0: 500;
					if (dp[i + 1][j] + tmp <= dp[i][0]) {
						dp[i][0] = dp[i + 1][j] + tmp;
						p[i][0] = j;
					}

				} else {

					for (int k = 0; k < j - l[i - 1]; k++) {

						tmp = j - l[i - 1] - k - 1;
						if (dp[i + 1][j] + tmp * tmp < dp[i][k]) {

							dp[i][k] = dp[i + 1][j] + tmp * tmp;
							p[i][k] = j;
						} else if (dp[i + 1][j] + tmp * tmp == dp[i][k]) {

							if (p[i][k] > k)
								p[i][k] = Min (p[i][k], j);
							else 
								p[i][k] = j;			
						}
					}
				}
			}
		}

		printf_ans(1, 0);
		printf ("\n");
	}
	return 0;  
}

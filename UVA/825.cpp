#include <cstdio>
#include <cstring>

const int N = 1005;

typedef long long ll;

int G[N][N];
ll dp[N][N];
char str[N];

void handle () {

	int x, y;
	bool flag = 1;
	x = y = 0;
//	printf ("%s\n", str);
	for (int i = 0; i <= strlen (str); i++) {

		if (str[i] >= '0' && str[i] <= '9') {

			if (flag)
			 	x = x * 10 + str[i] - '0';		
			else
				y = y * 10 + str[i] - '0';
		} else {

			if (!flag)
				G[x][y] = 1;
//			printf ("%d %d\n", x, y);
			y = 0;	
			flag = 0;
		}
	}
}

int main () {

	int t, n, m;
	int x, y;
	char ch;
	scanf ("%d", &t);
	while (t--) {

		scanf ("%d%d%*c", &n, &m);
		memset (G, 0, sizeof (G));
		for (int i = 1; i <= n; i++) {
	
			gets(str);
			handle();
		}

		for (int i = n; i >= 1; i--)
			for (int j = m; j >= 1; j--) {
	
				dp[i][j] = 0;
				if (G[i][j]) 
					continue;
				
				if (i == n && j == m) {
					dp[i][j] = 1;
					continue;
				}
				if (i != n) 
					dp[i][j] += dp[i + 1][j];
				if (j != m)
					dp[i][j] += dp[i][j + 1];
			}

		printf ("%lld\n", dp[1][1]);
		if (t)
			printf ("\n");
	}
	return 0;
}

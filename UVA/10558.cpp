#include <cstdio>
#include <cstring>

const int N = 105;

int n, m;
int s[N][N];
int t[N][N];
int dp[N][N];
int p[N][N];
int street[N];
int G[N][N][N];
int path[N][N];

int Max (const int a, const int b) { return a > b ? a: b; }

void init () {

	memset (t, 0, sizeof (t));
	for (int i = 1; i <= 100; i++) {	
		for (int j = 1; j < m; j++) {	
			int k;
			for (k = street[j - 1]; k < street[j]; k++)
				if (p[i - 1][k])
					break;
			if (k != street[j])
				t[i][j] = 1;
		}
	}

	memset (G, 0, sizeof (G));
	memset (s, 0, sizeof (s));
	for (int i = 1; i < 100; i++) {
		for (int j = 1; j + i <= 100; j++) {
		
			for (int k = 1; k < m; k++)
				G[j][j + i][k] |= G[j][j + i - 1][k];
			
			for (int k = 1; k < m; k++)
				G[j][j + i][k] |= t[j + i][k];
			for (int k = 1; k < m; k++)
				if (G[j][j + i][k])
					s[j][j + i]++;
		}
	}

}

void printf_ans (int A, int j) {

	if (path[A][j] == -1)
		return;
	printf_ans (A - 1, path[A][j]);
	printf (" %d", path[A][j]);					
}

int main () {

	int x, y, A;
	while (scanf ("%d", &n) && n != -1) {

		memset (p, 0, sizeof (p));
		for (int i = 0; i < n; i++) {

			scanf ("%d%d", &x, &y);
			p[y][x] = 1;
		}
		scanf ("%d", &m);
		for (int i = 0; i < m; i++)
			scanf ("%d", &street[i]);
		scanf ("%d", &A);

		init ();

		dp[1][1] = 0;
		path[1][1] = -1;
		for (int i = 2; i <= A; i++) {
			for (int j = i; j <= 100; j++) {

				dp[i][j] = 0;
				if (i == 2) {
					dp[i][j] = Max (dp[i][j] , dp[1][1] + s[1][j]);
					path[i][j] = 1;
				} else {

					for (int k = 2; k < j; k++) { 
						if (dp[i - 1][k] + s[k][j] >= dp[i][j])
							path[i][j] = k;
						dp[i][j] = Max (dp[i][j] , dp[i - 1][k] + s[k][j]);
					}
				}
			}
		}
		
		//printf ("%d\n", s[50][100]);
		printf ("%d", A);
		printf_ans(A, 100);
		printf (" 100\n");
				
	}	
	return 0;
}

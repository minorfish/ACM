#include <cstdio>
#include <cstring>
#include <cstdlib>

const int N = 11;
const int M = 7;
const int INF = 0x3f3f3f3f; 

int table[M][M];
int heat[M][M];
int f[N][N][N][N][N][N];
int n, m;

int Min (const int a, const int b) {return a < b ? a: b; }

int judge (int *c) {

	int count1 = 0;
	int count2 = 0;
	for (int i = 0; i < m; i++) {
		if (!c[i])
			count1++;
		if (c[i] == 1)
			count2++;
	}
	if (count1 == m - 1 && count2 == 1)
		return 1;
	return 0;
}

void init () {

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			for (int k = 0; k <= n; k++)
				for (int l = 0; l <= n; l++)
					for (int p = 0; p <= n; p++)
						for (int q = 0; q <= n; q++)
							f[i][j][k][l][p][q] = INF; 
}


int dp (int *c) {

	int& ans = f[c[0]][c[1]][c[2]][c[3]][c[4]][c[5]];

/*	for (int i = 0; i < m; i++)
		printf ("%d ", c[i]);
	printf ("\n");*/
	if (ans != INF)
		return ans;

	if (judge(c) == 1)
		return ans = 0;

	int newc;
	for (int i = 0; i < m; i++) {

		if (c[i]) {
			c[i]--;
			for (int j = 0; j < m; j++) {
				
				if (c[j]) {

					c[j]--;
					newc = table[i + 1][j + 1] - 1;
					c[newc]++;
					ans = Min (ans, dp(c) + heat[i + 1][j + 1]);
					c[j]++;
					c[newc]--;
				}
			}
			c[i]++;
		}
	}	
	return ans;
}

int main () {

	int t;
	int x;
	char str[M];
	int c[M];

	scanf ("%d", &t);
	while (t--) {

		scanf ("%d", &m);
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= m; j++) 
				scanf ("%d%d", &table[i][j], &heat[i][j]);

		scanf ("%d", &n);
		memset (c, 0, sizeof (c));
		for (int i = 0; i < n; i++) {
			scanf ("%d", &x);
			c[x - 1]++;
		}
		scanf ("%s", str);

		init();
		printf ("%d\n", dp(c));	
	}
}

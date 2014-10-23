#include <cstdio>
#include <cstring>

const int N = 42;
const int M = 5;
const int maxn = 1000005;

int candy[N][M];
int top[M];
int f[N][N][N][N];
int n;

int Max (const int a, const int b) { return a > b ? a: b; }

void init () {

	memset (f, -1, sizeof (f));
	f[n][n][n][n] = 0;
}

bool handle (int r, int c, int k, int *b) {

	int i;
	for (i = 0; i < k; i++) {

		if (candy[r][c] == b[i])
			break;
	}

	if (!k || i == k) {
		b[k] = candy[r][c];
		return false;
	} else {

		for (int j = i; j < k - 1; j++)
			b[j] = b[j + 1];
		return true;
	}
}

int dfs (int k, int *bket, int a, int b, int c, int d) {

	int bket1[M * 2];
	int& ans = f[a][b][c][d];
	if (k >= M)
		return 0;
	if (ans != -1)
		return ans;
	top[1] = a;
	top[2] = b;
	top[3] = c;
	top[4] = d;
	for (int i = 1; i < M; i++) {

		/*for (int j = 0; j < k; j++)
			bket1[j] = bket[j];*/
		memcpy (bket1, bket, k * sizeof (int));
		/*for (int j = 0; j < k; j++)
			printf ("%d ", bket1[j]);
		printf ("\n");*/
		if (handle (top[i], i, k, bket1)) {

			top[i]++;
			if (top[i] <= n)
				ans = Max (ans, dfs (k - 1, bket1, top[1], top[2], top[3], top[4]) + 1);				
		} else {

			top[i]++;
			if (top[i] <= n)
				ans = Max (ans, dfs (k + 1, bket1, top[1], top[2], top[3], top[4]));
		}
		top[i]--;
	}
	return ans;
}

int main () {

	while (scanf ("%d", &n), n) {

		for (int i = 0; i < n; i++)
			for (int j = 1; j < M; j++)
				scanf ("%d", &candy[i][j]);

		int b[M * 2];
		init ();
		printf ("%d\n", dfs (0, b, 0, 0, 0, 0));
//		printf ("%d\n", f[n][n - 1][0][0]);
/*		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					for (int l = 0; l < n; l++) 
						printf ("%d ", f[i][j][k][l]);
					printf ("\n");
				}
				printf ("\n");
			}
			printf ("\n");
		}
		printf ("\n");*/
	}
	return 0;
}

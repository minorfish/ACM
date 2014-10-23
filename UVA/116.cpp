#include <cstdio>
#include <cstring>

const int N = 15;
const int M = 105;
const int INF = 0x3f3f3f3f;
const int dir[3][2] = {{0, 1}, {1, 1}, {-1, 1}};

int mat[N][M];
int f[N][M];
int path[N][M];
int n, m;

int Min (const int a, const int b) { return a < b ? a: b; }

void init () {

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++) {
			f[i][j] = INF;
			path[i][j] = n;
		}
}

int dp (int x, int y) {

	int& ans = f[x][y];
	if (y == m)
		return ans = 0;
	if (ans != INF)
		return ans;
	int nx, ny;
	int temp;
	for (int i = 0; i < 3; i++) {

		nx = x + dir[i][0];
		ny = y + dir[i][1];
		if (nx == -1)
			nx = n - 1;
		if (nx == n)
			nx = 0;
		temp = dp(nx, ny) + mat[x][y]; 
		if (temp <= ans) {
			if (temp == ans)
				path[x][y] = Min (path[x][y], nx);
			else
				path[x][y] = nx;
			ans = temp;
		}
	}
	return ans;
}

void printf_ans (int x, int y) {

	if (y == m - 1)
		return;
	printf (" %d", path[x][y] + 1);
	printf_ans(path[x][y], y + 1);
}

int main () {

	while (scanf ("%d%d", &n, &m) != EOF) {

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf ("%d", &mat[i][j]);

		init();

		int ans = INF;
		int temp, r;
		for (int i = n - 1; i >= 0; i--) {
			temp = dp(i, 0);
			if (temp <= ans) {
				ans = temp;
				r = i;
			}
		}

		printf ("%d", r + 1);
		printf_ans(r, 0);
		printf ("\n%d\n", ans);
	}
	return 0;
}

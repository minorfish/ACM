#include <cstdio>
#include <cstring>
#include <queue>
#include <cstdlib>

using namespace std;

const int N = 105;
const int M = 8;
const int dir[M][2] = {{-1, 0},{-1, 1}, {0, -1}, {1, 1}, 
	                   {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

char rec[N][N];
int have[N][N];

int n;
int f[N][N][M][2];

void init () {

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			for (int d = 0; d < M; d++)
				for (int k = 0; k < 2; k++)
					f[i][j][d][k] = -1;
}

int dp (int x, int y, int k, int d) {
	
	if (f[x][y][d][k] != -1)
		return f[x][y][d][k];

	int nx, ny; 
	for (int i = 0; i < M; i++) {

		nx = x + dir[i][0];
		ny = y + dir[i][1];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n)
			continue;
		if (rec[nx][ny] == '#')
			continue;
		if (i == d)
			f[x][y][d][k] = max (dp(nx, ny, k, d) + 1, f[x][y][d][k]);
		else if (!k && (abs(i - d) == 2 || abs (i - d) == 6))
			f[x][y][d][k] = max (dp(nx, ny, k + 1, i) + 1, f[x][y][d][k]);
	}
	
	if (f[x][y][d][k] == -1) 
		f[x][y][d][k] = 1;
	return f[x][y][d][k];
}

int main () {

	while (scanf ("%d", &n) && n) {

		for (int i = 0; i < n; i++)
			scanf ("%s", rec[i]);
	
		int ans = -1;
		init();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (rec[i][j] == '.') {
					for (int d = 0; d < M; d++)
						ans = max (ans, dp(i, j, 0, d));
				}
			}
		printf ("%d\n", ans);
	}
	return 0;
}

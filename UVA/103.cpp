#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 35;
const int M = 15;

int n, m;
int box[N][M];
int G[N][N];
int f[N][N];
int path[N][N];

bool judge (int a, int b) {

	for (int i = 0; i < m; i++)
		if (box[a][i] >= box[b][i])
			return false;
	return true;
}

void handle () {

	memset (G, 0, sizeof (G));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {

			if (i == j)
				continue;
			if (judge(i, j))
				G[i][j] = 1;
		}
}

void init () {

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			f[i][j] = -1;
}

int dp (int x, int y) {

	int& ans  = f[x][y];
	int temp;
	if (ans != -1)
		return ans;
	for (int i = 0; i < n; i++)
		if (G[y][i]) {
			temp = dp(y, i) + 1;
			if (temp > ans) {
				ans = temp;
				path[x][y] = i;
			}
		}
	if (ans == -1) {
		ans = 2;
		path[x][y] = -1;
	}
	return ans;
}

void printf_ans(int x, int y) {

	if (path[x][y] == -1)
		return;
	printf (" %d", path[x][y] + 1);
	printf_ans(y, path[x][y]);
}

int main () {

	while (scanf ("%d%d", &n, &m) != EOF) {

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf ("%d", &box[i][j]);

		for (int i = 0; i < n; i++)
			sort (box[i], box[i] + m);
		
		handle ();
		init();

		int ans = 1;
		int temp;
		int x, y;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (G[i][j]) {
					temp = dp(i, j);
					if (temp > ans) {
						ans = temp;
						x = i;
						y = j;
					}
				}
		printf ("%d\n", ans);
		if (ans != 1) { 

			printf("%d %d", x + 1, y + 1);
			printf_ans(x, y);
		} else
			printf ("1");
		printf ("\n");
	}
	return 0;
}


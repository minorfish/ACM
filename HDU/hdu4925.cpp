#include <cstdio>
#include <cstring>

const int N = 105;
const int M = 4;
int visit[N][N];
const int dir[M][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

int main () {

	int t;
	int n, m;
	int ans, temp;
	scanf ("%d", &t);
	while (t--) {

		scanf ("%d%d", &n, &m);

		memset (visit, 0, sizeof(visit));
		visit[0][0] = 1;
		ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {

				if (visit[i][j])
					continue;
				temp = 0;
				for (int k = 0; k < M; k++) {
					
					if (i + dir[k][0] >= 0 && i + dir[k][0] < n && j + dir[k][1] >= 0 && j + dir[k][1] < m) {

						temp++;
						visit[i + dir[k][0]][j + dir[k][1]] = 1;
					}
				}
				ans += 1<<temp;
			}

		if (!ans)
			printf ("1\n");
		else
			printf ("%d\n", ans);
	}
	return 0;
}

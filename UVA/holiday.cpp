#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 105;
const int dir[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

int n, m;
char G[maxn][maxn];
int vis[maxn][maxn];

struct Des {

	int x, y, v;
	void set (int x, int y, int v = 0) {

		this->x = x;
		this->y = y;
		this->v = v;
	}
	bool operator < (Des tmp) const {
		return v > tmp.v;	
	}
};

priority_queue<Des> q;

int bfs (Des S, Des E) {

	int x, y;
	memset (vis, -1, sizeof (vis));
	while (!q.empty()) {
		q.pop();
	}
	vis[S.x][S.y] = 0;
	q.push(S);

	while (!q.empty()) {

		x = q.top().x;
		y = q.top().y;

		if (x == E.x && y == E.y)  
			return 1;
		for (int i = 0; i < 4; i++) {

			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (vis[nx][ny] != -1)
				continue;
			if (G[nx][ny] == '#')
				continue;

			if (G[nx][ny] == 'S')
				vis[nx][ny] = vis[x][y] + 3;
			else
				vis[nx][ny] = vis[x][y] + 1;
			S.set(nx, ny, vis[nx][ny]);
			q.push(S);
		}

		q.pop();
	}
	return 0;
}

int main () {

	while (scanf ("%d%d", &n, &m) != EOF) {

		Des S, E;
		for (int i = 0; i < n; i++) {
			scanf ("%s", G[i]);
			for (int j = 0; j < m; j++) {
				if (G[i][j] == 'G')
					S.set(i, j);
				else if (G[i][j] == 'T')
					E.set(i, j);
			}
		}
	
		if (!bfs(S, E))	
			printf ("GG is unhappy!\n");
		else
			printf ("%d\n", vis[E.x][E.y]);
	}
	return 0;
}

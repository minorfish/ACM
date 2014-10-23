#include <stdio.h>
#include <string.h>

const int N = 205;
const int INF = 0x3f3f3f3f;
int n, m;
char g[N][N];
int visit[N][N];
int mm;
struct Tem {

	int x, y, v;
};

const int dir[4][2][2] = {{{-1,0}, {0, 1}},
	{{1, 0}, {0, 1}}, 
	{{0, -1}, {1, 0}},
	{{0, -1}, {-1, 0}}};

int Min (const int x, const int y) { return x < y? x: y; }

bool influence (int x, int y, int d, Tem * tem) {

	tem[0].v = visit[x][y];
	tem[0].x = x;
	tem[0].y = y;
	visit[x][y] = 1;
	int nx = x + dir[d][0][0];
	int ny = y + dir[d][0][1];
	if (nx >= 0 && nx < n && ny >= 0 && ny < m) {

		if (g[nx][ny] == '#')	
			return false;
		else {

			tem[1].v = visit[nx][ny];
			tem[1].x = nx;
			tem[1].y = ny;
			visit[nx][ny] = 1;
		}
	}

	int nx1 = x + dir[d][1][0];
	int ny1 = y + dir[d][1][1]; 
	if (nx1 >= 0 && nx1 < n && ny1 >= 0 && ny1 < m ) {

		if (g[nx1][ny1] == '#')	
			return false;
		else {

			tem[2].v = visit[nx1][ny1];
			tem[2].x = nx1;
			tem[2].y = ny1;
			visit[nx1][ny1] = 1;
		}
	}

	return true;
}

void undo (Tem * tem) {

	for (int i = 0; i < 3; i++)	
		if (tem[i].v != -1)
			visit[tem[i].x][tem[i].y] = tem[i].v;
}

void dfs (int x, int y, int num) {

	int newx, newy;
	if (x == -1) {		

		mm = Min (mm, num);
		return;	
	}

	newy = y + 1; 
	newx = x;
	if (newy >= m) {
		newx = x - 1;
		newy = 0;
	}

	if (g[x][y] == '.') {

		bool flag = 0;
		if (visit[x][y]) {
			dfs(newx, newy, num);
			flag = 1;
		}

		if (num + 1 >= mm)
			return;

		Tem tem[3];
		memset (tem, -1, sizeof (tem));
		if (influence (x, y, 0, tem)) {

			g[x][y] = 'X';
			dfs (newx, newy, num + 1);
			undo(tem);
			g[x][y] = '.';

		} else {

			undo(tem);
			if (!flag) 
				return;
		}

	} else  	
		dfs (newx, newy, num);
}

void solve () {

	mm = INF;
	memset (visit, 0, sizeof (visit));
	bool flag = 1;
	Tem tem[3];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (g[i][j] == '.') {

				flag = 0;
				g[i][j] = 'X';
				for (int k = 0; k < 4; k++) {

					memset (tem, -1, sizeof (tem));
					memset (visit, 0, sizeof (visit));

					if (influence (i, j, k, tem))	
						dfs (n - 1, 0, 1);
					undo(tem);
				}
				g[i][j] = '.';
			}

	if (mm == INF) {

		if (flag)
			printf ("0\n");
		else
			printf ("-1\n");
	}
	else
		printf ("%d\n", mm);
}

int main () {

	while (scanf ("%d%d", &n, &m), n || m) {

		for (int i = 0; i < n; i++) 
			scanf ("%s", g[i]);
		solve();	
	}
	return 0;
}

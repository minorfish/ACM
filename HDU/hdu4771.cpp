#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 105;
const int M = 5;
int n, m, Q;
char map[N][N];
int dist[N][N];
int ans[M][M];
int mm;
int vis[M];

const int dir[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
const int INF = 0x6ffffff;

struct Precious {

	int x, y;
}precious[M], q[N * N];

int Min (const int x , const int y) {return x < y ? x: y;}
int bfs (const Precious begin, const Precious end) {

	memset (dist, 0, sizeof (dist));	
	int front, rear;
	front = 0;
	rear = 1;
	q[front].x = begin.x;
	q[front].y = begin.y;
	while (front < rear) {

		if (q[front].x == end.x && q[front].y == end.y)
			return dist[q[front].x][q[front].y];
		for (int i = 0; i < 4; i++) {

			q[rear].x = q[front].x + dir[i][0];
			q[rear].y = q[front].y + dir[i][1];
			if (q[rear].x < 0 || q[rear].x >= n || q[rear].y < 0 || q[rear].y >= m)
				continue;
			if ( map[q[rear].x][q[rear].y] != '#' && !dist[q[rear].x][q[rear].y]) {

				dist[q[rear].x][q[rear].y] = dist[q[front].x][q[front].y] + 1; 
				rear++;
			}
		}
		front++;
	}
	return -1;
}

bool solve () {

	memset (ans, -1, sizeof (ans));
	for (int i = 0; i <= Q; i++)
		for (int j = i + 1; j <= Q; j++) {

			ans[i][j] = ans[j][i] = bfs (precious[i], precious[j]);
			if (ans[i][j] == -1) 
				return false;
		}
	
	return true;
}
/*
void dfs (int k, int x, int sum) {

	if (k == Q) {
	
		mm = Min (mm, sum);
		return;
	}

	for (int i = 1; i <= Q; i++) {

		if ( !vis[i] && ans[x][i]!= -1) {
		
			if (sum + ans[x][i] >= mm)
				return;
			vis[i] = 1;
			dfs (k + 1, i, sum + ans[x][i]);		 
			vis[i] = 0;
		}
	}
}
*/
void dfs () {
	
	int s[M];
	for (int i = 1; i <= Q; i++)
		s[i - 1] = i;	
	sort (s, s + Q);
	int sum = 0;
	do {

		sum = ans[0][s[0]];
		for (int i = 0; i < Q - 1; i++)
			sum += ans[s[i]][s[i + 1]];
		mm = Min (mm, sum);
	} while (next_permutation (s, s + Q));
}

int main () {

	char ch;
	while (scanf("%d%d%c", &n, &m, &ch), n || m) {

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {

				scanf("%c", &map[i][j]);
				if (map[i][j] == '@') {

					precious[0].x = i;
					precious[0].y = j;
				}
			}
			scanf ("%c", &ch);	
		}

		scanf("%d", &Q);
		for (int i = 1; i <= Q; i++) {

			scanf ("%d%d", &precious[i].x, &precious[i].y);
			precious[i].x--;
			precious[i].y--;
		}

		if (!solve())
			printf ("-1\n");
		else {

			mm = INF;
			memset(vis, 0, sizeof (vis));
			//dfs (0, 0, 0);
			dfs();
			printf ("%d\n", mm);
		}

	}
	return 0;
}

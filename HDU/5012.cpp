#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

const int N = 6;
const int maxn = 30;

const int dir[4][N] = {{3, 2, 0, 1, 4, 5}, 
	                   {2, 3, 1, 0, 4, 5},
					   {5, 4, 2, 3, 0, 1},
					   {4, 5, 2, 3, 1, 0}};
struct State {

	int dice[N];
}st[maxn];

int ans;
int p[maxn];

map<int ,int> vis;

int hash (State a) {

	int sum = 0;
	for (int i = 0; i < N; i++)
		sum = sum * 10 + a.dice[i];
	return sum;
}

int bfs () {

	int front, rear;
	front = 0;
	rear = 1;

	vis.clear();
	p[0] = 0;
	vis[hash (st[0])] = 1;
	while (front < rear) {
		
		if (hash (st[front]) == ans)
			return front;
		for (int i = 0; i < 4; i++) {

			for (int j = 0; j < N; j++) 
				st[rear].dice[j] = st[front].dice[dir[i][j]];

			int tmp = hash (st[rear]);
			if (!vis[tmp]) {
				vis[tmp] = 1;
				p[rear] = p[front] + 1;
				rear++;
			}
		}
		front++;
	}
	return -1;
}

int main () {

	int num;
	while (scanf ("%d%d%d%d%d%d", &st[0].dice[0], &st[0].dice[1], &st[0].dice[2], &st[0].dice[3], &st[0].dice[4], &st[0].dice[5]) != EOF) {

		ans = 0;
		for (int i = 0; i < N; i++) {
			
			scanf ("%d", &num);
			ans = ans * 10 + num;
		}
		
		int flag = bfs();
		if (flag == -1)
			printf ("-1\n");
		else
			printf ("%d\n", p[flag]);
	}
	return 0;
}

#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

const int maxn = 1e7;
const int INF = 0x7f7f7f7f;
const int M = 3;

map<int, int> vis;
int q[maxn][M];
int c[M];
int L[maxn];
int d;
int Min, MinL;
bool flag;

bool cmp (int k) {

	for (int i = 0; i < M; i++)
		if (q[k][i] == d) {
		
			Min = d;
			if (!flag)
				MinL = L[k];
			if (flag && MinL > L[k])
				MinL = L[k];
			return true;
		}

	if (!flag) {

		int tmp = -1;
		for (int i = 0; i < M; i++)
			if (q[k][i] < d && tmp < q[k][i])
				 tmp = q[k][i];

		if (Min < tmp) {
			Min = tmp;
			MinL = L[k];
		} else if (Min == tmp && MinL > L[k]) 
			MinL = L[k];
	}
	return false;
}

int hash (int k) {

	int ans = 0;
	for (int i = 0; i < M; i++)
		ans = ans * 1000 + q[k][i];
	return ans;
}

void bfs () {

	int front, rear;
	int tmp;
	front = 0;
	rear = 1;
	MinL = INF;
	Min = -1;
	flag = 0;
	vis.clear();
	while (front < rear) {

		if (cmp(front)) {
			front++;
			flag = 1;
			continue;
		}									
		for (int i = 0; i < M; i++) {

			if (!q[front][i])
				continue;
			for (int j = 0; j < M; j++) {
				
				if (i == j)
					continue;
				if (q[front][j] == c[j])
					continue;

				tmp = q[front][j] + q[front][i];
				memcpy (q[rear], q[front], 3 * sizeof (int));

				if (tmp > c[j]) {
					q[rear][j] = c[j];
					q[rear][i] = tmp - c[j];
				} else {
					q[rear][j] = tmp;
					q[rear][i] = 0;
				}

				L[rear] = L[front] + q[front][i] - q[rear][i];	
				tmp = hash (rear);
				if (!vis[tmp]) {
					vis[tmp] = 1;
					rear++;
				}
			}
		}
		front++;
	}
}

int main () {

	int t;
	scanf ("%d", &t);
	while (t--) {

		scanf ("%d%d%d%d", &c[0], &c[1], &c[2], &d);
		q[0][0] = q[0][1] = 0;
		q[0][2] = c[2];
		L[0] = 0;
		bfs();
		printf ("%d %d\n", MinL, Min);
//		printf ("%d %d %d %d\n", q[1][0], q[1][1], q[1][2], L[1]);
	}
	return 0;
}

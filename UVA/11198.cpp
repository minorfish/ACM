#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;

const int MAXN = 1000005;
const int N = 8;
int state[MAXN][N], head[MAXN], next[MAXN], dist[MAXN];

bool cmp (const int& a, const int& b) {

	if (abs(a) < abs(b))
		return true;
	return false;
}

bool is_prime (int n) {

	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return false;
	return true;
}

int hash (int rear) {

	int sum = 0;
	for (int i = 0; i < N; i++) 
		sum = sum  * 10 + abs(state[rear][i]);
	return sum % MAXN;
}

bool trytoinsert (int rear) {

	int p = hash (rear);
	int u = head[p];
	while (u) {

		if (memcmp(state[rear], state[u], sizeof (state[u])) == 0)
			return false;
		u = next[u];
	}

	next[rear] = head[p]; 
	head[p] = rear;
	return true;
}

void change (int p1, int p2, int front, int& rear, int dir) {

	int temp = state[front][p1];
	memcpy (state[rear], state[front], sizeof (state[front]));
	if (p1 < p2) {

		if (dir == 0) {

			for (int i = p1 + 1; i < p2; i++)
				state[rear][i - 1] = state[rear][i];
			state[rear][p2 - 1] = temp;
		} else {

			for (int i = p1 + 1;i <= p2; i++)
				state[rear][i - 1] = state[rear][i];
			state[rear][p2] = temp;

		}
	}
	if (p1 > p2) {

		if (dir == 1) {

			for (int i = p1; i > p2; i--) 
				state[rear][i] = state[rear][i - 1];
			state[rear][p2 + 1] = temp;
		} else {

			for (int i = p1; i >= p2; i--)
				state[rear][i]= state[rear][i - 1];
			state[rear][p2] = temp;
		}
	}
	if (trytoinsert(rear)) {

		dist[rear] = dist[front] + 1; 
		rear++;
	}
}

int bfs () {

	int front, rear;
	front = 1;
	rear = 2;
	memset (dist, 0, sizeof (dist));
	memset (head, 0, sizeof(head));
	while (front < rear) {

		if (memcmp (state[0], state[front], sizeof (state[0])) == 0) 
			return dist[front];
		for (int i = 0; i < N; i++) {	
			for (int j = 0; j < N; j++) {

				if (i != j && state[front][i] * state[front][j] < 0 && is_prime (abs (state[front][i]) + abs (state[front][j]))) {

					change (i, j, front, rear, 0);
					change (i, j, front, rear, 1);
				}
			}
		}
		front++;
	}
	return -1;
}

int main () {

	int t = 0;
	while (scanf ("%d", &state[1][0]), state[1][0]) {

		for (int i = 1; i < N; i++) 
			scanf ("%d", &state[1][i]);
		memcpy(state[0], state[1], sizeof (state[1]));
		sort (state[0], state[0] + N, cmp);	
		printf ("Case %d: %d\n", ++t, bfs());
	}
	return 0;
}

#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int>pii;
priority_queue<pii, vector<pii>, greater<pii> >q;

const int maxn = 10;
const int maxm = 100;
const int INF = 1e6;
const int wait = 60;

int t[maxn];
int floor[maxm];
int w[maxm][maxm];
int d[maxm];

void read_Graph (int n, int k) {

	int pos;
	char ch;

	for (int i = 0; i < maxm; i++)
		for (int j = i; j < maxm; j++)
			w[j][i] = w[i][j] = (i==j)? 0 : INF;

	for (int i = 0; i < n; i++)
		scanf ("%d", &t[i]);
	for (int i = 0; i < n; i++) {

		pos = 0;
		do {
			scanf ("%d%c", &floor[pos++], &ch);
		} while (ch != '\n');

		for (int j = 0; j < pos; j++)
			for (int x = j; x < pos; x++)
				if (w[floor[x]][floor[j]] > (floor[x] - floor[j]) * t[i])
					w[floor[x]][floor[j]] = w[floor[j]][floor[x]] = (floor[x] - floor[j]) * t[i];
	}

}

int Dijkstra (int n, int k) {
	
	for (int i = 0; i < maxm; i++)
		d[i] = INF;

	d[0] = 0;
	
	pii u = make_pair(d[0], 0);
	q.push(u);

	while (!q.empty()) {

		u = q.top();
		q.pop();

		if (u.first != d[u.second]) continue;

		for (int i = 0; i < maxm; i++) {
			if (i == u.second) continue;

			if (u.second == 0) {

				if (d[i] > u.first + w[u.second][i])
					d[i] = u.first + w[u.second][i];
				q.push(make_pair(d[i], i));

			} else if (d[i] > u.first + w[u.second][i] + wait) {

					d[i] = u.first + w[u.second][i] + wait;
					q.push(make_pair(d[i], i));
			}
		}	
	}

	return d[k];
}

int main () {

	int n, k;

	while (scanf ("%d%d", &n, &k) != EOF) {
		read_Graph(n, k);
		int ans = Dijkstra(n, k);

		if (ans == INF)
			printf ("IMPOSSIBLE\n");
		else
			printf ("%d\n", ans);
	}
	return 0;
}

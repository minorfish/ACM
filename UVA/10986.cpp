#include <cstdio>
#include <queue>
#include <vector>
#include <string.h>  

using namespace std;
using std::make_pair;

typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii> >q;

const int INF = 0x3f3f3f3f;
const int maxn = 2e4;
const int maxm = 1e5 + 5;

int first[maxn];
int u[maxm], v[maxm], w[maxm], next[maxm];
int d[maxn];

void read_Graph (int n, int m) {

	for (int i = 0; i < n; i++)
		first[i] = -1;

	m *= 2;
	for (int i = 0; i < m; i++) {
		scanf ("%d%d%d", &u[i], &v[i], &w[i]);
		next[i] = first[u[i]];
		first[u[i]] = i;

		i++;
		u[i] = v[i - 1];
		v[i] = u[i - 1];
		w[i] = w[i - 1];
		next[i] = first[u[i]];
		first[u[i]] = i;
	}
}

int Dijkstra (int s, int t, int n) {

	for (int i = 0; i < n; i++)
		d[i] = (i == s) ? 0 : INF;

	q.push(make_pair(d[s],s));

	pii cur;
	while (!q.empty()) {

		cur = q.top();
		q.pop();

		if (cur.first != d[cur.second]) continue;

		for (int i = first[cur.second]; i != -1; i = next[i])
			if (d[v[i]] > d[u[i]] + w[i]) {
				d[v[i]] = d[u[i]] + w[i];
				q.push(make_pair(d[v[i]], v[i]));
			}
	}

	return d[t];
}

int main () {

	int T;
	scanf ("%d", &T);

	int n, m, s, t, cas = 0;
	while (T--) {

		scanf ("%d%d%d%d", &n, &m, &s, &t);

		read_Graph(n, m);
		int ans = Dijkstra(s, t, n);

		if (ans == INF)
			printf ("Case #%d: unreachable\n", ++cas);
		else
			printf ("Case #%d: %d\n", ++cas, ans);
	}
	return 0;
}

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn = 505;
const int maxm = 300000;

int u[maxm], v[maxm], r[maxm];
int p[maxn];
double w[maxm];

struct Node {

	int x, y;
}node[maxn];

double dist (int i, int j) {

	double x = node[i].x - node[j].x;
	double y = node[i].y - node[j].y;
	return sqrt(x * x + y * y);
}

void init (int n, int cnt) {

	for (int i = 0; i < n; i++)
		p[i] = i;
	for (int i = 0; i < cnt; i++)
		r[i] = i;
}

int getParent (int x) {
	return (x == p[x]) ? x : p[x] = getParent(p[x]);
}

int cmp (int i, int j) {
	return w[i] < w[j];
}

double Kruskal (int n, int cnt, int m) {

	init(n, cnt);
	sort(r, r + cnt, cmp);

	int flag = n - m;
	double ans;

	for (int i = 0; i < cnt; i++) {

		int P = getParent(u[r[i]]);
		int Q = getParent(v[r[i]]);
		if (P == Q) continue;

		if (flag--) { 
			ans = w[r[i]];
			p[P] = Q;
		} else
			return ans;
	}
	return ans;
}

int main () {

	int T;
	scanf ("%d", &T);

	int n, m;
	while (T--) {

		scanf ("%d%d", &m, &n);	

		for (int i = 0; i < n; i++)
			scanf ("%d%d", &node[i].x, &node[i].y);
		
		int pos = 0;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++) {
				u[pos] = i;
				v[pos] = j;
				w[pos++] = dist(i, j);
			}

		printf ("%.2lf\n", Kruskal(n, pos, m));
	}
	return 0;
}

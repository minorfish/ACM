#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 755;
const int maxm = 3e5;

struct Node {
	int x, y;
}node[maxn];

double w[maxm];
int p[maxn], u[maxm], v[maxm];
int vis[maxn][maxn], r[maxm];

double dist (int i, int j) {

	double x = node[i].x - node[j].x;
	double y = node[i].y - node[j].y;
	return sqrt(x * x + y * y);
}

void init (int n) {	
	for (int i = 0; i < n; i++)
		p[i] = i;
}

int getParent (int x) {
	return (x == p[x]) ? p[x] : p[x] = getParent(p[x]);
}

int cmp (int i, int j) {
	return w[i] < w[j];
}

double Kruskal (int n, int m) {

	double ans = 0;

	init(n);
	for (int i = 0; i < m; i++)
		r[i] = i;

	sort(r, r + m, cmp);

	for (int i = 0; i < m; i++) {
		
		int P = getParent(u[r[i]]);
		int Q = getParent(v[r[i]]);
		if (P == Q) continue;
		
		ans += w[r[i]];
		p[P] = Q;
	}

	return ans;
}

int main () {

	int n, m;
	while (scanf ("%d", &n) != EOF) {
		
		for (int i = 0; i < n; i++) 
			scanf ("%d%d", &node[i].x, &node[i].y);	

		int x, y;
		memset (vis, 0, sizeof(vis));
		scanf ("%d", &m);	
		for (int i = 0; i < m; i++) {
			scanf ("%d%d", &x, &y);
			vis[x - 1][y - 1] = vis[y - 1][x - 1] = 1;
		}

		int pos = 0;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++) {
				u[pos] = i;
				v[pos] = j;
				if (vis[i][j])
					w[pos++] = 0;
				else
					w[pos++] = dist(i, j);
			}

		printf ("%.2lf\n", Kruskal(n, pos));	
	}
	return 0;
}

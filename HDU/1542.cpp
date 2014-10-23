#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 205;

#define lson(x) (x<<1)
#define rson(x) ((x<<1) | 1)

struct Node {

	int l, r, add;
	double s;
	void set (int l, int r, double s, int add) {

		this->l = l;
		this->r = r;
		this->s = s;
		this->add = add;
	}
}node[4 * maxn];

struct Line {
	
	double x, y1, y2;
	int flag;
	Line (double x, double y1, double y2, int flag) {
	
		this->x = x;
		this->y1 = y1;
		this->y2 = y2;
		this->flag = flag;
	}

	bool operator < (const Line &l) const {
		
		return x < l.x;   
	}
};

int n;
vector<Line> L;
vector<double> pos;

void pushup(int u) {

	if (node[u].add) 
		node[u].s = pos[node[u].r + 1] - pos[node[u].l];
	else if (node[u].l == node[u].r)
		node[u].s = 0;
	else
		node[u].s = node[lson(u)].s + node[rson(u)].s;
}

void build (int u, int l, int r) {

	node[u].set (l, r, 0, 0);
	if (l == r)
		return;
	int m = (l + r)>>1;
	build(lson(u), l, m);
	build(rson(u), m + 1, r);
}

void update (int u, int l, int r, int v) {

	if (node[u].l >= l && node[u].r <= r) {
		node[u].add += v;
		pushup(u);
		return;
	}

	int m = (node[u].l + node[u].r)>>1;
	if (l <= m)
		update (lson(u), l, r, v);
	if (r > m)
		update (rson(u), l, r, v);
	pushup(u);
}

void init () {

	pos.clear();
	L.clear();
	double x1, y1, x2, y2;

	for (int i = 0; i < n; i++) {
		scanf ("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
		pos.push_back(y1);
		pos.push_back(y2);
		L.push_back(Line(x1, y1, y2, 1));
		L.push_back(Line(x2, y1, y2, -1));
	}

	sort (pos.begin(), pos.end());
	sort (L.begin(), L.end());
	pos.erase(unique(pos.begin(), pos.end()), pos.end());

	build(1, 0, (int)pos.size() - 1);
}

double solve() {

	init();
	double ans = 0;
	for (int i = 0; i < (int)L.size() - 1; i++) {

		int l = lower_bound(pos.begin(), pos.end(), L[i].y1) - pos.begin();
		int r = lower_bound(pos.begin(), pos.end(), L[i].y2) - pos.begin();
		update (1, l, r - 1, L[i].flag);
//		printf ("%.2lf\n", node[1].s);
		ans += node[1].s * (L[i + 1].x - L[i].x);	
	}
	return ans;
}

int main () {

	int T = 0;
	double x1, y1, x2, y2;
	while (scanf ("%d", &n) && n) {

		printf ("Test case #%d\n", ++T);
		printf ("Total explored area: %.2lf\n\n", solve());
	}
	return 0;
}

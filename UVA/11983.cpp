#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define lson(x) (x<<1)
#define rson(x) ((x<<1) | 1)

const int maxn = 60005;
typedef long long ll;

struct Line {

	int x, y1, y2, flag;
	Line (int x, int y1, int y2, int flag) {

		this->x = x;
		this->y1 = y1;
		this->y2 = y2;
		this->flag = flag;
	}

	bool operator < (const Line & a) const {
		return x < a.x;
	}
};

struct Node {

	int l, r, add;
	ll s[12];
	void set (int l, int r, int add) {

		this->l = l;
		this->r = r;
		this->add = add;
	}
}node[maxn * 4];


vector<int> pos;
vector<Line> L;
int n, k;

void pushup(int u) {

	for (int i = 0; i <= k; i++)
		node[u].s[i] = 0L;

	int t;
	if (node[u].l == node[u].r) {
		t = min(k, node[u].add);
		node[u].s[t] = pos[node[u].l + 1] - pos[node[u].l]; 
	} else {
		for (int i = 0; i <= k; i++) {	
			t = min (i + node[u].add, k);
			node[u].s[t] += node[lson(u)].s[i] + node[rson(u)].s[i];
		}
	}
}

void build (int u, int l, int r) {

	node[u].set(l, r, 0);

	if (l == r) { 
		pushup(u);
		return;
	}

	int m = (l + r)>>1;
	build(lson(u), l, m);
	build(rson(u), m + 1, r);
	pushup(u);
}

void update (int u, int l, int r , int v) {

	if (l <= node[u].l && r >= node[u].r) {
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

	int x1, y1, x2, y2;
	scanf ("%d%d", &n, &k);
	L.clear();
	pos.clear();

	for (int i = 0; i < n; i++) {

		scanf ("%d%d%d%d", &x1, &y1, &x2, &y2);

		L.push_back(Line(x1, y1, y2 + 1, 1));
		L.push_back(Line(x2 + 1, y1, y2 + 1, -1));
		pos.push_back(y1);
		pos.push_back(y2 + 1);
	}

	sort(L.begin(), L.end());
	sort(pos.begin(), pos.end());
	pos.erase (unique(pos.begin(), pos.end()), pos.end());

	build(1, 0, (int)pos.size() - 1);
}

ll solve () {

	init();
	ll ans = 0;

	int l, r;
	for (int i = 0; i < L.size() - 1; i++) {

		l = lower_bound(pos.begin(), pos.end(), L[i].y1) - pos.begin();	
		r = lower_bound(pos.begin(), pos.end(), L[i].y2) - pos.begin();

		update (1, l, r - 1, L[i].flag);
		ans += node[1].s[k] * (L[i + 1].x - L[i].x);  
	}
	return ans;	
}

int main () {

	int T;
	scanf ("%d", &T);

	for (int cas = 1; cas <= T; cas++)
		printf ("Case %d: %lld\n", cas, solve());
	return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1e6 + 5;
const int N = 1e5 + 5;
#define lson(x) (x<<1)
#define rson(x) ((x<<1) | 1)

struct Node {

	int l, r, ns, nc;
	void set (int l, int r, int ns, int nc) {

		this->l = l;
		this->r = r;
		this->ns = ns;
		this->nc = nc;
	}
}node[4 * maxn];

void pushup (int u) {
	
	node[u].set (node[lson(u)].l, node[rson(u)].r, 0, 0);
}

void add_node (int u, int adds, int addc) {

	node[u].ns += adds;
	node[u].nc += addc;	
}

void pushdown (int u) {

	if (node[u].ns || node[u].nc) {
		add_node(lson(u), node[u].ns, node[u].nc);
		add_node(rson(u), node[u].ns, node[u].nc);	
	}
}

void build (int u, int l, int r) {

	if (l == r) {
		node[u].set (l, r, 0, 0);
		return;
	}

	int m = (l + r)>>1;
	build (lson(u), l, m);
	build (rson(u), m + 1, r);
	pushup(u);
}

void update (int u, int l, int r, int addc, int adds) {

	if (node[u].l >= l && node[u].r <= r) {
		add_node (u, adds, addc);	
		return;
	}
	
	int m = (node[u].l + node[u].r)>>1;
	pushdown(u);
	if (l <= m)
		update (lson(u), l, r, addc, adds);
	if (r > m)
		update (rson(u), l, r, addc, adds);
	pushup(u);
}

int query (int u, int x) {

	if (node[u].l == x && node[u].r == x)
		return u;
	
	int m = (node[u].l + node[u].r)>>1;
	int ans;

	pushdown(u);
	if (x <= m)
		ans = query (lson(u), x);
	else
		ans = query (rson(u), x);
	pushup(u);
	return ans;
}

int p[N], cnt[N], L[N], R[N];
int n, m;

int getParent (int x) {
	return x == p[x] ? x: p[x] = getParent (p[x]);
}

void change (int u, int l, int r, int addc, int adds) {

	if (r < l) 
		return;
	update (u, l, r, addc, adds); 
}

void Union(int x, int y) {

	x = getParent (x);
	y = getParent (y);

	if (x == y)
		return;

	if (L[x] >= L[y])
		swap(x, y);
	
	if (R[x] <= L[y]) {

		change (1, L[x], R[x] - 1, cnt[y], 0);		
		change (1, L[y], R[y] - 1, cnt[x], 0);
		change (1, R[x], L[y] - 1, cnt[x] + cnt[y], 1);
	} else if (R[y] <= R[x]) {

		change (1, L[x], L[y] - 1, cnt[y], 0);
		change (1, R[y], R[x] - 1, cnt[y], 0);
		change (1, L[y], R[y] - 1, 0, -1);
	} else {

		change (1, L[x], L[y] - 1, cnt[y], 0);
		change (1, R[x], R[y] - 1, cnt[x], 0);
		change (1, L[y], R[x] - 1, 0, -1);
	}

	p[x] = y;
	cnt[y] += cnt[x];
	L[y] = min (L[y], L[x]);
	R[y] = max (R[y], R[x]);
}

void init () {

	int x, y;
	scanf ("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf ("%d%d", &x, &y);
		p[i] = i;
		cnt[i] = 1;
		L[i] = R[i] = y;
	
	}
	
	scanf ("%d", &m);
	build (1, 0, maxn - 5);
}

void solve () {

	char str[100];
	int x, y;
	double q;

	for (int i = 0; i < m; i++) {

		scanf ("%s", str);

		if (str[0] == 'r') {
			scanf ("%d%d", &x, &y);		
			Union(x, y);
		} else {
			scanf ("%lf", &q);
			x = query (1, (int)q);
			printf ("%d %d\n", node[x].ns, node[x].nc);
		}
	}
}

int main () {
	
	int T;
	scanf ("%d", &T);
	
	while (T--) {

		init();
		solve();	
	}
	return 0;
}

#include <cstdio>
#include <cstring>

const int maxn = 1e5 + 5;

#define lson(x) ((x)<<1)
#define rson(x) (((x)<<1) + 1)

struct Node {

	int l, r, h, sign;
	void set (int l, int r, int h, int sign) {

		this->l = l;
		this->r = r;
		this->h = h;
		this->sign = sign;
	}
}node[4 * maxn];

void pushdown(int u) {

	node[lson(u)].sign = node[rson(u)].sign = 1;		
	node[lson(u)].h = node[rson(u)].h = node[u].h;
	node[u].sign = 0;
	node[u].h = 0;
}

void pushup (int u) {

	node[u].l = node[lson(u)].l;
	node[u].r = node[rson(u)].r;

	if (node[lson(u)].sign && node[rson(u)].sign && node[lson(u)].h == node[rson(u)].h) {

		node[u].sign = 1;
		node[u].h = node[lson(u)].h;
	} else 
		node[u].sign = node[u].h = 0;
}

void build (int u, int l, int r) {

	if (l == r)
		node[u].set(l, r, 0, 1);
	else {

		int m = (l + r) / 2;
		build(lson(u), l, m);
		build(rson(u), m + 1, r);
		pushup(u);
	}
}

int update (int u, int l, int r, int h) {

	if (node[u].sign && node[u].h > h)
		return 0;

	if (node[u].l >= l && node[u].r <= r && node[u].sign) {

		node[u].h = h;
		return node[u].r - node[u].l + 1;
	}

	int ret = 0;
	int m = (node[u].l + node[u].r) / 2;

	if (node[u].sign)
		pushdown(u);

	if (l <= m)		
		ret += update (lson(u), l, r, h);
	if (r > m)
		ret += update (rson(u), l, r, h);
	pushup(u);

	return ret;
}

int main () {

	int T;
	int n, l, r, h, ans;

	scanf ("%d", &T);

	while (T--) {

		build(1, 1, maxn);
		scanf ("%d", &n);
		
		ans = 0;
		for (int i = 0; i < n; i++) {

			scanf ("%d%d%d", &l, &r, &h);
			ans += update (1, l + 1, r, h);	
		}

		printf ("%d\n", ans);
	}
	return 0;
}

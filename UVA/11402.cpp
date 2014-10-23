#include <cstdio>
#include <cstring>

#define lson(x) (x<<1)
#define rson(x) ((x<<1) + 1)

const int maxn = 1100000;
int v[maxn];

struct Node {

	int l, r, v;
	int setv, resv;
	void set (int l, int r, int v, int setv, int resv) {

		this->l = l;
		this->r = r;
		this->v = v;
		this->setv = setv;
		this->resv = resv;
	}
}node[4 * maxn];

inline void pushup (int u) {

	node[u].set(node[lson(u)].l, node[rson(u)].r, node[lson(u)].v + node[rson(u)].v, -1, 0);
}

inline void set_node(int u, int v) {

	node[u].setv = v;
	node[u].resv = 0;
	node[u].v = v * (node[u].r - node[u].l + 1);	
}

inline void res_node(int u) {

	node[u].resv ^= 1;
	node[u].v = node[u].r - node[u].l + 1 - node[u].v;
}

inline void pushdown (int u) {

	if (node[u].setv >= 0) {

		set_node(lson(u), node[u].setv);
		set_node(rson(u), node[u].setv);
		node[u].setv = -1;
	}

	if (node[u].resv) {

		res_node(lson(u));
		res_node(rson(u));
		node[u].resv = 0;
	}	
}

void build (int u, int l, int r) {

	if (l == r) 
		node[u].set(l, r, v[l - 1], -1, 0);
	else {

		int m = (l + r) / 2;
		build (lson(u), l, m);
		build (rson(u), m + 1, r);
		pushup(u);
	}
}

void update (int u, int l, int r, int v) {

	if (node[u].l >= l && node[u].r <= r) {
		set_node(u, v);
		return;
	}
	int m = (node[u].l + node[u].r) / 2;

	pushdown(u);
	if (l <= m)
		update (lson(u), l, r, v);
	if (r > m)
		update (rson(u), l, r, v);
	pushup(u);				
}

void reserve (int u, int l, int r) {

	if (node[u].l >= l && node[u].r <= r) {
		res_node(u);
		return;
	}

	int m = (node[u].l + node[u].r) / 2;

	pushdown(u);
	if (l <= m)
		reserve(lson(u), l, r);
	if (r > m)
		reserve(rson(u), l, r);
	pushup(u);
}

int query (int u, int l, int r) {

	if (node[u].l >= l && node[u].r <= r)
		return node[u].v;

	int m = (node[u].l + node[u].r) / 2;

	int ret = 0;
	pushdown(u);
	if (l <= m)
		ret += query (lson(u), l, r);
	if (r > m)
		ret += query (rson(u), l, r);
	pushup(u);

	return ret;
}

int main () {

	int T, n, t, q;
	int x, y;
	int N, len;
	char s[100];

	scanf ("%d", &T);

	for (int i = 1; i <= T; i++) {

		printf ("Case %d:\n", i);
		memset (v, 0, sizeof (v));
		len = 0;

		scanf ("%d", &n);
		while (n--) {

			scanf ("%d%s", &t, s);
			N = strlen (s);
			for (int j = 0; j < t; j++) 
				for (int k = 0; k < N; k++) {
					if (s[k] == '1')
						v[len] = 1;
					len++;
				}
		}

		build(1, 1, len);

		scanf ("%d", &q);
		int cas = 0;
		while (q--) {
			scanf ("%s%d%d", s, &x, &y);
			if (s[0] == 'F') 
				update(1, x + 1, y + 1, 1);
			else if (s[0] == 'E')
				update (1, x + 1, y + 1, 0);
			else if (s[0] == 'I')
				reserve(1, x + 1, y + 1);
			else 
				printf ("Q%d: %d\n", ++cas, query(1, x + 1, y + 1)); 	
		}
	}
	return 0;
}

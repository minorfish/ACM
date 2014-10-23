#include <cstdio>
#include <cstring>

const int N = 5e4 + 5;

#define lson(x) (2*(x))
#define rson(x) (2*(x) + 1)

struct Node {

	int l, r, v;
	void set(int l, int r, int v) {
		this->l = l;
		this->r = r;
		this->v = v;
	}
}node[4 * N];

void build (int u, int l, int r) {

	if (l == r)
		node[u].set(l, r, 1);
	else {

		int m = l + (r - l) / 2;
		build(lson(u), l, m);
		build(rson(u), m + 1, r);
		node[u].set(l, r, node[lson(u)].v + node[rson(u)].v);
	}
}

int Query (int u, int k) {

	if (node[u].l == node[u].r)
		return node[u].l;
	if (k > node[lson(u)].v)
		return Query(rson(u), k - node[lson(u)].v);
	else
		return Query(lson(u), k);
}

void Update (int u, int p, int v) {

	if (node[u].l == node[u].r) 
		node[u].v = v;
	else {

		int m = node[u].l + (node[u].r - node[u].l) / 2;
		if (p <= m)
			Update (lson(u), p, v);
		else
			Update (rson(u), p, v);
		node[u].v = node[lson(u)].v + node[rson(u)].v;
	}
}

int main () {

	int T, K, num, p;
	scanf ("%d", &T);
	while (T--) {

		scanf ("%d", &K);	
		build(1, 1, K);
		for (int i = 0; i < K; i++) {

			scanf ("%d", &num);
			p = Query (1, num + 1);
			if (i != K - 1)
				printf ("%d ", p);
			else
				printf ("%d\n", p);
			Update(1, p, 0); 
		}
	}
	return 0;
}

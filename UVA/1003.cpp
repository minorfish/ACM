#include <cstdio>
#include <cstring>
#include <cmath>

const int maxn = 50005;
#define lson(x) (x<<1)
#define rson(x) ((x<<1) | 1)

int num[maxn];

struct NODE {
	
	int l, r, v;
	int setv, addv;
	void set (int l, int r, int v, int setv = -1, int addv = 0) {
		this->l = l;
		this->r = r;
		this->v = v;
		this->setv = setv;
		this->addv = addv;
	}
}node[4 * maxn];

void setnode (int u, int v) {
	node[u].setv = v;	
	node[u].v = (node[u].r - node[u].l + 1) * v;
	node[u].addv = 0;
}

void addnode (int u, int v) {
	node[u].addv += v;
	node[u].v += (node[u].r - node[u].l + 1) * v;
}

void pushup (int u) {
	
	node[u].set(node[lson(u)].l, node[rson(u)].r, node[lson(u)].v + node[rson(u)].v);
}

void pushdown (int u) {
	
	if (node[u].setv != -1) {
		setnode(lson(u), node[u].setv);
		setnode(rson(u), node[u].setv);
		node[u].setv = -1;
	}

	if (node[u].addv) {
		addnode(lson(u), node[u].addv);
		addnode(rson(u), node[u].addv);
		node[u].addv = 0;
	}
}

void build (int u, int l, int r) {

	if (l == r) {
		node[u].set(l, r, num[l], -1, 0); 
		return;
	}

	int m = (l + r) / 2;
	build (lson(u), l, m);
	build (rson(u), m + 1, r);
	pushup(u);		
}

void add (int u, int l, int r, int v) {
	
	if (node[u].l >= l && node[u].r <= r) {	
		addnode(u, v);
		return;
	}

	pushdown(u);

	int m = (node[u].l + node[u].r) / 2;
	if (l <= m)
		add(lson(u), l, r, v);
	if (m < r)
		add(rson(u), l, r, v);
	
	pushup(u);	
}

void set (int u, int l, int r, int v) {
	
	if (node[u].l >= l && node[u].r <= r) {
		setnode(u, v);
		return;
	}

	pushdown(u);

	int m = (node[u].l + node[u].r) / 2;
	if (l <= m)
		set (lson(u), l, r, v);
	if (m < r)
		set (rson(u), l, r, v);

	pushup(u);
}

int query (int u, int l, int r) {
	
	if (node[u].l >= l && node[u].r <= r) {
		return node[u].v;
	}

	int ans = 0;

	pushdown(u);

	int m = (node[u].l + node[u].r) / 2;
	if (l <= m)
		ans += query (lson(u), l, r);
	if (m < r)
		ans += query (rson(u), l, r);

	pushup(u);
	return ans;
}

int main () {
	
	int N, M, type;
	while (scanf ("%d%d", &N, &M) != EOF) {
	
		for (int i = 1; i <= N; i++)
			scanf ("%d", &num[i]);
	
		build (1, 1, N);
			
		int l, r, x;
		for (int i = 1; i <= M; i++) {
			scanf ("%d", &type);
			if (type == 1) {
				scanf ("%d%d", &l, &r);
				printf ("%d\n", query(1, l, r));
			} else if (type == 2) {
				scanf ("%d", &x);
				num[x] = pow(2, num[x]);
				set(1, x, x, num[x]);
				
			} else {
				scanf ("%d%d%d", &l, &r, &x);
				for (int i = l; i <= r; i++)
					num[i] += x;    
				add(1, l, r, x); 
			}
		}
	}
	return 0;
}

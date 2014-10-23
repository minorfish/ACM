#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define lson(x) ((x)<<1)
#define rson(x) (((x)<<1) + 1)

const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;

struct Item {

	int sum, Max_num, Min_num;

	Item (int sum = 0, int Max_num = -INF, int Min_num = INF) {
		this->set(sum, Max_num, Min_num);
	}

	void set (int sum, int Max_num, int Min_num) {
		this->sum = sum;
		this->Max_num = Max_num;
		this->Min_num  = Min_num;
	}
};

struct Node {

	Item v;
	int l, r;
	int addv, setv;

	void set (int l, int r, int addv = 0, int setv = -1) {
		this->l = l;
		this->r = r;
		this->addv = addv;
		this->setv = setv;	
	}

}node[4 * N];

Item get_item (Item a, Item b) {

	return Item(a.sum + b.sum, max(a.Max_num, b.Max_num), min(a.Min_num, b.Min_num));
}

void Node_add(int u, int addv) {

	node[u].addv += addv;
	node[u].v.sum += addv * (node[u].r - node[u].l + 1);
	node[u].v.Max_num += addv;
	node[u].v.Min_num += addv;
}

void Node_set(int u, int setv) {

	node[u].setv = setv;
	node[u].addv = 0;
	node[u].v.sum = setv * (node[u].r - node[u].l + 1);
	node[u].v.Max_num = node[u].v.Min_num = setv;
}

void pushup (int u) {

	node[u].set(node[lson(u)].l, node[rson(u)].r);
	node[u].v = get_item(node[lson(u)].v, node[rson(u)].v);
}

void pushdown(int u) {

	if (node[u].setv >= 0) {
		Node_set(lson(u), node[u].setv);
		Node_set(rson(u), node[u].setv);
		node[u].setv = -1;
	}

	if (node[u].addv) {
		Node_add(lson(u), node[u].addv);
		Node_add(rson(u), node[u].addv);
		node[u].addv = 0;	
	}
}

void Build (int u, int l, int r) {

	if (l == r) { 
		node[u].set(l, r);
		node[u].v.set(0, 0, 0);

	} else {

		int m = (l + r) / 2;
		Build(lson(u), l, m);
		Build(rson(u), m + 1, r);
		pushup(u);
	}
}

void Add (int u, int l, int r, int addv) {

	if (node[u].l >= l && node[u].r <= r)
		Node_add(u, addv);
	else {

		pushdown(u);
		int m = (node[u].l + node[u].r) / 2;
		if (l <= m)
			Add (lson(u), l, r, addv);
		if (r > m)
			Add (rson(u), l, r, addv);
		pushup(u);
	}
}

void Set (int u, int l, int r, int setv) {

	if (node[u].l >= l && node[u].r <= r)
		Node_set(u, setv);
	else {

		pushdown(u);
		int m = (node[u].l + node[u].r) / 2;
		if (l <= m)
			Set (lson(u), l, r, setv);
		if (r > m)
			Set (rson(u), l, r, setv);
		pushup(u);
	}
}

Item Query (int u, int l, int r) {

	if (node[u].l >= l && node[u].r <= r) 
		return node[u].v;
	else {

		Item ans;

		pushdown(u);
		int m = (node[u].l + node[u].r) / 2;
		if (l <= m)
			ans = get_item (ans, Query(lson(u), l, r));
		if (r > m)
			ans = get_item (ans, Query(rson(u), l, r));	
		pushup(u);

		return ans;
	}
}

int main () {

	int r, c, m;
	int type;
	int x1, y1, x2, y2, v;

	while (scanf ("%d%d%d", &r, &c, &m) != EOF) {

		Build(1, 1, r * c);

		while (m--) {
		
			scanf ("%d", &type);

			if (type == 1) {

				scanf ("%d%d%d%d%d", &x1, &y1, &x2, &y2, &v);

				for (int i = x1 - 1; i < x2; i++)
					Add(1, i * c + y1, i * c + y2, v);
			} else if (type == 2) {

				scanf ("%d%d%d%d%d", &x1, &y1, &x2, &y2, &v);
				for (int i = x1 - 1; i < x2; i++)
					Set(1, i * c + y1, i * c + y2, v);
			} else {

				scanf ("%d%d%d%d", &x1, &y1, &x2, &y2);

				Item ans;
				for (int i = x1 - 1; i < x2; i++)
					ans = get_item(ans, Query(1, i * c + y1, i * c + y2));
				printf ("%d %d %d\n", ans.sum, ans.Min_num, ans.Max_num);
			}
		}
	}
	return 0;
}

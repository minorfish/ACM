#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 2e5;
#define lson(x) (x<<1)
#define rson(x) ((x<<1) | 1)

int n;
vector<int> pos;
map<int, int>x, y;
set<int> score, vec;

struct Point {

	int x, y, score;
}p[maxn];

int cmp_x (const Point &a, const Point &b) {
	if (a.x == b.x)
		return a.y > b.y;
	return a.x < b.x;
}

struct Node {

	int l, r, v, addv;
	void set (int l, int r, int addv, int v) {

		this->l = l;
		this->r = r;
		this->v = v;
		this->addv = addv;
	}
}node[4 * maxn + 5];

void add_node (int u, int addv) {

	node[u].addv += addv;
	node[u].v += (node[u].r - node[u].l + 1) * addv;
}

void pushdown (int u) {

	if (node[u].addv) {
		add_node(lson(u), node[u].addv);
		add_node(rson(u), node[u].addv);
	}
}

void pushup (int u) {

	node[u].set (node[lson(u)].l, node[rson(u)].r, 0, node[lson(u)].v + node[rson(u)].v);
}

void build (int u, int l, int r) {

	if (l == r) {

		node[u].set (l, r, 0, y[pos[l]]);
		return ;
	}
	int m = (l + r)>>1;
	build (lson(u), l, m);
	build (rson(u), m + 1, r);
	pushup(u);
}

void update (int u, int l, int r, int add) {

	if (node[u].l >= l && node[u].r <= r) {
		add_node(u, add);
		return;
	}

	pushdown(u);
	int m = (node[u].l + node[u].r)>>1;
	if (l <= m)
		update (lson(u), l, r, add);
	if (r > m)
		update (rson(u), l, r, add);
	pushup(u);
}

int query (int u, int l, int r) {

	if (node[u].l >= l && node[u].r <= r)
		return node[u].v;

	pushdown(u);
	int m = (node[u].l + node[u].r)>>1;
	int ans = 0;
	if (l <= m)
		ans += query(lson(u), l, r);
	if (r > m)
		ans += query(rson(u), l, r);
	pushup(u);
	return ans;
}

void init () {

	x.clear();
	y.clear();
	pos.clear();

	for (int i = 0; i < n; i++) {

		scanf ("%d%d", &p[i].x, &p[i].y);
		p[i].score = 0;
		x[p[i].x]++;
		y[p[i].y]++;
		pos.push_back(p[i].y);
	}

	sort (pos.begin(), pos.end());
	sort (p, p + n, cmp_x);
	pos.erase(unique (pos.begin(), pos.end()), pos.end());
}

void solve_rtop () {

	int x;
	build(1, 0, (int)pos.size() - 1);
	for (int i = 0; i < n; i++) {

		x = lower_bound(pos.begin(), pos.end(), p[i].y) - pos.begin();
		if (x + 1 <= pos.size() - 1) {
			p[i].score += query(1, x + 1, pos.size() - 1);		
			//printf ("%d %d %d\n", p[i].x, p[i].y, x);
		}
		update (1, x, x, -1);		
	}	
}

void solve_lboutom () {

	int x;	
	build(1, 0, (int)pos.size() - 1);
	for (int i = n - 1; i >= 0; i--) {

		x = lower_bound(pos.begin(), pos.end(), p[i].y) - pos.begin();
		if (x - 1 >= 0) {
			p[i].score += query (1, 0, x - 1);
			//printf ("%d %d %d\n", p[i].x, p[i].y, p[i].score);
		}
		update (1, x, x, -1);
	}
}

void add_ans (int tmp) {

	for (set<int>::iterator it = vec.begin(); it != vec.end(); it++)
		score.insert(n - tmp - x[p[*it].x] - y[p[*it].y] + 1);	
}

void solve () {

	init();
	solve_lboutom();
	solve_rtop();
	score.clear();
	vec.clear();

	int ans = -1;
	int tmp = p[0].score;			
	int pre = p[0].x;

	for (int i = 0; i < n; i++)	{

		if (pre == p[i].x) {
			if (tmp == p[i].score)
				vec.insert(i);
			else if (tmp > p[i].score) {
				vec.clear();
				vec.insert(i);	
				tmp = p[i].score;
			}
		} else {

			if (ans <= tmp) {
				if (ans < tmp) 
					score.clear();
				add_ans(tmp);
			}
			ans = max (ans, tmp);
			tmp = p[i].score;
			pre = p[i].x;
			vec.clear();
			vec.insert(i);
		}
	}

	if (ans <= tmp) {
		if (ans < tmp) 
			score.clear();
		add_ans(tmp);
	}
	ans = max (ans, tmp);

	printf("Stan: %d; Ollie:", ans);
	for (set<int>::iterator it = score.begin(); it != score.end(); it++)
		printf(" %d", *it);
	printf(";\n");
}

int main () {

	while (scanf ("%d", &n) && n) {	
		solve();
	}
	return 0;
}

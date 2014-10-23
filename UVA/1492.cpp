#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 5e4 + 5;
typedef long long ll;
#define lson(x) (x<<1)
#define rson(x) ((x<<1) | 1)

int x[2][maxn], y[2][maxn];

struct Node {

	int l, r, add, s;
	void set (int l, int r, int add, int s) {

		this->l = l;
		this->r = r;
		this->add = add;
		this->s = s;
	}
}node[8 * maxn];

struct Line {

	int x, y1, y2, flag;
	Line (int x, int y1, int y2, int flag) {

		this->x = x;
		this->y1 = y1;
		this->y2 = y2;
		this->flag = flag;
	}

	bool operator < (const Line& a) const {
		return x < a.x;
	}
};

vector<int> pos;
vector<Line> L;
int W, H, N, M;	

void pushup (int u) {

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
	build (lson(u), l, m);
	build (rson(u), m + 1, r);
	pushup(u);
}

void update (int u, int l, int r, int v) {

	if (node[u].l >= l && node[u].r <= r) {

		node[u].add += v;
		pushup(u);
		return ;
	}

	int m = (node[u].l + node[u].r)>>1;
	if (l <= m)
		update (lson(u), l, r, v);
	if (r > m)
		update (rson(u), l, r, v);
	pushup(u);
}

void init () {

	for (int i = 0; i < N; i++) 
		scanf ("%d%d%d%d", &x[0][i], &y[0][i], &x[1][i], &y[1][i]);		
}

ll solve (int w, int h, int x[2][maxn], int y[2][maxn]) {

	L.clear();
	pos.clear();
	int tmp;

	for (int i = 0; i < N; i++) {

		tmp = max(y[0][i] - M + 1, 1);	
		L.push_back(Line(x[0][i], tmp, y[1][i] + 1, 1));	
		L.push_back(Line(x[1][i] + 1, tmp, y[1][i] + 1, -1));
		pos.push_back(tmp);
		pos.push_back(y[1][i] + 1);
	}

	tmp = max(1, h - M + 2);
	L.push_back(Line(1, tmp, h + 1, 1));
	L.push_back(Line(w + 1, tmp, h + 1, -1));
	pos.push_back(tmp);
	pos.push_back(h + 1);
	
	sort (L.begin(), L.end());
	sort (pos.begin(), pos.end());
	pos.erase (unique(pos.begin(), pos.end()), pos.end());

	build(1, 0, (int)pos.size() - 1);

	ll ans = 0;
	int l, r;
	for (int i = 0; i < L.size() - 1; i++)  {

		l = lower_bound(pos.begin(), pos.end(), L[i].y1) - pos.begin();
		r = lower_bound(pos.begin(), pos.end(), L[i].y2) - pos.begin();
		update(1, l, r - 1, L[i].flag);
//		printf ("%d %d\n", node[1].s, L[i + 1].x - L[i].x);
		ans += (ll)node[1].s * (L[i + 1].x - L[i].x);
	}
	
	return ans;
}

int main () {

	ll ans;
	while (scanf ("%d%d%d%d", &W, &H, &N, &M) != EOF) {

		init();

		if (M == 1) {
			ans = 0;
			for (int i = 0; i < N; i++)
				ans += (ll) (x[1][i] + 1 - x[0][i]) * (y[1][i] + 1- y[0][i]);	
			ans = (ll)W * H - ans;
		} else 
			ans = 2 * (ll)W * H - solve(H, W, y, x) - solve(W, H, x, y);
		printf ("%lld\n", ans);
	}
	return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define lson(x) (x<<1)
#define rson(x) ((x<<1) | 1)

const int maxn = 30005;

int lc[4 * maxn], rc[4 * maxn], s[4 * maxn], add[4 * maxn];
int pos[maxn];

void pushup (int u) {

	if (add[u]) {
		s[u] = pos[rc[u] + 1] - pos[lc[u]];
	} else if (rc[u] == lc[u])
		s[u] = 0;
	else
		s[u] = s[lson(u)] + s[rson(u)];
}

void build (int u, int l, int r) {

	lc[u] = l;
	rc[u] = r;
	s[u] = add[u] = 0;

	if (l == r) 
		return ;

	int m = (l + r) / 2;
	build (lson(u), l, m);
	build (rson(u), m + 1, r);
	pushup(u);
}

void modify (int u, int l, int r, int a) {

	if (lc[u] >= l && rc[u] <= r) {
		add[u] += a;
		pushup(u);
		return;
	}

	int m = (lc[u] + rc[u]) / 2;
	if (l <= m)
		modify(lson(u), l, r, a);
	if (r > m)
		modify(rson(u), l, r, a);
	pushup(u);
}

int query (int u, int l, int r) {

	if (lc[u] >= l && rc[u] <= r)
		return s[u];

	int m = (lc[u] + rc[u]) / 2;
	int ret = 0;
	if (l <= m)
		ret += query(lson(u), l, r);
	if (r > m)
		ret += query(rson(u), l, r);
	return ret;
}

int main () {
	
	return 0;
}


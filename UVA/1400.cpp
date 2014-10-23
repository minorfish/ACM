#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 5e5 + 5;

#define lson(x) ((x)<<1)
#define rson(x) (((x)<<1) + 1)

ll A[N], S[N];
struct Segment {

	ll v;
	int l, r;

	Segment(int l = 0, int r = 0, ll v = 0) {

		this->l = l;
		this->r = r;
		this->v = v;
	}

	Segment operator + (const Segment& a) const{

		Segment ans;
		ans.l = min (l, a.l);
		ans.r = max (r, a.r);
		ans.v = v + a.v;
		return ans;
	}

	bool operator < (const Segment &a) const {

		if (v == a.v) {

			if (l == a.l)
				return r > a.r;
			return l > a.l;
		}
		return v < a.v;
	}
};

struct Node {

	int l, r;
	Segment max_sub, max_prefix, max_suffix; 

	void set (int l, int r, Segment max_sub, Segment max_prefix, Segment max_suffix) {

			this->l = l;
			this->r = r;
			this->max_sub = max_sub;
			this->max_prefix = max_prefix;
			this->max_suffix = max_suffix;
	}

}node[4 * N];

Node Seg_merge(Node a, Node b) {

	Node ret;
	ll suml = S[a.r] - S[a.l - 1];
	ll sumr = S[b.r] - S[b.l - 1];

	ret.l = a.l;
	ret.r = b.r;
	
	ret.max_sub = max(a.max_suffix + b.max_prefix, max(a.max_sub, b.max_sub));
	ret.max_prefix = max (a.max_prefix, Segment(a.l, a.r, suml) + b.max_prefix);
	ret.max_suffix = max (b.max_suffix, a.max_suffix + Segment(b.l, b.r, sumr));

	return ret;
}

void build (int u, int l, int r) {

	if (l == r) { 	
		Segment max_sub(l, r, A[l]);
		Segment max_prefix(l, r, A[l]);
		Segment max_suffix(l, r, A[l]);
		node[u].set(l, r, max_sub, max_prefix, max_suffix);

	} else {
		int m = (l + r) / 2;			
		build(lson(u), l, m);
		build(rson(u), m + 1, r);
		node[u] = Seg_merge(node[lson(u)], node[rson(u)]);

	}		
}

Node Query (int u, int ql, int qr) {

	if (ql <= node[u].l && qr >= node[u].r)
		return node[u];
	
	int m = (node[u].l + node[u].r) / 2;

	if (ql > m)
		return Query (rson(u), ql, qr);
	else if (qr <= m)
		return Query (lson(u), ql, qr);
	else
		return Seg_merge(Query(lson(u), ql, qr), Query(rson(u), ql, qr));
}

int n, m;
int main () {

	int cas = 0;
	int l, r;
	Node ans;

	while (scanf ("%d%d", &n, &m) != EOF) {

		S[0] = 0;
		for (int i = 1; i <= n; i++) {
			
			scanf ("%lld", &A[i]);
			S[i] = S[i - 1] + A[i];
		}

		printf ("Case %d:\n", ++cas);
		build(1, 1, n);

		for (int i = 0; i < m; i++) {

			scanf ("%d%d", &l, &r);
			ans = Query(1, l, r);
			printf ("%d %d\n", ans.max_sub.l, ans.max_sub.r);
		}
	}
	return 0;
}

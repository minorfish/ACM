#include <cstdio>
#include <cstring>

const int N = 8e5 + 5;

int v[N];
int n;

int Query (int o, int l, int r, int ql, int qr) {

	int	m = l + (r - l) / 2;

	if (ql == l && r == qr)
		return v[o]; 

	if (qr <= m)
		return Query(2 * o, l, m, ql, qr);
	else if (ql > m)
		return Query(2 * o + 1, m + 1, r, ql, qr);
	else 
		return Query(2 * o, l, m, ql, m) + Query(2 * o + 1, m + 1, r, m + 1, qr);
}

void Update (int o, int l, int r, int p, int val) {

	int m = l + (r - l) / 2;

	if (l == r) 
		v[o] = val;
	else {

		if (p <= m)
			Update (2 * o, l, m, p, val);
		else
			Update (2 * o + 1, m + 1, r, p, val);

		v[o] = v[2 * o] + v[2 * o + 1];
	}
}

void solve () {

	char str[10];
	int x, y, r;
	while (scanf ("%s", str) && str[0] != 'E') {

		if (str[0] == 'M') {

			scanf ("%d%d", &x, &y);
			printf ("%d\n", Query (1, 1, n, x, y));
		} else {

			scanf ("%d%d", &x, &r);
			Update (1, 1, n, x, r);	
		}
	}
}

int main () {

	int cas = 0;
	int num;
	while (scanf ("%d", &n) && n) {

		if (cas)
			printf ("\n");
		printf ("Case %d:\n", ++cas);

		memset (v, 0, sizeof (v));
		for (int i = 1; i <= n; i++) {

			scanf ("%d", &num);
			Update (1, 1, n, i, num);
		}

		solve();			
	}
	return 0;
}

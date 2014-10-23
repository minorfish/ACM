#include <cstdio>
#include <cstring>

const int maxn = 2e5 + 5;

int lowbit (int x) { return x&-x; }

int n;
int A[maxn], C[maxn];

void Add (int x, int d) {

	while (x <= n) {
		
		C[x] += d;
		x += lowbit(x);
	}
}

int Sum (int x) {

	int ret = 0;
	while (x > 0) {
		
		ret += C[x];
		x -= lowbit(x);
	}
	return ret;
}

void solve () {

	char str[10];
	int x, r, y;
	while (scanf ("%s", str) && str[0] != 'E') {

		if (str[0] == 'M') {

			scanf ("%d%d", &x, &y);
			printf ("%d\n", Sum (y) - Sum (x - 1));
		} else {

			scanf ("%d%d", &x, &r);
			Add(x, r - A[x]);
			A[x] = r;
		}
	}
}

int main () {

	int cas = 0;
	while (scanf ("%d", &n) && n) {

		if (cas)
			printf ("\n");
		memset (C, 0, sizeof (C));
		for (int i = 1; i <= n; i++) {
			scanf ("%d", &A[i]);
			Add(i, A[i]);
		}
		printf ("Case %d:\n", ++cas);
		solve();
	}
	return 0;
}

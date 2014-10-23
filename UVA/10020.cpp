#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

const int N = 100005;
int m, n;
int visit[N];

struct segments {

	int l, r;
}s[N];

int cmp (const segments& a, const segments &b) { return a.l < b.l; }

int Max (const int a, const int b) {return a > b ? a: b;}

int solve () {

	memset (visit, 0, sizeof (visit));
	if (s[0].l > 0)
		return 0;
	int st = 0;
	int ll = -1;
	int t = -1;
	for (int i = 0; i < n; i++) {

		if (s[i].l <= st) {

			if (ll < s[i].r) {

				visit[i] = 1;
				if (t >= 0)
					visit[t] = 0;
				t = i;
				ll = Max (ll, s[i].r);
			}
		} else {

			if (st == ll)
				return 0;
			st = ll;
			i--;
			t = -1;
		}
		if (ll >= m)
			break;
	}
	if (ll < m)
		return 0;
	int count = 0;
	for (int i = 0; i < n; i++)
		if (visit[i])
			count++;
	return count;
}

int main () {

	int t;
	int l, r;
	scanf ("%d", &t);
	while (t--) {

		scanf ("%d", &m);
		n = 0;
		while (scanf ("%d%d", &l, &r), l || r) {

			if (r <= 0 || l >= m)
				continue;
			s[n].l = l;
			s[n].r = r;
			n++;
		}

		sort (s, s + n, cmp);
		int count = solve();
		printf ("%d\n", count);
		if (count) {
			for (int i = 0; i < n; i++)
				if (visit[i])
					printf ("%d %d\n", s[i].l, s[i].r);
		}
		if (t)
			printf ("\n");
	}
	return 0;
}

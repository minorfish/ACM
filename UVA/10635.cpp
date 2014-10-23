#include <cstdio>
#include <cstring>

const int N = 62505;

int dp[N];
int v[N];
int vis[N];
int LIS[N];
int p1;

int Max (const int a, const int b) { return a > b ? a: b; }

int bsearch (int s) {

	int l = 0;
	int r = p1;
	int mid;
	while (l < r) {

		mid = l + (r - l) / 2;
		if (s == LIS[mid])
			return mid;
		else if (s > LIS[mid])
			l = mid + 1;
		else
			r = mid;
	}
	return l;
}

int main () {

	int n, p, q, t;
	scanf ("%d", &t);
	for (int cas = 1; cas <= t; cas++) {

		scanf ("%d%d%d", &n, &p, &q);
		memset (vis, -1, sizeof (vis));

		for (int i = 0; i <= p; i++) {
			scanf ("%d", &v[i]);
			vis[v[i]] = i;
		}

		p1 = -1;
		int k;
		int ans = 0;
		for (int i = 0; i <= q; i++) {
				
			scanf ("%d", &v[i]);
			v[i] = vis[v[i]];
			if (v[i] == -1)
				continue;
			if (p1 == -1) {
				dp[i] = 1;
				LIS[++p1] = v[i];
			} else {

				if (v[i] > LIS[p1]) {

					LIS[++p1] = v[i];
					dp[i] = p1 + 1;
				} else if (v[i] < LIS[p1]) {

					k = bsearch (v[i]);
					dp[i] = k + 1;
					LIS[k] = v[i];
				} else
					dp[i] = p1 + 1;
			}
			 ans = Max (ans, dp[i]);
		}
		printf ("Case %d: %d\n", cas, ans);
	}
	return 0;
}

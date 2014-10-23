#include <cstdio>
#include <cstring>

const int maxn = 1e8 + 5;
const int N = 105;
const int M = 4505;

int dp[maxn];
int v[N][2];
int vis[M];
int l, n;

void init () {

	memset (dp, 0, sizeof (dp));
	memset (vis, 0, sizeof (vis));
	for (int i = 0; i < n; i++)
		for (int j = v[i][0]; j <= v[i][1] && j <= l; j++)
			if (!vis[j])
				vis[j] = 1;
	dp[0] = 1;
}

int main () {

	int t;
	int maxc, minc;
	scanf ("%d", &t);
	while (t--) {

		maxc = -1;
		minc = M;
		scanf ("%d%d", &l, &n);
		l *= 1000;
		int k = -1;
		for (int i = 0; i < n; i++) {
			scanf ("%d%d", &v[i][0], &v[i][1]);	
			if (k < v[i][0] * v[i][0] / (v[i][1] - v[i][0]))
				k = v[i][0] * v[i][0] / (v[i][1] - v[i][0]);
			if (maxc < v[i][1])
				maxc = v[i][1];
			if (minc > v[i][0])
				minc = v[i][0];
		}

		if (l >= k) {

			printf ("0\n");
		} else {

			init ();
			if (l <= maxc && vis[l]) {

				printf ("0\n");
			} else {

				for (int i = minc; i <= maxc; i++)
					for (int j = i; j <= l; j++) {

						if (vis[i] && dp[j - i])
							dp[j] = 1;
					}

				int i;
				for (i = l; i >= 0; i--)
					if (dp[i])
						break;

				printf ("%d\n", l - i);
			}
		}
		if (t)
			printf ("\n");
	}
	return 0;
}

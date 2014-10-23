#include <cstdio>
#include <cstring>

typedef long long ll;

const int maxn = 1005;
const int N = 55;
const int INF = 0x3f3f3f3f;

ll dp[maxn][maxn];
int v[N];
int l, n;

void init () {

	v[n + 1] = l;
	v[0] = 0;
	for (int i = 0; i <= n; i++) 
		dp[v[i]][v[i + 1]] = 0;
}

ll Min (const ll a, const ll b) { return a < b? a: b; }

int main () {

	while (scanf ("%d", &l), l) {

		scanf ("%d", &n);

		for (int i = 1; i <= n; i++)
			scanf ("%d", &v[i]);

		init ();
		ll temp;
		for (int i = 2; i <= n + 1; i++)
			for (int j = 0; j + i <= n + 1; j++) {
				
				temp = INF;
				for (int k = 1; k < i; k++)
					temp = Min (temp, dp[v[j]][v[j + k]] + dp[v[j + k]][v[j + i]]);
				dp[v[j]][v[j + i]] = temp + v[j + i] - v[j];
			}

		printf ("The minimum cutting is %lld.\n", dp[0][l]);
	}
	return 0;
}

#include <cstdio>
#include <cstring>

typedef long long ll;
const int N = 105;
const ll INF = 0x3f3f3f3f;

ll dp[N][N], sum[N];
int v[N];
int n;

void init () {

	memset (sum , 0, sizeof (sum));
	for (int i = n; i >= 1; i--) {

		if (i == n)
			sum[i] = v[i];
		else
			sum[i] = sum[i + 1] + v[i];
	//	printf ("%lld\n", sum[i]);
		dp[i][i] = v[i]; 
	}
}

ll Min (const ll a, const ll b) { return a < b? a: b; }

int main () {

	while (scanf ("%d", &n) && n) {

		for (int i = 1; i <= n; i++)
			scanf ("%d", &v[i]);
		init ();

		ll mm;
		for (int len = 1; len < n; len++)
			for (int i = 1; i + len <= n; i++) {
		
				mm = INF;
//				printf ("%lld\n", mm);
				for (int k = 1; k <= len; k++)
					mm = Min (mm, Min (dp[i + k][i + len], dp[i][i + len - k]));

				dp[i][i + len] = sum[i] - sum[i + len + 1] - Min (0, mm);  
			}

//		printf ("%lld\n", dp[1][n]);
		printf ("%lld\n", 2 * dp[1][n] - sum[1]);

	}
	return 0;
}

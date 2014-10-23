#include <cstdio>
#include <cstring>
#include <cmath>

const int N = 21;
const int maxn = 10000;
typedef long long ll;
int value[N];
ll dp[maxn];

void init () {
		
	for (int i = 0; i < N; i++) 
		value[i] = pow (i + 1, 3);
	
	memset (dp, 0, sizeof (dp));
	dp[0] = 1;
	for (int i = 0; i < N; i++) {

		for (int j = 1; j < maxn; j++) {

			if (j >= value[i])
				dp[j] += dp[j - value[i]];
		}
	}
}

int main () {

	init ();
	int n;
	while (scanf ("%d", &n) != EOF) {

		printf ("%lld\n", dp[n]);
	}
	return 0;
}

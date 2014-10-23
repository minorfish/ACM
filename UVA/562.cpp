#include <cstdio>
#include <cstring>

const int N = 105;
const int maxn = N * 500;

int v[N];
bool dp[maxn];
int n, sum;

void init () {

	memset (dp, false, sizeof (dp));
	dp[0] = true;

	for (int i = 0; i < n; i++)
		for (int j = sum; j >= v[i]; j--) {
				
			if (dp[j - v[i]])
				dp[j] = true;
		//	dp[j] = dp[j - v[i]];
		}
}

int main () {

	int t;
	scanf ("%d", &t);
	while (t--) {

		scanf ("%d", &n);
		sum = 0;
		for (int i = 0; i < n; i++) {

			scanf ("%d", &v[i]);
			sum += v[i];
		}
		
		init ();

		int i;
		for (i = sum / 2; i >= 0; i--) 
			if (dp[i])
				break;

		printf ("%d\n", sum - 2 * i);
				
	}
	return 0;
}


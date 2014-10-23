#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 10000005;
const int M = 10;

int v[M];
int dp[N];

int main () {

	int n, m;
	while (scanf ("%d%d", &n, &m) != EOF ) {

		for (int i = 0; i < m; i++)
			scanf ("%d", &v[i]);

		sort (v, v + m);
		memset (dp, 0, sizeof (dp));

		for (int i = 1; i <= n; i++)
			for (int j = 0; j < m; j++) {

				if (i >= v[j] && dp[i - v[j]] == 0)
					dp[i] = 1;
			}

	/*	for (int i = 0; i < m; i++)
			for (int j = v[i]; j <= n; j++)
				if (dp[j - v[i]] == 0)
					dp[j] = 1;*/
	
		printf ("%s wins\n", dp[n] ? "Stan": "Ollie");
	}
	return 0;
}

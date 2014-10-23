#include <cstdio>
#include <cstring>

const int maxn = 3e5;
const int N = 55;

int dp[maxn];
int v[N];

int main () {

	int n;
	int val, num;
	while (scanf ("%d", &n) != EOF && n) {

		memset (v, 0, sizeof (v));
		for (int i = 0; i < n; i++) {
			scanf ("%d%d", &val, &num);
			v[val] += num;
		}
		
		for (int i = 1; i <= N - 5; i++) {

			for (int j = 1; j <= v[i]; j++) {

						
			}
		}
	}
	return 0;
}

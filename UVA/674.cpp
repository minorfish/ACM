#include <cstdio>
#include <cstring>

const int N = 5;
const int maxn = 8000;

typedef long long ll;

int n;
int v[N] = {1, 5, 10, 25, 50};
//ll dp[maxn][N];
ll d[maxn];

/*void init () {
	
	memset (dp, -1, sizeof (dp));//have not been search
	for (int i = 0; i < N; i++) 
		dp[0][i] = 1;
}*/

/*ll DP (int x, int k) {

	ll& ans = dp[x][k];
	if (ans != -1)
		return ans;
	ans = 0;
	for (int i = k; i < N && x >= v[i]; i++)		
			ans += DP(x - v[i], i); 
	return ans;
}*/

int main () {
	
//	init();
	memset (d, 0, sizeof (d));
	d[0] = 1;

	for (int i = 0; i < N; i++)
		for (int j = v[i]; j <= maxn; j++)
			d[j] += d[j - v[i]]; 

	while (scanf ("%d", &n) != EOF) {
		
		//printf ("%lld\n", DP(n, 0));
		printf ("%lld\n", d[n]);
	}
	return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int find (int n, int k) {

	if (n < k)
		return 0;
	int mul = n / k;
	int mod = n % k;
	return (mul * n + mod * mul) * k;
}

int solve (int n, int k) {

	int tmp1 = find(n, k), tmp2 = 0;

	if (n > k && n % k) 
		tmp2 = solve(n - 2 * (n % k), k) + 4 * (n / k) * (n % k) * k;
	return max(tmp1, tmp2);
}

int main () {

	int T, N, K;
	scanf ("%d", &T);
	while (T--) {
		
		scanf ("%d%d", &N, &K);
		printf ("%d\n", solve(N, K));	
	}
	return 0;
}

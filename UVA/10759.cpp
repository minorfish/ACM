#include <cstdio>
#include <cstring>

typedef long long ll;
const int maxn = 25;
const int maxm = 155;

int N, X;
ll f[maxn][maxm], t[maxn];

void init () {

	t[0] = 1LL;
	for (int i = 1; i < maxn; i++)
		t[i] = t[i - 1] * 6;
}

ll gcd (ll a, ll b) {
	return b == 0? a: gcd(b, a%b);
}

ll dp (int n, int x) {

	ll& ans = f[n][x];
	if (ans != -1)
		return ans;
	if (n == N) {
		if (x < X)
			return ans = 1;
		return ans = 0;
	}

	ans = 0;
	for (int i = 1; i <= 6; i++)
		if (x + i < X)
			ans += dp(n + 1, x + i);
		else
			break;
	return ans;
}

int main () {

	init();
	while (scanf ("%d%d", &N, &X) && (N||X)) {

		memset(f, -1, sizeof (f));	
		ll a = t[N] - dp(0, 0);

		if (a == 0) {
			printf ("0\n");
			continue;
		}

		if (a == t[N]) {
			printf ("1\n");
			continue;
		}

		ll tmp = gcd(a, t[N]);
		printf ("%lld/%lld\n", a/tmp, t[N]/tmp);
		
	}
}

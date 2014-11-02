#include <cstdio>
#include <cstring>
#include <cmath>

const int maxn = 65000 + 5;
typedef long long ll;

int notprime[maxn];

void init () {

	for (int i = 2; i < maxn; i++) 
		for (int j = 2 * i; j < maxn; j += i) 
			notprime[j] = 1;
}

ll powmod(ll x, ll n, ll mod) {

	if (n == 1)
		return x;

	ll ans = powmod(x, n / 2, mod);
	ans = (ans * ans) % mod;
	if (n % 2 == 1)
		ans *= x;
	return ans % mod;	
}

bool is_carmichael(int n) {

	for (int i = 2; i < n; i++) {
		if (powmod(i, n, n) != i)
		return false;
	}
	return true;
}

int main () {


	init();
	int n;
	while (scanf ("%d", &n) && n) {
		
		if (notprime[n] == 0)
			printf ("%d is normal.\n", n);
		else {
			bool flag = is_carmichael(n);
			if (flag)
				printf ("The number %d is a Carmichael number.\n", n);
			else
				printf ("%d is normal.\n", n);
		}
	}
	return 0;
}

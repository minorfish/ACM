#include <cstdio>
#include <cstring>

typedef long long ll;

int main () {

	ll n;
	while (scanf ("%lld", &n) && n >= 0) {

		printf ("%lld\n", (1 + n) * n / 2 + 1);		
	}

	return 0;
}

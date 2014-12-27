#include <cstdio>
#include <cstring>
#include <cmath>

typedef long long ll;

ll gcd (ll a, ll b) {
	
	return (b == 0) ? a : gcd(b, a%b);
}

int main () {

	ll p, q, ans, P, Q;
	bool flag;
	while (scanf ("%lld%lld", &P, &Q) != EOF && (P || Q)) {

		flag = 0;
		if (P == 0) {
			printf ("0 2\n");
			continue;
		}
		
		if (P == Q) {
			printf("2 0\n");
			continue;
		}
		ans = gcd(P, Q);
		
		P /= ans;
		Q /= ans;
		ll m, total;
		int l, r; 
		for (total = 3; total <= 50000; total++) {

			ll N = total * (total - 1) * P, M;
			if (N % Q != 0)
				continue;
			
			l = 1; r = total;
			N /= Q;
			while (l < r) {
				m = (l + r) / 2;
				M = m * (m - 1);
				if (M < N)
					l = m + 1;
				else if (M > N)
					r = m;
				else {
					flag = 1;
					break;
				}
			}
			if (flag)
				break;
		}
	
		if (flag)
			printf ("%lld %lld\n", m, total - m);
		else
			printf ("impossible\n");
	}
	return 0;
}

#include <cstdio>
#include <cstring>
#include <cmath>

typedef long long ll;
int n;

ll solve () {

	int cnt, flag, m;
	ll ans = 0LL;
	cnt = flag = 0;
	m = sqrt(n);

	for (int i = 2; i <= m; i++) {

		if (n % i == 0) {
			cnt = 1;
			flag++;
			while (n % i == 0) {
				cnt *= i;
				n /= i;
			}
			ans += cnt;
		}
		if (n == 1)
			break;
	}

	if (n != 1 || (flag == 0)) {
		ans += n;
		flag++;
	}

	if (flag == 1)
		ans++;
	return ans;
}

int main () {

	int cas = 0;
	while (scanf ("%d", &n) && n) {
		printf ("Case %d: %lld\n", ++cas, solve());
	}
	return 0;
}

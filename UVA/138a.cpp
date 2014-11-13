#include <cstdio>
#include <cstring>
#include <cmath>

typedef long long ll;
const int maxn = 10;

int main () {

	ll a = 1;
	double b;
	int cnt = 0;

	while (cnt < maxn) {

		a++;
		b = (sqrt(a * a * 8 + 1.0) - 1) / 2;
		if (b == floor(b)) {
			printf ("%10lld%10.0lf\n", a, b);
			cnt++;
		}
	}
	return 0;
}

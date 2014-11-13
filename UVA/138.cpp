#include <cstdio>
#include <cstring>
#include <cmath>

typedef long long ll;
const int maxn = 10;
int A[maxn] = {6, 35, 204, 1189, 6930, 40391, 235416, 1372105, 7997214, 46611179};
int B[maxn] = {8, 49, 288, 1681, 9800, 57121, 332928, 1940449, 11309768, 65918161};

/*
void solve () {

	int cnt = 0;
	ll b, l, r, m;
	for (ll i = 2; cnt < maxn; i++) {

		b = i * i + i;
		if (b % 2 != 0)
			continue;

		b /= 2;
		l = 1;
		r = sqrt(b);

		while (l <= r) {

			m = (l + r) / 2;
			if (m * m < b)
				l = m + 1;
			else if (m * m > b)
				r = m;
			else {
				printf ("%10lld%10lld\n", m, i);
				cnt++;
				break;
			}
		}	
	}
}*/

int main () {

	for (int i = 0; i < maxn; i++)
		printf ("%10d%10d\n", A[i], B[i]);
	
//	solve();
	return 0;
}

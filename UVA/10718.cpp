#include <stdio.h>
#include <string.h>

const int N = 32;
typedef long long ll;
ll t[N];
bool w1[N], w2[N];

void init () {
	
	t[0] = 1;
	for (int i = 0; i < N - 1; i++)
		t[i + 1] = t[i] * 2;	
}

void cut (ll n, bool w[]) {

	for (int i = N - 1; i >= 0; i--) {
		if (n >= t[i]) {

			w[i] = 1;
			n -= t[i];
		}
	}
}

ll solve (ll l, ll r) {

	ll ans = l;
	for (int i = N - 1; i >= 0; i--) {

		if (!w1[i] && !w2[i]) {

			if (ans + t[i] <= r)
				ans += t[i];
			else {
				
				ll temp = 0;
				for (int j = i - 1; j >= 0; j--)
					if (w2[j])
						temp += t[j];
				if (ans + t[i] - temp >= l && ans + t[i] - temp <= r) {
					
					ans = ans + t[i] - temp;	
					for (int j = i - 1; j >= 0; j--)
						w2[j] = 0;
				}
			}
		}

		if (w1[i] && w2[i]) {

			if (ans - t[i] >= l)
				ans -= t[i];
			else {
			
				ll temp = 0;
				for (int j = i - 1; j >= 0; j--) 
					if (!w2[j])
						temp += t[j];
				if (ans - t[i] + temp >= l && ans - t[i] + temp <= r) {

					ans = ans - t[i] + temp;
					for (int j = i - 1; j >= 0; j--)
						w2[j] = 1;
				}
			}
		}
	}
	return ans;
}

int main () {
	
	ll n, l, r;
	init();
	while (scanf ("%lld%lld%lld", &n, &l, &r) != EOF) {

			memset(w1, 0, sizeof(w1));
			memset(w2, 0, sizeof(w2));
			cut(n, w1);
			cut(l, w2);
			printf ("%lld\n", solve(l, r));
	}
	return 0;
}

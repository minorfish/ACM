#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;
const int maxn = 50;
const ll INF = 0x3f3f3f3f;

int k, t;
ll num[maxn], H[maxn];
ll L[maxn], R[maxn];

ll gcd (ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}

void init () {

	for (int i = 0; i < k; i++) 
		scanf ("%lld", &num[i]);
	for (int i = 0; i < t; i++)
		scanf ("%lld", &H[i]);

	for (int i = 0; i < t; i++) {
		L[i] = 0;
		R[i] = INF;
	}
}

void solve (ll a) {

	ll tmp;
	for (int i = 0; i < t; i++) {
	
		tmp = a;
		while (1) {
			
			if (tmp == H[i]) {
				L[i] = max(L[i], tmp);
				R[i] = min(R[i], tmp);
				break;
			} else if (tmp < H[i]) {

				L[i] = max(L[i], tmp);
			} else {

				L[i] = max(L[i], tmp - a);
				R[i] = min(R[i], tmp); 
				break;
			}
			tmp += a;
		}
	}
}

int main () {

	while (scanf ("%d%d", &k, &t) && (k || t)) {	

		init();		
		ll tmp1, tmp2, tmp;

		for (int i = 0; i < k; i++) 
			for (int j = i + 1; j < k; j++) {

				tmp1 = num[i] / gcd(num[i], num[j]) * num[j];
				for (int m = j + 1; m < k; m++)
					for (int n = m + 1; n < k; n++) {
						
						tmp2 = num[m] / gcd(num[m], num[n]) * num[n];
						tmp = tmp1 / gcd(tmp1, tmp2) * tmp2;
						solve(tmp);
					}	
		}

		for (int i = 0; i < t; i++) 
			printf ("%lld %lld\n", L[i], R[i]);	
	}
	return 0;
}

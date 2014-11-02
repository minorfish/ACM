#include <cstdio>
#include <cstring>

typedef long long ll;

const int maxn = 1e6;
const ll mod = 1e9 + 7;

ll arr[maxn];

int main () {

	int T, n;
	scanf ("%d", &T);
	while (T--) {

		scanf ("%d", &n);	
		for (int i = 1; i <= n; i++)
			scanf ("%I64d", &arr[i]);

		ll ans = 0;
		for (int i = 1; i <= n; i++) 
			ans = (ans + (arr[i] * i % mod) * (n - i + 1) % mod) % mod;
		printf ("%I64d\n", ans);	
	}
	return 0;
}

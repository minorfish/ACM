#include <cstdio>
#include <cstring>

const int maxn = 1e5 + 5;
const int N = 2e4 + 5;

typedef long long ll;

int C[maxn];
int A[maxn];
ll c[N], d[N];

int lowbit(int x) { return x&-x; }

void Add (int x, int d) {

	while (x < maxn) {

		C[x] += d;
		x += lowbit(x);
	}
}

int Sum (int x) {

	int ret = 0;
	while (x > 0) {

		ret += C[x];
		x -= lowbit(x); 
	}
	return ret;
}

void init () {

	memset (C, 0, sizeof (C));
	//memset (A, 0, sizeof (A));
}

int main () {

	int T;
	int n;
	int num[N];
	scanf ("%d", &T);
	while (T--) {

		scanf ("%d", &n);	
		init();
		for (int i = 0; i < n; i++) {
			scanf ("%d", &num[i]);
			//A[num] = 1;
			Add(num[i], 1);
			c[i] = Sum (num[i]) - 1;	
		}

		init();
		for (int i = n - 1; i >= 0; i--) {

			Add(num[i], 1);
			d[i] = Sum (num[i]) - 1;
		}

		ll ans = 0;
		for (int i = 0; i < n; i++) { 
//			printf ("%lld %lld\n", c[i], d[i]);
			ans += c[i] * (n - i - 1 - d[i]) + (i - c[i]) * d[i];
		}
		printf ("%lld\n", ans);
	}
	return 0;
}

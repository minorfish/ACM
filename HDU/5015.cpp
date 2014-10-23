#include <cstdio>
#include <cstring>

typedef long long ll;

const int N = 15;
const ll MOD = 10000007;

ll A[N][N];
int B[N];
int n;
ll m;

struct Rec {

	ll v[N][N];

	Rec () { memset (v, 0, sizeof (v));}
	void init () {

		for (int i = 0; i < n + 2; i++)
			for (int j = 0; j < n + 2; j++)
				v[i][j] = A[i][j];
	}

	Rec operator * (const Rec &a) {

		Rec tmp;
		for (int i = 0; i < n + 2; i++)
			for (int j = 0; j < n + 2; j++) 
				for (int k = 0; k < n + 2; k++)
					tmp.v[i][j] = (tmp.v[i][j] + (v[i][k] * a.v[k][j]) % MOD) % MOD;
		return tmp;
	}
	
	Rec operator *= (const Rec &a) {
		
		return *this = *this * a;
	}
}num;

void init () {

	memset (A, 0, sizeof (A));
	for (int i = 0; i < n + 1; i++) {
		A[i][0] = 10LL;
		A[i][n + 1] = 1LL;
	}

	A[n + 1][n + 1] = 1LL;
	for (int i = 1; i < n + 1; i++) 
		for (int j = 1; j <= i; j++) 
			A[i][j] = 1LL;
	B[0] = 23;
}

Rec f(ll m) {

	if (m == 1)
		return num;
	Rec tmp;
	tmp = f(m / 2);
	tmp *= tmp;
	if (m % 2)
		tmp *= num; 
	return tmp;
}

int main () {


	while (scanf ("%d%lld", &n, &m) != EOF) {

		for (int i = 1; i <= n; i++)
			scanf ("%d", &B[i]);

		init();
		B[n + 1] = 3;
		num.init ();

		num = f(m);
		
/*		for (int i = 0; i <= n + 1; i++) {
			for (int j = 0; j <= n + 1; j++)
				printf ("%lld ", num.v[i][j]);
			printf ("\n");
		}*/

		ll ans = 0;
		for (int i = 0; i <= n + 1; i++) 
			ans = (ans + (num.v[n][i] * B[i]) % MOD) % MOD;
		printf ("%lld\n", ans);
	}
	return 0;
}

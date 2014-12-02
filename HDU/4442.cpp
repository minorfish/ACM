#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
const int MOD = 31536000;

struct Queue {

	ll ai, bi;
} q[maxn];

bool cmp (const Queue A, const Queue B) {

	if (A.ai * B.bi < A.bi * B.ai)
		return true;
	return false;
}

int main () {

	int n;	
	while (scanf ("%d", &n) && n) {

		for (int i = 0; i < n; i++)
			scanf ("%I64d%I64d", &q[i].ai, &q[i].bi);
		sort (q, q + n, cmp);

		ll ans = q[0].ai, t = q[0].ai;
		for (int i = 1; i < n; i++) {
			ans = (ans + q[i].ai + (t * q[i].bi) %MOD)%MOD;
			t = (t + q[i].ai + (t * q[i].bi) % MOD) % MOD;
		}

		printf ("%I64d\n", ans);
	}
	return 0;
}

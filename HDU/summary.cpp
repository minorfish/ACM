#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

typedef long long ll;
const int N = 105;
ll num[N];

set<ll> vis;
set<ll>::iterator it;
int main () {

	int n;
	while (scanf ("%d", &n) != EOF) {

		vis.clear();
		for (int i = 0; i < n; i++) {
			scanf ("%I64d", &num[i]);
		}
	
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (i == j)
					continue;
				vis.insert (num[i] + num[j]);
			}

		ll ans = 0;
		for (it = vis.begin(); it != vis.end(); it++)
			ans += *it;
		printf ("%I64d\n", ans);
	}
	return 0;
}

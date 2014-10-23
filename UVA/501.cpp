#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

const int maxn = 3e4 + 5;

vector<ll> v;
vector<ll>::iterator it;
int n, m;
ll num[maxn];
int op;

int main () {
	
	int T;
	scanf ("%d", &T);
	while (T--) {

		scanf ("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			scanf ("%lld", &num[i]);
		v.clear();
		int dex = 0;
		for (int i = 0; i < m; i++) {
			scanf ("%d", &op);
			while (dex < op) {
			
				it = lower_bound(v.begin(), v.end(), num[dex]);
				if (it != v.end())
					v.insert(it, num[dex++]);
				else
					v.push_back(num[dex++]);
			}
			printf ("%lld\n", v[i]);
		}

		if (T)
			printf ("\n");
	}
	return 0;
}

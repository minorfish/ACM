#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
const int maxn = 33;
typedef long long ll;

int n;
const ll base = -2LL;
ll L[maxn], R[maxn], t[maxn];
int ans[maxn];

void init() {

	t[0] = 1;
	for (int i = 1; i < maxn; i++)
		t[i] = t[i - 1] * base;

	L[0] = R[0] = 1;
	L[1] = -2, R[1] = -1;
	
	for (int i = 2; i < maxn; i++) {
		if (i % 2 == 0) {
			L[i] = R[i - 2] + 1; 
			R[i] = R[i - 2] + t[i];
		} else {
			R[i] = L[i - 2] - 1;
			L[i] = L[i - 2] + t[i];
		} 
	}
}

int main () {

	int T, flag;
	scanf ("%d", &T);
	init();

	for (int cas = 1; cas <= T; cas++) {

		scanf ("%d", &n);	

		printf ("Case #%d: ", cas);
		if (!n) {
			printf ("0\n");
			continue;
		}

		memset (ans, 0, sizeof(ans));
		flag = -1;
		for (int i = maxn - 1; i >= 0; i--) {

			if (L[i] <= n && n <= R[i]) {
				flag = max(flag, i);
				ans[i]++;
				n -= t[i]; 
			}
			if (!n)
				break;
		}
	
		for (int i = flag; i >= 0; i--)
			printf ("%d", ans[i]);
		printf ("\n");
	}
	return 0;
}

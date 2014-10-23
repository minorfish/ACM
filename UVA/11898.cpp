#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int M = 1e4;
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;

int arr[N];
int tmp[N];

int Min_value (int l, int r) {

	if (r - l + 1 > M)
		return 0;

	memset (tmp, 0, sizeof (tmp));
	for (int i = l; i <= r; i++) {
		if (tmp[arr[i]])
			return 0;
		tmp[arr[i]]++;
	}
	
	int mval = INF, pre = -INF;
	for (int i = 1; i <= M; i++) {
		
		if (tmp[i]) {

			mval = min (mval, i - pre);
			pre = i;
		}
	}
	return mval;
}

int main () {

	int T, n, q;
	int l, r;
	scanf ("%d", &T);

	while (T--) {

		scanf ("%d", &n);
		for (int i = 0; i < n; i++)
			scanf ("%d", &arr[i]);

		scanf ("%d", &q);
		while (q--) {
			
			scanf ("%d%d", &l, &r);
			printf ("%d\n", Min_value(l - 1, r - 1));
		}
	}
	return 0;
}

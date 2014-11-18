#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main () {

	int n, m, r, c, ans;
	while (scanf ("%d%d", &n, &m) && (n || m)) {
			
		r = min(n, m);
		c = max(n, m);

		if (r == 2) {
			int mod = c % 4;
			int mul = c / 4;
			ans = mul * 4 + (mod <= 2? (mod * 2) : 4); 
		} else if (r <= 1) {
			ans = r * c;
		} else {

			ans = (n * m + 1) / 2; 
		}
			
		printf ("%d knights may be placed on a %d row %d column board.\n", ans, n, m);
	}
	return 0;
}

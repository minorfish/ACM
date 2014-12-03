#include <cstdio>
#include <algorithm>

using namespace std;

int main () {
	
	int p, q, r, s;
	while (scanf ("%d%d%d%d", &p, &q, &r, &s) != EOF) {
		
		q = min (q, p - q);
		s = min (s, r - s);

		double ans = 1.0;
		for (int i = 1; i <= q || i <= s; i++) {
			if (i <= q)
				ans = ans * (p - i + 1) / i;  
			if (i <= s)
				ans = ans * i / (r - i + 1);
		}
		printf ("%.5lf\n", ans);
	}
	return 0;
}

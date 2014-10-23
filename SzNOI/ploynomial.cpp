#include <cstdio>
#include <cstring>
#include <cmath>

const double esp = 1e-9;

int main () {

	int T, n;
	scanf ("%d", &T);
	for (int cas = 1; cas <= T; cas++) {

		double ans = 0;
		double fnum;
		double l, r;

		scanf ("%lf%lf", &l, &r);
		scanf ("%d", &n);

		for (int i = 0; i < n; i++) {
			
			scanf ("%lf", &fnum);
			if (fabs(fnum) < esp)
				continue;
			ans += fnum / (i + 1) * (pow(r, i + 1) - pow(l, i + 1));
		}

		printf ("Case %d: %.8lf\n", cas, ans);
	}
	return 0;
}

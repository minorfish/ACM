#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 5610;

struct turtle {

	int w, s;		
}t[N];

int f[N * N];

int cmp (const turtle &a, const turtle &b) {

	if (a.s - a.w == b.s - b.w)
		return a.w < b.w;
	return (a.s - a.w) > (b.s - b.w);
}

int Min (const int a, const int b ) { return a < b ? a: b; }

int main () {

	int n = 0;
	while (scanf ("%d%d", &t[n].w, &t[n].s) != EOF) {

		n++;
	}

	sort(t, t + n, cmp);

	int max = t[0].s - t[0].w;
	int tmp;
	for (int i = 0; i < n; i++) {
		for (int j = t[i].w; j <= max; j++) {

			if (f[j]) {

				tmp = Min (j, t[i].s) - t[i].w; 
				if (f[tmp] < f[j] + 1)
					f[tmp] = f[j] + 1;
			}
		}
		tmp = t[i].s - t[i].w;
		if (!f[tmp])
			f[tmp] = 1;
	}

	int ans = 0;
	for (int i = 0; i <= max; i++)
		if (ans < f[i])
			ans = f[i];
	printf ("%d\n", ans);
	return 0;
}

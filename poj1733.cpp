#include <stdio.h>
#include <map>

using namespace std;

int n, m;
map<int, int> f, c;

void init (int x) {

	if (f.count(x))
		return ;
		f[x] = x;
		c[x] = 0;
}

int getfather (int x) {

	if (x != f[x]) {

		int t = f[x];
		f[x] = getfather (f[x]);
		c[x] = (c[x] + c[t]) % 2;
	}
	return f[x];
}

int main () {

	while (	scanf ("%d%d", &n, &m) != EOF ) {

		char str[10];
		int x, y, v, ans = m;
		for (int i = 0; i < m; i++) {

			scanf ("%d%d%s", &x, &y, str);
			if (ans != m)
				continue;
			init (x - 1);
			init (y);
			if (str[0] == 'o')
				v = 1;
			else
				v = 0;
			int p = getfather (x - 1);
			int q = getfather (y);
			if (p != q) {

				f[q] = p;
				c[q] = (v + c[x - 1] + c[y] + 2) % 2;
				//	printf("!=");
			} else if ((c[y] - c[x - 1] + 2) % 2 != v){

				ans = i;
				//printf ("=");
			}

			//	printf ("%d %d %d\n", p, q, v);
			//	printf ("%d %d\n",f[q], c[q]);
		}
		printf ("%d\n", ans);
		f.clear();
		c.clear();
	}
	return 0;
}

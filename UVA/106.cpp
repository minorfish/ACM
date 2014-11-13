#include <cstdio>
#include <cstring>
#include <cmath>

const int maxn = 1e6 + 5;

int vis[maxn];
int n;

int gcd(int a, int b) {

	return b == 0 ? a : gcd(b, a % b);
}

int solve () {

	int x, y, z;
	int m = sqrt(n);
	int count = 0;
	memset (vis, 0, sizeof (vis));

	for (int i = 1; i <= m; i++) {
		for (int j = i + 1; j <= m; j += 2) {
			x = j * j - i * i;
			y = 2 * i * j;
			z = j * j + i * i;
			if (x > n || y > n || z > n)
				continue;
			if (x * x + y * y == z * z && gcd(i, j) == 1) {

	//			printf ("%d %d %d\n", x, y, z);
				count++;
				for (int k = 1; k * z <= n; k++)
					vis[k * x] = vis[k * y] = vis[k * z] = 1;
			}
		}
	}

	return count;
}

int main () {

	while (scanf ("%d", &n) == 1) {

		int c = solve();
		int p = 0;
		for (int i = 1; i <= n; i++)
			if (!vis[i]) {
				p++;
//				printf ("%d\n", i);
			}
		printf ("%d %d\n", c, p);
	}
	return 0;
}

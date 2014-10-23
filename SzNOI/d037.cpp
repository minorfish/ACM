#include <cstdio>
#include <cstring>

int main () {

	int n, m;
	int y;
	while (scanf ("%d%d", &n, &m) != EOF) {

		y = (m - 2 * n) / 2;
		printf ("%d %d\n", n - y, y);
	}
	return 0;
}

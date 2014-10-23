#include <cstdio>
#include <cstring>

int a, b, c;

int main () {

	int T;
	scanf ("%d", &T);
	while (T--) {
		
		scanf ("%d%d%d", &a, &b, &c);
		int ans = 0;
		for (int i = 1; i <= c/a; i++) {

			if ((c - a * i) <= 0)
				break;
			if ((c - a * i) % b == 0)
				ans++;
		}
		printf ("%d\n", ans);
	}
	return 0;
}

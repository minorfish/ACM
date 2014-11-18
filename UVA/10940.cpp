#include <cstdio>
#include <cstring>

const int maxn = 5e5 + 5;
int f[maxn];

void init () {

	int tmp = 1;
	f[1] = 1;
	for (int i = 2; i <= maxn - 5; i++) {
	
		if(i > tmp * 2) {
			tmp *= 2;
			f[i] = 2 * (i - tmp);
		} else
			f[i] = 2 * (i - tmp);	
	}
}

int main () {

	init();
	int n;

	while (scanf ("%d", &n) && n) {

		printf ("%d\n", f[n]);
	}
	return 0;
}

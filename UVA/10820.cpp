#include <cstdio>
#include <cstring>

const int maxn = 5e4 + 5;
int phi[maxn];

void phi_table() {

	phi[1] = 1;
	for (int i = 2; i < maxn; i++) {

		if (phi[i])
			continue;
		for (int j = i; j < maxn; j += i) {
			if (!phi[j])
				phi[j] = j;
			phi[j] = phi[j] / i * (i - 1);
		}
	}
}

int main () {

	int n;
	phi_table();
	while (scanf ("%d", &n) && n) {
		int ans = 0;
		for (int i = 1; i <= n; i++)
			ans += phi[i];
		printf ("%d\n", 2 * ans - 1);
	}
}

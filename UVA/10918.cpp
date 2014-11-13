#include <cstdio>
#include <cstring>

const int maxn = 35;
typedef long long ll;
ll num[maxn];

void init() {

	num[0] = 1;
	num[2] = 3;

	for (int i = 4; i <= maxn - 5; i += 2) 
		num[i] = 4 * num[i - 2] - num[i - 4];
}

int main () {

	init();

	int n;
	while (scanf ("%d", &n) && n != -1) {
	
		printf ("%lld\n", num[n]);
	}
	return 0;
}

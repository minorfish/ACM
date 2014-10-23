#include <cstdio>
#include <cmath>

using namespace std;

int num, k;

int f(int d) {

	if (d == 1)
		return num % 1000;
	if (d == 0)
		return 1;
	int n = f(d / 2) % 1000;
	n = (n * n) % 1000;
	if (d % 2)
		n = (n * (num % 1000)) % 1000; 
	return n;
}

int main () {

	int T;
	scanf ("%d", &T);

	while (T--) {

		scanf ("%d%d", &num, &k);
		int tail = f(k);
		int head = (int)pow (10, 2 + fmod (k * log10(num * 1.0), 1.0));
		printf ("%d...%03d\n", head, tail);
	}
	return 0;
}

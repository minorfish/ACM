#include <cstdio>
#include <cstring>

int main () {

	int T, X, K;
	scanf ("%d", &T);
	while (T--)  {
	
		scanf ("%d%d", &X, &K);
		if (X < K) {
			printf ("%d %d\n", 0, X);
			continue;
		}

		if (X % K == 0) 
			printf ("0 %d\n", K);
		else {
			int q = X % (X / K);
			int p = X / (X / K) - q;
			printf ("%d %d\n", p, q);
		}
	}
	return 0;
}

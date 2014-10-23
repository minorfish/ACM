#include <stdio.h>
#include <stdlib.h>

const int N = 100005;
long long wines[N];

int main () {

	int n;
	while (scanf ("%d", &n), n) {
		
		for (int i = 0; i < n; i++) {

			scanf ("%lld", &wines[i]);
		}
		long long count = labs(wines[0]); 
		for (int i = 1; i < n; i++) {
			
			wines[i] += wines[i - 1];
			count += labs(wines[i]);	
		}
		printf ("%lld\n", count);
	}
	return 0;
}

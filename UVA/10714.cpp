#include <stdio.h>

const int N = 1000005;
int s[N];

int max (const int x, const int y) {
	
	return x > y ? x : y;
}
	
int min (const int x, const int y) {

	return x < y ? x: y;
}

int main () {
	
	int t;
	int l, n;
	scanf ("%d", &t);
	while (t--) {
		
		scanf ("%d%d", &l, &n);
		for (int i = 0; i < n; i++) 
			scanf ("%d", &s[i]);

		int minlen, maxlen;
		minlen = maxlen = -1;

		for (int i = 0; i < n; i++) {
			
			minlen = max (minlen, min (s[i], l - s[i]));
			maxlen = max (maxlen, max (s[i], l - s[i])); 
		}
		printf ("%d %d\n", minlen, maxlen); 
	}
	
	return 0;
}

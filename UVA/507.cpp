#include <stdio.h>
#include <string.h>

const int N = 20005;
int s, b, e;
int stop[N];

int solve () {
	
	int mm = stop[1];
	int sum = stop[1];
	int tems = 1;
	b = e = 1;

	if (sum < 0) {

		tems = 2;
		sum = 0;
	}

	for (int i = 2; i < s; i++) {

		sum += stop[i];
		if (sum < 0) {

			tems = i + 1;
			sum = 0;
		}
		else if (sum >= mm) {
				
			if ( (sum == mm && i - tems > e - b) || sum > mm) {
				
				b = tems;
				e = i;
				mm = sum;
			}	
		}
	}
	return mm;	
}

int main () {

	int t;
	scanf ("%d", &t);
	for (int i = 1; i <= t; i++) {

		scanf("%d", &s);
		for (int j = 1; j < s; j++)
			scanf ("%d", &stop[j]);
		
		int mm = solve();
		if (mm < 0)
			printf ("Route %d has no nice parts\n", i);
		else
			printf ("The nicest part of route %d is between stops %d and %d\n", i, b, e + 1);
	}
	return 0;
}

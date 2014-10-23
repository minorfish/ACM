#include <stdio.h>
#include <stdlib.h>

const int N = 505;
const int INF = 0x3f3f3f3f;
int r;
int relatives[N];

int Min (const int x, const int y) { return x < y ?x : y;}

int solve () {

	int mm = INF;
	int sum = 0;
	for (int i = 0; i < r; i++) {

		sum = 0;
		for (int j = 0; j < r; j++) {
			
			if (i == j)
				continue;
			sum += abs (relatives[i] - relatives[j]);		
			if (sum >= mm)
				break;
		}
		mm = Min (mm, sum);
	}
	return mm;
}

int main () {

	int t;
	scanf ("%d", &t);
	while (t--) {

		scanf ("%d", &r);
		for (int i = 0; i < r; i++) 
			scanf ("%d", &relatives[i]);

		printf ("%d\n", solve());
	}
	return 0;
}

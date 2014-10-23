#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;

const int N = 1005;
int s[N];
int n, q;

int min (const int a, const int b) {
	
	if (a == 0)
		return b;
	return abs(a - q) < abs (b - q)? a: b;
}

int search () {
	
	int l = 0;
	int r = n - 1;
	int sum = 0;
	while (l <= n - 1 && r >= 0 && l < r) {
		
		if (s[l] + s[r] < q) {

			sum = min (sum, s[l] + s[r]);
			l++;
		}
		else if (s[l] + s[r] > q) {
		
			sum = min (sum , s[l] + s[r]);
			r--;
		}
		else
			return s[l] + s[r]; 
	}	
	return sum;
}

int main () {
	
	int m;
	int t = 0;
	while (scanf ("%d", &n), n) {

		for (int i = 0; i < n; i++)
			scanf ("%d", &s[i]);
		sort (s, s + n);
		scanf ("%d", &m);
		printf ("Case %d:\n", ++t);
		for (int i = 0; i < m; i++) {

			scanf ("%d", &q);
			printf ("Closest sum to %d is %d.\n", q, search ());
		}
	}
	return 0;
}

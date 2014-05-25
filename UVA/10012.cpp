#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;

const int N = 10;
const double INF = 0x6ffffff;
double r[N], front[N], tail[N], ans;
int n;

void init () {

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf ("%lf", &r[i]);
	sort(r, r + n);
	ans = INF;
}

bool cmp (double x, double y) {
	
	return x - y < -1e-9;
}

double dis (int a, int b) {

	return 2 * sqrt (r[a] * r[b]);
}

double len (int a, int b) {
	
	return sqrt (pow (front[a] - front[b], 2) + pow (r[a] - r[b], 2));
}

void solve () {
	
	double sum = 0;
	memset(front, 0, sizeof(front));
	memset(tail, 0, sizeof(tail));
	front[0] = tail[0] = r[0];
	sum = 2 * r[0];
	int i, j;
	for (i = 1; i < n; i++) {
		
		front[i] = front[i - 1] + dis(i, i - 1);
		tail[i] = r[i];
		if (cmp (front[i], r[i]))
				front[i] = r[i];
		for (j = 0; j < i - 1; j++) 
			if ( cmp (len (j, i) , r[j] + r[i]))
				front[i] = front[j] + dis (i, j);
		if (cmp (sum, front[i] + r[i]))
			sum = front[i] + r[i];
	}

	if (cmp(sum, ans))
		ans = sum;
}

int main () {
	
	int t;
	scanf ("%d", &t);
	while (t--) {

		init();
		//sort (r, r + n);
		do {
			
			solve ();
		}while (next_permutation(r, r + n));
		printf("%.3lf\n", ans);

	}
	return 0;
}

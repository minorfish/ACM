#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

const int N = 10005;
int n, l, w;
int visit[N];

double Max (const double a, const double b) { return a > b ? a: b; }

struct Len {
	
	double L, R;	
}len[N];

int cmp (const Len &a, const Len &b) { return a.L < b.L;}

void handle (int c, int r, int i) {
	
	double r1 = r;
	double c1 = c;
	double w1 = w;
	double temp = sqrt (r1 * r1 - 0.25 * w1 * w1);
	len[i].L = c - temp;
	len[i].R = c + temp;
}

int solve () {
	
	memset (visit, 0, sizeof (visit));
	if (len[0].L > 0)
		return -1;
	double s = 0;
	double ll = -1;
	int m = -1;
	for (int i = 0; i < n; i++) {
		
		if (len[i].L <= s) {
			
			if (ll < len[i].R) {

				visit[i] = 1;
				if (m >= 0)
					visit[m] = 0;
				m = i;
				ll = Max (ll, len[i].R);
			}
		} else {
			
			if (s == ll)
				return -1;
			s = ll;
			i--;
			m = -1;
		}
//		printf ("%f\n", ll);
	}
//	printf ("%f\n", ll);
	if (ll < l)
		return -1;
	int count = 0;
	for (int i = 0; i < n; i++)
		if (visit[i])
			count++;
	return count;
}

int main () {
	
	int c, r;
	while (scanf ("%d%d%d", &n, &l, &w) != EOF) {

		for (int i = 0; i < n; i++) {

			scanf ("%d%d", &c, &r);
			handle (c, r, i);
		}
		sort (len, len + n, cmp);
		
/*		for (int i = 0; i < n; i++)
			printf ("%f %f\n", len[i].L, len[i].R);*/
		printf ("%d\n", solve());

	}
	return 0;
}

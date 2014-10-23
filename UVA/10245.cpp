#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
using namespace std;

const int MAXN = 10005;
const double MLen = 10000;
const double esp = 1e-9;

struct NODE {

	double x, y;
}node[MAXN];

int cmp (const NODE &a, const NODE &b) {

	return a.x < b.x;	
}

double dist (int i, int j) {

	double px = fabs (node[i].x - node[j].x);
	double py = fabs (node[i].y - node[j].y);
	return sqrt (px * px + py * py);
}

int main () {

	int n;
	double minLen, d;
	while (scanf ("%d", &n) && n) {

		for (int i = 0; i < n; i++)
			scanf ("%lf%lf", &node[i].x, &node[i].y);
		
		sort (node, node + n, cmp);
		
		minLen = MLen;
		for (int i = 0; i < n; i++) {

			for (int j = i + 1; j < n; j++) {
				
//				printf ("%lf %lf\n", node[j].x - node[i].x - minLen,esp);
				if (node[j].x - node[i].x - minLen >= -esp)
					break;
				d = dist(i, j);
//				printf (".4lf\n", d);
				if (d < minLen) 
					minLen = d;
			}
		}
		
//		printf ("%.4lf\n", minLen);
	    if (fabs (minLen - MLen) <= esp)
			printf ("INFINITY\n");
		else 
			printf ("%.4lf\n", minLen);
	}
	return 0;
}

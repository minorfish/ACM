#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;
const double pi = acos(-1);
int n, Q;
double q;

struct build {

	double x, h;
	int th[2];
	double k[2];
	build(double x = 0, double h = 0) :x(x), h(h) {}
	friend bool operator < (const build& a, const build &b) {
		return a.x < b.x;
	}
}b[N];
/* 
   int cmp (const build a, const build b) {
   return a.x < b.x;
   }*/

double GetK(build &a, build &b) {	
	return (a.h - b.h) / fabs (a.x- b.x);
}

void handle () {

	int tmp;
	b[n - 1].th[0] = -1;
	for (int i = n - 2; i >= 0; i--) {

		b[i].th[0] = i + 1;
		b[i].k[0] = (b[i + 1].h - b[i].h) / (b[i + 1].x - b[i].x); 

		tmp = i + 1;
		while (b[tmp].th[0] != -1 && b[tmp].k[0] > GetK(b[tmp], b[i])) {	
			tmp = b[tmp].th[0];
		}
		b[i].th[0] = tmp;
		b[i].k[0] = GetK(b[tmp], b[i]);
	}

	b[0].th[1] = -1;
	for (int i = 1; i < n; i++) {

		b[i].th[1] = i - 1;
		b[i].k[1] = (b[i - 1].h - b[i].h) / (b[i].x - b[i - 1].x);

		tmp = i - 1;
		while (b[tmp].th[1] != -1 && b[tmp].k[1] > GetK(b[tmp], b[i])) {
			tmp = b[tmp].th[1];
		}
		b[i].th[1] = tmp;
		b[i].k[1] = GetK(b[tmp], b[i]);
	}
}
/*
   int bsearch (double a) {

   int l = 0; 
   int r = n - 1;
   int m;
   while (l < r) {

   m = l + (r - l) / 2;
   if (b[m].x > a)
   r = m;
   else
   l = m + 1;
   }
   return l;
   }*/

int main () {

	int T;
	scanf ("%d", &T);
	for (int cas = 1; cas <= T; cas++) {

		printf ("Case #%d:\n", cas);
		scanf ("%d", &n);
		for (int i = 0; i < n; i++) 
			scanf ("%lf%lf", &b[i].x, &b[i].h);

		sort (b, b + n);

		handle();

		scanf ("%d", &Q);
		int l, r;
		double k1, k2;
		for (int i = 0; i < Q; i++) {

			scanf ("%lf", &q);
			r = lower_bound(b, b + n, q) - b;
			l = r - 1;

			build tmp(q, 0);	
			while (b[l].th[1] != -1 && b[l].k[1] > GetK(b[l], tmp)) {			
				l = b[l].th[1];
			}

			while (b[r].th[0] != -1 && b[r].k[0] > GetK(b[r], tmp)) {
				r = b[r].th[0];
			}

			//printf ("%lf %lf %lf\n", k1, k2, pi);
			k1 = GetK(b[l], tmp);
			k2 = GetK(b[r], tmp);
			k1 = atan(k1);
			k2 = atan(k2);
			printf ("%.10f\n", (pi - k1 - k2) * 180 / pi);        
		}
	}
	return 0;
}

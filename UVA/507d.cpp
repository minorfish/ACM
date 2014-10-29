#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 2e4 + 5;
int n, s[maxn];

struct Ans {

	int v, l, r;
	Ans () {}
	Ans (int v, int l , int r) : v(v), l(l), r(r){}
	void set (int v, int l, int r) {
		this->v = v;
		this->l = l;
		this->r = r;
	}
};

Ans maxsum (int l, int r) {

	if (r - l == 1) 
		return Ans(s[l], l, l);

	Ans max_sum;
	int m = l + (r - l)/2;
	Ans Lmax = maxsum(l, m);
	Ans Rmax = maxsum(m, r);	
	if (Lmax.v > Rmax.v) 
		max_sum = Lmax;
	else if (Lmax.v < Rmax.v)
		max_sum = Rmax;
	else  {	
		if (Lmax.r - Lmax.l < Rmax.r - Rmax.l)
			max_sum = Rmax;
		else
			max_sum = Lmax;
	}

	Ans Lp(s[m - 1], m - 1, m - 1), Rp(s[m], m, m);	
	int tmp = 0;
	for (int i = m - 1; i >= l; i--) {
		tmp += s[i];
		if (tmp >= Lp.v) 
			Lp.set(tmp, i, m - 1);
	}

	tmp = 0;
	for (int i = m; i < r; i++) {
		tmp += s[i];
		if (tmp >= Rp.v) 
			Rp.set(tmp, m, i);
	}

	Ans Center(Lp.v + Rp.v, Lp.l, Rp.r);
	if (Center.v > max_sum.v) 
		max_sum = Center;
	else if (Center.v == max_sum.v) {
		int dis1 = Center.r - Center.l;
		int dis2 = max_sum.r - max_sum.l;
		if (dis1 > dis2 || (dis1 == dis2 && Center.l < max_sum.l))
			max_sum = Center;
	}

	return max_sum;
}

int main () {

	int T;
	scanf ("%d", &T);

	for (int cas = 1; cas <= T; cas++) {  

		scanf ("%d", &n);
		for (int i = 0; i < n - 1; i++)
			scanf ("%d", &s[i]);

		Ans result = maxsum(0, n - 1);
	//	printf ("%d\n", result.v);
		if (result.v < 0)  
			printf ("Route %d has no nice parts\n", cas);  
		else  
			printf ("The nicest part of route %d is between stops %d and %d\n", cas, result.l + 1, result.r + 2);  
	}  
	return 0;  
}  


#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 30;
int h, n;
int t[N];
typedef long long ll;
ll fish;

struct Lake {

	int i;
	ll f;
	int d;
	int hour;
}l[N], l1[N];

int cmp (const Lake &a, const Lake &b) { 
	if (a.f == b.f)
		return a.i < b.i;
	return a.f > b.f; 
}

int cmp1 (const Lake &a, const Lake &b) { return a.i < b.i; }

void init () {

	h *= 12;
	fish = -1;
	for (int i = 0; i < n; i++)
		l[i].hour = 0;
}

bool judge (int num, int newh) {

	sort (l1, l1 + num + 1, cmp1);
	l1[0].hour += newh;
	for (int i = 0; i <= num; i++)
		if (l1[i].hour != l[i].hour)
			return l1[i].hour > l[i].hour;
	return false;
}

void solve () {

	init ();
	int newh;
	int k, max_day;
	ll sum; 
	
	for (int i = 0; i < n; i++) {

		newh = h;	
		for (int j = 0; j <= i; j++) {

			l1[j].i = l[j].i;
			l1[j].f = l[j].f;
			l1[j].d = l[j].d;
			l1[j].hour = 0;
		}

		for (int j = 0; j <= i - 1; j++) 	
			newh -= t[j];
		if (newh <= 0)
			continue;

		if (i == 0) {

			l1[i].hour += newh;	
			newh = 0;
		}

		while (newh > 0 && i) {

			sort (l1, l1 + i + 1 , cmp);
			if (l1[0].f == 0)
				break;
			if (l1[0].d != 0) {
				
				if (l1[0].f == l1[0].f)
					k = 1;
				else {

					k = (l1[0].f - l1[1].f) / l1[0].d;
					if ((l1[0].f - l1[1].f) % l1[0].d)
						k++;
				}
			}
			else
				k = newh;
			if (newh - k < 0)
				k = newh;
			newh -= k;
			l1[0].f -= k * l1[0].d;
			if (l1[0].f < 0)
				l1[0].f = 0;
			l1[0].hour += k;
		}

		sum = 0;	
		for (int j = 0; j <= i; j++) {
			
			k = l1[j].i;
			if (!l1[j].hour)
				continue;
			if (l[k].d == 0) {

				sum += l[k].f * l1[j].hour;
				continue;
			}
			max_day = l[k].f/ l[k].d;
			if (l[k].f % l[k].d != 0)
				max_day++;
			if (l1[j].hour <= max_day) 
				max_day = l1[j].hour;
			l1[j].f = l[k].f - (max_day - 1) * l[k].d;
			sum += (l[k].f + l1[j].f) * max_day / 2;
					
		}

		if (sum > fish || (sum == fish && judge(i, newh))) {

			fish = sum;
			for (int j = 0; j <= i; j++) {
				
				if (l1[j].i == 0)
					l[0].hour = l1[j].hour + newh;
				else
					l[l1[j].i].hour = l1[j].hour;
			}	
		}
	}			
}

int main () {

	bool flag = 0;
	while (scanf ("%d", &n) && n) {

		if (flag)
			printf ("\n");
		flag = 1;
		scanf ("%d", &h);
		for (int i = 0; i < n; i++)
			scanf ("%lld", &l[i].f);
		for (int i = 0; i < n; i++)
			scanf ("%d", &l[i].d);
		for (int i = 0; i < n - 1; i++)
			scanf ("%d", &t[i]);
		for (int i = 0; i < n; i++)
			l[i].i = i;
		
		solve();
		printf ("%d", l[0].hour * 5);
		for (int i = 1; i < n; i++) 
			printf (", %d",l[i].hour * 5);
		printf ("\n");
		printf ("Number of fish expected: %lld\n", fish);
	}
	return 0;
}

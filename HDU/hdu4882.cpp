#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int N = 1e5+5;
typedef _int64 ll;

struct ST{

 	ll ei, ki;
}st[N];

bool cmp (const ST &a, const ST &b) {

	return a.ei * b.ki < a.ki * b.ei;
}

int main () {
	
	int n;
	ll sum, temp;
	while (scanf ("%d", &n) == 1 && n) {
		
		for (int i = 0; i < n; i++) 
			scanf ("%I64d", &st[i].ei);
		for (int i = 0; i < n; i++)
			scanf ("%I64d", &st[i].ki);
		
		sort (st, st + n, cmp);
		
		sum = temp = 0;
		for (int i = 0; i < n; i++) {

			temp += st[i].ei;
			sum += temp * st[i].ki;
		}
		printf ("%I64d\n", sum);	
	}
	return 0;
}

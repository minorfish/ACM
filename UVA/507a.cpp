#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 2e4 + 5;
int n, s[maxn];

int solve (int& l, int& r) {

	int Max_num, sum;
	int tmp;

	l = r = tmp = 1; //border
	Max_num = sum = s[0];

	for (int i = 1; i < n - 1; i++) {

		if (sum < 0) {
			sum = s[i];
			tmp = i + 1;
		} else
			sum += s[i];

		if (sum > Max_num) {
			Max_num = sum;
			l = tmp;
			r = i + 1;
		} else if (sum == Max_num) {
			if (r - l < i + 1 - tmp || ((r - l) == (i + 1 - tmp) && tmp < l)) {
				l = tmp;
				r = i + 1;
			}
		}
	}

	return Max_num;
}

int main () {

	int T, l, r;
	scanf ("%d", &T);

	for (int cas = 1; cas <= T; cas++) {  

		scanf("%d", &n);  
		for (int i = 0; i < n - 1; i++)  
			scanf ("%d", &s[i]);  

		int ans = solve(l, r);  
//		printf ("%d\n", ans);
		if (ans < 0)  
			printf ("Route %d has no nice parts\n", cas);  
		else  
			printf ("The nicest part of route %d is between stops %d and %d\n", cas, l, r + 1);  
	}  
	return 0;  
}  

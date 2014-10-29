#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 2e4 + 5;
int n, s[maxn];

int solve (int& l, int& r) {

	int Min_sum, sum, Max_sum;
	int tmp;

	tmp = 0; //border
	l = r = 1;
	sum = Min_sum = 0;
	Max_sum = s[0];

	for (int i = 0; i < n - 1; i++) {
		
		sum += s[i];
		if (sum - Min_sum >= Max_sum) {
			if (sum - Min_sum > Max_sum) {
				Max_sum = sum - Min_sum;
				l = tmp + 1;
				r = i + 1;
			} else if (sum - Min_sum == Max_sum) {	
				if (i - tmp > r - l) {
					l = tmp + 1;
					r = i + 1;
				}
			}
		}

		if (sum < Min_sum) {
			Min_sum = sum;
			tmp = i + 1;
		}
	}

	return Max_sum;
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

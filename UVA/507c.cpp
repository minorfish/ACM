#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 2e4 + 5;
int n, s[maxn], sum[maxn];

int solve (int& l, int& r) {

	int Max_sum, tmp;
	Max_sum = sum[0] = s[0];
	l = r = tmp = 1;

	for (int i = 1; i < n - 1; i++) {
	
		if (sum[i - 1] + s[i] < s[i]) {
			sum[i] = s[i];
			tmp = i + 1;
		} else 
			sum[i] = sum[i - 1] + s[i];
		//max
		if (Max_sum <= sum[i]) {

			if (Max_sum < sum[i]) {
				Max_sum = sum[i];
				l = tmp;
				r = i + 1;
			} else if (Max_sum == sum[i] && (i + 1 - tmp > r - l)) {
				l = tmp;
				r = i + 1;
			}
		}
	}
	return Max_sum;
}

int main () {

	int T, l, r;
	scanf ("%d", &T);

	for (int cas = 1; cas <= T; cas++) {  

		scanf ("%d", &n);
		for (int i = 0; i < n - 1; i++)
			scanf ("%d", &s[i]);

		int ans = solve(l, r);
		if (ans < 0)  
			printf ("Route %d has no nice parts\n", cas);  
		else  
			printf ("The nicest part of route %d is between stops %d and %d\n", cas, l, r + 1);  
	}  
	return 0;  
}  

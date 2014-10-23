#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int N = 1000005;
int n;
int num[N];

int main () {

	int mm, count, ans;
	while (scanf ("%d", &n) != EOF) {

		for (int i = 0; i < n; i++) 
			scanf ("%d", &num[i]);

		sort (num, num + n);
		
		count = 0;
		if (n % 2) {

			mm = num[n / 2];
			for (int i = n / 2; i >= 0 && num[i] == mm; i--)
				count++;
			for (int i = n / 2 + 1; i < n  && num[i] == mm; i++)
				count++;
			
			ans = 1;
		} else {
			
			int left = num[n / 2 - 1];
			int right = num[n / 2];
			mm = left;
			for (int i = n / 2 - 1; i >= 0 && num[i] == left; i--)
				count++;
			for (int i = n / 2; i < n && num[i] == right; i++)
				count++;
			
			ans = right - left + 1;
		}
		printf ("%d %d %d\n", mm, count, ans);
	}
	return 0;
}

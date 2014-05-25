#include <stdio.h>
#include <iostream>
using namespace std;

int main () {

	int t, n, ans;
	long long temp, x;
	scanf ("%d", &t);
	for (int i = 1; i <= t; i++) {

		ans = 0;
		scanf ("%d", &n);
		cin >> temp;
		if (temp > 0) {

			for (int j = 1; j < n; j++) {

				cin >> x;
				if (ans)
					continue;
				if (x != temp + j)
					ans = j;
			}
		}
		printf ("Case #%d: %d\n", i, ans + 1);
	}
	return 0;
}

#include <stdio.h>
#include <algorithm>
#include <functional>
using namespace std;

const int N = 10005;
int vec[N], n;

int solve () {

	for (int i = 0; i < n; i++) {

		sort (vec + i, vec + n, greater<int>());
		if (vec[i] > n - i - 1)
			return 0;
		for (int j = i + 1; j < i + 1 + vec[i]; j++) {

			vec[j]--;
			if (vec[j] < 0)
				return 0;
		}
		vec[i] = 0;
	}
	return 1;
}

int main () {

	while (scanf ("%d", &n), n) {

		for (int i = 0; i < n; i++) 
			scanf ("%d", &vec[i]);
		
		printf ("%s\n", solve() ? "Possible": "Not possible");
	}
	return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 55;

int n;
double num[N]; 
double ans;
int chose[N];

bool dfs (int k, double len) {

	if (k == n)
		return true;
	if (!k || (chose[k - 1] && num[k] - num[k - 1] >= len))
		chose[k] = 1;
	else if (k == n - 1 || num[k + 1] - num[k] >= len) {

		if (num[k + 1] - num[k] == len || num[k + 1] - num[k] >= 2 * len)
			chose[k] = 1;
		else 	
			chose[k] = 0;
	} else
		return false;
	return dfs (k + 1, len);	
}

int main () {

	int T;
	scanf ("%d", &T);
	while (T--) {

		scanf ("%d", &n);
		for (int i = 0; i < n; i++)
			scanf ("%lf", &num[i]);
		
		sort (num, num + n);
		ans = 0;
		for (int i = 1; i < n; i++) {

			if (ans < num[i] - num[i - 1] && dfs (0, num[i] - num[i - 1]))
				ans = max (ans, num[i] - num[i - 1]);
			else if (ans < (num[i] - num[i - 1]) / 2 && dfs (0, (num[i] - num[i - 1]) / 2))
				ans = max (ans, (num[i] - num[i - 1]) / 2);
		}
		printf ("%.3lf\n", ans);
	}
	return 0;
 }


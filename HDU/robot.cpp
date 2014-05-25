#include <stdio.h>
#include <string.h>

const int N = 1005;
int n, s[N];

int main () {
	
	
	while (scanf ("%d", &n) == 1) {
		
		memset (s, 0, sizeof (s));
		int ans , x;
		for (int i = 0;  i <= n; i++)  {

			scanf ("%d", &x);
			if (s[x])
				ans = x;
			else
				s[x] = 1;
		}
		printf ("%d\n", ans);
	}
	return 0;
}

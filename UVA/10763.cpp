#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 500005;
int n;
struct CANDIDATES {
	
	int x, y;
}candidates[N], temp[N];

bool cmp (const CANDIDATES &c1, const CANDIDATES &c2) {
	
	if (c1.x == c2.x)
		return c1.y < c2.y;
	return c1.x < c2.x;
}

bool judge () {

	for (int i = 0; i < n; i++) 
		if (candidates[i].y != temp[i].y  || temp[i].x != candidates[i].x)
			return false;
	return true;
}

int main () {

	int x, y;
	while (scanf ("%d", &n), n) {

		for (int i = 0; i < n; i++) {
			
			scanf ("%d%d", &x, &y);
			candidates[i].x = x;
			candidates[i].y = y;
				
			temp[i].x = y;
			temp[i].y = x;
		}
		
		if (n % 2) {
			
			printf ("NO\n");
			continue;
		}

		sort (temp, temp + n, cmp);
		sort (candidates, candidates + n, cmp);
		printf ("%s\n", judge()? "YES" : "NO");

	}
	return 0;
}

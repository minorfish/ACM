#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 10005;
int n, v[N];

struct OB {

	int pi, di;
}ob[N];

bool cmp (const OB &x, const OB &y) {
	
	return x.pi > y.pi ?true:false;
}

void init () {
	
  memset(v, -1, sizeof (v));
  for (int i = 0 ; i < n; i++)
	 scanf ("%d%d", &ob[i].pi, &ob[i].di);
  sort (ob, ob + n, cmp);

}

int getfather (int x) {

	return ( v[x] == -1) ? x: getfather(v[x]); 	
}

int main () {

	while (scanf ("%d", &n) == 1) {

		
		init ();
		int sum = 0;
		for (int i = 0; i < n; i++) {

			int p = getfather (ob[i].di);
			if (p) {
				
				sum += ob[i].pi;
				v[p] = p - 1;
			}
		}
		printf ("%d\n", sum);
	}
	return 0;
}

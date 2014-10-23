#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 1005;
const int M = 20005;

int k, n;
int visit[M];

struct jogger {

	int a, b;
}jo[N];

int cmp (const jogger &a, const jogger &b) {

	if (a.b == b.b)
		return a.a > b.a;
	return a.b < b.b;
}

int solve () {

	int count = 0;
	int s = -M;
	int c;
	memset (visit, 0, sizeof (visit));
	for (int i = 0; i < n; i++) {

		if (jo[i].a > s) {

			//			printf ("%d\n", jo[i].b - jo[i].a + 1);
			if (jo[i].b - jo[i].a + 1 <= k) {
				for (int j = jo[i].a; j <= jo[i].b; j++) 
					visit[j + 10000] = 1;
				count += jo[i].b - jo[i].a + 1;
			} else {

				//				printf ("----\n");
				for (int j = jo[i].b; j > jo[i].b - k; j--)
					visit[j + 10000] = 1;
				count += k;
			}
			s = jo[i].b;
		} else {

			c = 0;
			for (int j = jo[i].a; j <= s; j++)	
				if (visit[j + 10000])
					c++;

			if (jo[i].b - jo[i].a + 1 <= k) {

				if (c >= jo[i].b - jo[i].a + 1)
					continue;
				for (int j = jo[i].b; j >= jo[i].a; j--) {

					if (visit[j + 10000])
						continue;
					visit[j + 10000] = 1;
					count++;
				}
				s = jo[i].b;
			} else {

				if (c >= k)
					continue;
				int m = 0;
				for (int j = jo[i].b; j >= jo[i].a; j--) {

					if (m + c == k)
						break;
					if (visit[j + 10000])
						continue;
					visit[j + 10000] = 1;
					count++;
					m++;	
				}
				s = jo[i].b;
			}
		}
	}
	return count;
}

int main () {

	int t;
	int a, b;
	scanf ("%d", &t);
	while (t--) {

		scanf ("%d%d", &k, &n);
		for (int i = 0; i < n; i++) {

			scanf ("%d%d", &a, &b);
			if (a < b) {
				jo[i].a = a;
				jo[i].b = b;
			} else {

				jo[i].a = b;
				jo[i].b = a;
			}
		}

		sort (jo, jo + n, cmp);
		int count = solve();
		printf ("%d\n", count);
		for (int i = 0; i < M; i++) 
			if (visit[i])
				printf ("%d\n", i - 10000);
		if (t)
			printf ("\n");
	}
	return 0;
}

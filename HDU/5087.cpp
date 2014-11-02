#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1005;
int l[maxn], c[maxn];
int arr[maxn];

int main () {

	int T, n;
	scanf ("%d", &T);
	while (T--) {

		scanf ("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf ("%d", &arr[i]);
	
		for (int i = 1; i <= n; i++)
			l[i] = c[i] = 1;
	
		int ans = 1; 
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j < i; j++) {

				if (arr[i] > arr[j]) {
					if (l[j] + 1 > l[i]) {
						l[i] = l[j] + 1;
						c[i] = c[j];
					} else if (l[j] + 1 == l[i])
						c[i] = 2;
				}
			}
			ans = max (ans, l[i]);
		}

			
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			if (l[i] == ans)
				cnt += c[i];	
							  
		if (cnt > 1)
			printf ("%d\n", ans);
		else
			printf ("%d\n", ans - 1);
	}
	return 0;
}

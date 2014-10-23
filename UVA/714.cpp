#include <stdio.h>
#include <string.h>

const int N = 505;
typedef long long ll;
int n, m;
ll max_num, min_num;

int books[N];
int visit[N];

ll Min (const ll a, const ll b) { return a < b ? a : b; } 

int divide (ll value) {

	int i = n - 1;
	int count = 0;
	ll sum;
	while (i >= 0) {

		sum = 0;
		if (sum + books[i] > value)
			return m + 1;
		while (i >= 0 && sum + books[i] <= value) {
			
			sum += books[i--];
		}
		if (i >= 0)
			visit[i] = 1;
		count++;
	}
	return count;
}

int bsearch () {

	ll left = min_num;
	ll right = max_num;
	ll mid;
	while (left < right) {

	   mid = left + ((right - left)>>1);
	   if (divide (mid) <= m)
		   right = mid;
	   else
		   left = mid + 1; 
	}
	return right;
}

void solve () {
	
	ll ans = bsearch();
    memset (visit, 0, sizeof (visit));
    int cnt =  divide (ans);
	
	for (int i = 0; i < n - 1 && cnt < m; i++) {

		if (!visit[i]) {

			visit[i] = 1;
			cnt++;
		}
	}
}

int main () {

	int t;
	scanf ("%d", &t);
	while (t--) {

		max_num = 0;
		scanf ("%d%d", &n, &m);
		for (int i = 0; i < n; i++) {

			scanf ("%d", &books[i]);
			max_num += books[i];
			if (i == 0)
				min_num = books[i];
			else
				min_num = Min(min_num, books[i]);
		}
		
		memset (visit, 0, sizeof (visit));
		if (m != 1)  
			solve();	
/*			for (int i = 0; i < n; i++)
			printf ("%d ", visit[i]);
			printf ("\n");*/

		for (int i = 0; i < n - 1; i++) {

			printf ("%d ", books[i]);
			if (visit[i])
				printf ("/ ");
		}
		printf ("%d\n", books[n - 1]);
	}
	return 0;
}

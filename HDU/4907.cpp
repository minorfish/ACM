#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>

using namespace std;

const int N = 2e5 + 5;

int num[N];
int p[N];
int n, m;

void init () {
	
	sort (num, num + n, greater<int>());
	for (int i = 1; i < N; i++)
		p[i] = i;	
}

int getParent (int q) {

	return q == p[q] ? q : p[q] = getParent(p[q]);
}

int main () {

	int T;
	scanf ("%d", &T);
	while (T--) {
	
		scanf ("%d%d", &n, &m);
		for (int i = n - 1; i >= 0; i--) 
			scanf ("%d", &num[i]);			
		
		init ();

		for (int i = 0; i < n; i++) 
			p[num[i]] = getParent(num[i] + 1); 

		int q;
		for (int i = 0; i < m; i++) {
			scanf ("%d", &q);
			printf ("%d\n", p[q]);
		}
		//printf ("%d\n", N);
	}
	return 0;
}

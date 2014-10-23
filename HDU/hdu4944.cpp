#include <cstdio>
#include <cstring>

typedef unsigned __int64 ll;

const int maxn = 500005;
const ll M = 1LL<<32;

ll f1[maxn];
ll f2[maxn];

void init () {
	
	for (int i = 1; i < maxn; i++) {
		for (int j = 1; j * i < maxn; j++) 
			f1[i * j] = (f1[i * j] + (1LL + i) * i / 2) % M;
	}

	f2[1] = 1;
	for (int i = 2; i < maxn; i++)
		f2[i] = (f2[i - 1] + f1[i] * i) % M; 	
}

int main () {

	int t;
	int n;
	init ();
	scanf ("%d", &t);
	for (int i = 1; i <= t; i++) {

		scanf ("%d", &n);
		printf ("Case #%d: %I64u\n", i, f2[n]); 
	}
	return 0;
}

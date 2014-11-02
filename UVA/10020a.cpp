#include <stdio.h>  
#include <string.h>  
#include <algorithm>  
using namespace std;  

const int N = 100005;  
int m, n;  
int visit[N];  

struct segments {  

	int l, r;  
}s[N];  

int cmp (const segments& a, const segments &b) { 
	if (a.l == b.l)
		return b.r > a.r;
	return a.l < b.l; 
}  


int solve () {  

	memset (visit, 0, sizeof (visit));  

	if (s[0].l > 0)          
		return 0;

	int cover = -1;
	int pre = 0;
	int t = -1;
	for (int i = 0; i < n; i++) {  

		if (s[i].l <= pre) {	
			if (cover < s[i].r) {  
				visit[i] = 1;  
				cover = s[i].r;
				if (t != -1)
					visit[t] = 0;
				t = i;
			}
		} else {
			pre = cover;
			if (s[i].l > pre)
				return 0;
			i--;
			t = -1;
		}
		if(cover >= m)        
			break;  
	} 

	if (cover < m)                   
		return 0;  
	int count = 0;  
	for (int i = 0; i < n; i++)  
		if (visit[i])  
			count++;  
	return count;  
}  

int main () {  

	int t;  
	int l, r;  
	scanf ("%d", &t);  
	while (t--) {  

		scanf ("%d", &m);  
		n = 0;  
		while (scanf ("%d%d", &l, &r), l || r) {  

			if (r <= 0 || l >= m)  
				continue;  
			s[n].l = l;  
			s[n].r = r;  
			n++;  
		}  

		sort (s, s + n, cmp);  
		int count = solve();  
		printf ("%d\n", count);  
		if (count) {  
			for (int i = 0; i < n; i++)  
				if (visit[i])  
					printf ("%d %d\n", s[i].l, s[i].r);  
		}  
		if (t)  
			printf ("\n");  
	}  
	return 0;  
}  

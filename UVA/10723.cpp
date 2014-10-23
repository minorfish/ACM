#include <cstdio>
#include <cstring>

const int N = 35;

typedef long long ll;

int l[N][N];
ll n[N][N];
char s1[N], s2[N];
int l1, l2;

int Max (const int a, const int b) { return a > b? a: b; }

void init () {
	
	l1 = strlen (s1);
	l2 = strlen (s2);
	memset (l, 0, sizeof (l));	
	for (int i = 0; i <= l1; i++)
		n[i][0] = 1;
	for (int i = 0; i <= l2; i++)
		n[0][i] = 1;	
}

int main () {
	
	int t;
	scanf ("%d%*c", &t);
	for (int k = 1; k <= t; k++) {

		printf ("Case #%d:", k);	
		gets (s1);
		gets (s2);
		
		init ();

		for (int i = 1; i <= l1; i++) {

			for (int j = 1; j <= l2; j++) {
				
				if (s1[i - 1] == s2[j - 1]) {

					l[i][j] = l[i - 1][j - 1] + 1;
					n[i][j] = n[i - 1][j - 1];
				} else {
					
					l[i][j] = Max (l[i - 1][j], l[i][j - 1]); 

//					printf ("%d %d %d %d %d\n", i, j, l[i - 1][j], l[i][j - 1], l[i][j]); 
					if (l[i - 1][j] > l[i][j - 1])
						n[i][j] = n[i - 1][j];
					else if (l[i - 1][j] < l[i][j - 1])
						n[i][j] = n[i][j - 1];
					else
						n[i][j] = n[i][j - 1] + n[i - 1][j];
				}
			}
		}
		
		printf (" %d %lld\n", l1 + l2 - l[l1][l2], n[l1][l2]);
	}
	return 0;
}

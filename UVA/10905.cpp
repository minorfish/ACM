#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 55;
const int M = 10000;
int n;

char str1[M], str2[M];

struct Num {

	char s[M];
}num[N];

int cmp (const Num &a, const Num &b) {

	strcpy (str1, a.s);
	strcat (str1, b.s);
	strcpy (str2, b.s);
	strcat (str2, a.s);
	if (strcmp (str1, str2) > 0)
		return 1;
	return 0;
   /* int l1 = strlen (a.s);
	int l2 = strlen (b.s);

	if (l1 <= l2) {
		
		for (int i = 0, j = 0; j < l2; i = (i + 1) % l1, j++) {
		
			if (b.s[j] != a.s[i])
				return a.s[i] > b.s[j];
		}
	} else {

		for (int i = 0, j = 0; j < l1; i = ( i + 1) % l2, j++) {
			
			if (a.s[j] != b.s[i])
				return a.s[j] > b.s[i];
		}
	}
	return 0;*/
}

int main () {
	
	while (scanf ("%d", &n), n) {

		for (int i = 0; i < n; i++)
			scanf ("%s", num[i].s);
		
		sort (num, num + n, cmp);
		
		for (int i = 0; i < n; i++)
			printf ("%s", num[i].s);
		printf ("\n");
	}
	return 0;
}

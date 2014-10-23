#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

const int N = 105;
char first[N];
struct WORDS{

	char str[N];
}words[N];

int cmp (const WORDS & w1, const WORDS & w2) {

	return strcmp(w1.str, w2.str) < 0 ? true :false;
}

int caculate (int n) {
	
	int sum = 0;
	int len;
	int k;
	for (int i = 1; i < n; i++) {

		len = strlen(words[i].str);
		k = 0;
		while (words[i - 1].str[k]  && words[i - 1].str[k] == words[i].str[k]) {

			k++;
		}
		sum += len - k;
	}
	return sum + strlen (words[0].str);
}


int main () {

	int t;
	scanf ("%d", &t);
	while (t--) {

		int n;
		scanf ("%d", &n);
		for (int i = 0; i < n; i++)
			scanf ("%s", words[i].str);
		memcpy (first, words[0].str, sizeof (first));
		sort (words, words + n, cmp);
		printf ("%d\n", caculate(n));	
		for (int i = 0; i < n; i++)
			printf("%s\n", words[i].str);
	}
	return 0;
}

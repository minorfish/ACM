#include <stdio.h>
#include <string.h>

const int N = 1000005;
char s[N], t[N];

bool match () {
	
	int i = 0;
	int lens = strlen(s);
	int lent = strlen(t);
	for (int j = 0; j < lent; j++) {
		
		if (i == lens)
			return true;
		if (lens - i > lent - j)
			return false;
		if (s[i] == t[j])
			i++;
	}
	if (i == lens)
		return true;
	return false;
}

int main () {
	
	while (scanf ("%s", s) != EOF) {

		scanf ("%s", t);
		printf ("%s\n", match()? "Yes" :"No");
	}
	return 0;
}

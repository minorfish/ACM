#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int N = 105;
const int M = 26;
char s[N];
int visit[N];

int solve () {

	memset (visit, 0, sizeof (visit));
	int len = strlen(s);
	for (int i = 0; i < len; i++)
		visit[s[i] - 'a']++;

	int count = 0;
	for (int i = 0; i < M; i++)
		if (visit[i] % 2)
			count++;

	if ( (len % 2 && count == 1) || (len % 2 == 0 && !count)) {
	
		int l, r, min;
		count = 0;
		while (len > 1) {

			min = N;
			memset (visit, 0, sizeof (visit));	
			for (int i = 0; i < len; i++) {

				if (visit[i])
					continue;
				visit[i] = 1;
				for (int j = len - 1; j >= 0; j--) {

					if (s[j] == s[i] && !visit[j]) {

						visit[j] = 1;
						if (len - abs (i - j) - 1  < min) {

							min = len - abs (i - j) - 1;
							l = i;
							r = j;
						}
						break;
					}
				}

//			printf ("%d\n", min);			
			}
			count += min;
//			printf ("%d\n", min);
//			printf ("%d\n", count);
//			printf ("%d %d\n", l, r);
			
			if (l > r) {
				
				min = l;
				l = r;
				r = min;
			}

			for (int i = l; i < len - 1; i++)
				s[i] = s[i + 1];
			for (int i = r - 1; i < len - 2; i++)
				s[i] = s[i + 1];
//			s[len - 2] = '\0';
//				printf ("%s\n", s);
			len -= 2;
		}
		return count;
	}
	return -1;
}

int main () {

	int t;
	int count;
	scanf ("%d", &t);
	while (t--) {

		scanf ("%s", s);

		count = solve();
		if (count < 0)
			printf ("Impossible\n");
		else
			printf ("%d\n", count);
	}
	return 0;
}

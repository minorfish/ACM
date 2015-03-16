#include <cstdio>
#include <cstring>

const int maxn = 1e6 + 5;

char str[maxn];
int n;
/*
int handle () {

	int ans = 0;
	int len = strlen (str);
	bool flag = 1;
	for (int i = 0; i <= len; i++) {
		
		if (str[i] >= 'A' && str[i] <= 'Z') {
			
			if (flag && str[i] == 'G')
				ans++;
			flag = 0;
		} else 
			flag = 1;
	}
	return ans;
}*/

int main () {

	int T;
	char ch;
	scanf ("%d", &T);
	getchar();

	for (int i = 1; i <= T; i++) {
	
	//	gets(str);
	//	printf ("Case %d: %d\n", i, handle());
		int ans = 0;
		while ((ch = getchar()) != EOF && ch != '\n') {

		/*	while (ch == ' ') {
				ch = getchar();
			}*/

			if (ch == 'G')
				ans++;
//			printf ("%c\n", ch);
			while ((ch = getchar()) != EOF) {

				if (ch == ' ' || ch == '\n')
					break;
			}

			if (ch == '\n')
				break;
		}
		printf ("Case %d: %d\n", i, ans);
	}
	return 0;
}


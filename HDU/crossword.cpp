#include <stdio.h>
#include <string.h>

const int N = 35;
const int M = 105;
const int H = 10005;

char map[N][N], word[H][N];
int s[M][5], k, h[H], n, m;

int hash (int j) {

	int num = 0;
	for (int i = 0; i < strlen (word[j]); i++)
		num =  (num * 33 + word[j][i] ) % 997;
	return num ;
}

void solve () {

	memset(h, -1, sizeof(h));
	int num;
	for (int i = 0; i < k; i++) {

		 num = hash (i);
		 printf ("%d\n", num);
  	 		h[num] = i;
	}
	for (int i = 0; i < m; i++) {

		num = h[s[i][4]];
		if (num != -1) {

			if (s[i][0] == s[i][2]) {
				
				int a;
				for (int j = s[i][1] - 1, a = 0; j < s[i][3]; j++, a++)
					map[s[i][0] - 1][j] = word[num][a];
			}
			else {

				int a;
				for (int j = s[i][0] - 1, a = 0; j < s[i][2]; j++, a++)
					map[j][s[i][1] - 1] = word[num][a];
			}
		}
			
	}

}

int main () {

	while (scanf ("%d%d", &n, &m), n||m) {

		int x1, y1, x2, y2, w;
		for (int i = 0; i < m; i++)  
			for (int j = 0; j < 5; j++)
				scanf ("%d", &s[i][j]);

		scanf("%d", &k);
		for (int i = 0; i < k; i++)
			scanf("%s", word[i]);

		memset(map, 0, sizeof(map));
		solve ();
		printf ("%d", h[207]);
		for (int i = 0; i < n; i++)  {

			for (int j = 0; j < n; j++)
				if ( map[i][j] != 0)
					printf("%c", map[i][j]);
				else 
					printf(" ");
			printf("\n");
		}
		
	}
	return 0;
}

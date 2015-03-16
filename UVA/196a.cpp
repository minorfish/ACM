#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 1005;

typedef struct Sheet {

	int flag;
	int count;
	int row[55];
	int column[55];
	int value;
}sheet;

sheet s[maxn][maxn];
int n, m;

void translate(int x, int y, char * f) {

	int len = strlen(f);
	int row_num = 0, col_num = 0;
	bool flag = false;

	for (int i = 1; i <= len; i++) {

		if (f[i] >= 'A' && f[i] <= 'Z') { 
			col_num = col_num * 26 + (f[i] - 'A' + 1);	
			flag = true;
		} else if (f[i] != '+' && f[i] != '\0') {
			row_num = row_num * 10 + f[i] - '0';
		} else {

			if (flag) {
				s[x][y].row[s[x][y].count] = row_num;
				s[x][y].column[s[x][y].count++] = col_num;
			} else
				s[x][y].value += row_num;
			row_num = col_num = 0;
			flag = false;
		}	
	}
//	printf ("%d, %d, %d ,%d\n", x + 1, y + 1, s[x][y].value, s[x][y].count);	
}

void Read_Sheet() {

	char f[maxn];
	char str[maxn];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			
			scanf ("%s", f);
			if (f[0] != '=') {
				
				s[i][j].flag = 0;
				sscanf(f, "%d", &s[i][j].value);
			} else {

				s[i][j].flag = 1;
				s[i][j].count = s[i][j].value = 0;
				translate (i, j, f);
			}
		}
}

void dfs (int x, int y) {

	int newx, newy;

	if (s[x][y].flag) {
		
		for (int i = 0; i < s[x][y].count; i++) { 
			newx = s[x][y].row[i] - 1;
			newy = s[x][y].column[i] - 1;

			if (s[newx][newy].flag)
				dfs(newx, newy);

			if (!s[newx][newy].flag)	
				s[x][y].value += s[newx][newy].value;
		}

		s[x][y].flag = 0;
	}
}

int main () {
	
	int T;
	scanf ("%d", &T);

	while (T--) {
		
		scanf ("%d%d", &m, &n);
		Read_Sheet();

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (s[i][j].flag)
					dfs(i, j);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (j != m - 1)
					printf ("%d ", s[i][j].value);
				else
					printf ("%d\n", s[i][j].value);
			}
	}
	return 0;
}

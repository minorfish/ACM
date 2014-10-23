#include <cstdio>
#include <cstring>

const int N = 30;
char preord[N], inord[N];
char postord[N];
int p1, p2, len;

int search (char val) {

	for (int i = 0; i < len; i++)
		if (inord[i] == val)
			return i;
}

void build(int l, int r) {

	if (r - l < 1)
		return;
	int pos = search (preord[p1++]);
	build(l, pos);	
	build(pos + 1, r);
	postord[p2++] = inord[pos];	
}

int main () {
	
	while (scanf ("%s%s", preord, inord) != EOF) {

		p1 = p2 = 0;
		len = strlen (preord);
		build(0, len);
		postord[len] = '\0';
		printf ("%s\n", postord);
	}
	return 0;
}

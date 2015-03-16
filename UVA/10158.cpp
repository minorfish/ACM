#include <cstdio>
#include <cstring>

const int maxn = 10005;
int N;
int p[maxn * 2];

void init () {

	for (int i = 0; i < 2 * N; i++)
		p[i] = i;		
}

int getParent(int x) {
	return x == p[x] ? x : p[x] = getParent(p[x]); 
}

bool setfriend (int x, int y) {

	int  x1 = getParent(x);
	int  y1 = getParent(y);
	int  x2 = getParent(x + N);
	int  y2 = getParent(y + N);
	
	if (x1 == y2 || y1 == x2)
		return false;
	else {
		
		p[x1] = y1;
		p[x2] = y2;
		return true;
	}
}

bool setenemies(int x, int y ) {
	
	int  x1 = getParent(x);
	int  y1 = getParent(y);
	int  x2 = getParent(x + N);
	int  y2 = getParent(y + N);
	
	if (x1 == y1 || y2 == x2)
		return false;
	else {
		
		p[x1] = y2;
		p[y1] = x2;
		return true;
	}
}

bool is_friend(int x, int y) {
		
	int  x1 = getParent(x);
	int  y1 = getParent(y);
	int  x2 = getParent(x + N);
	int  y2 = getParent(y + N);
	
	if (x1 == y1)
		return true;
	return false;	
}

bool is_enemies(int x, int y) {

	int  x1 = getParent(x);
	int  y1 = getParent(y);
	int  x2 = getParent(x + N);
	int  y2 = getParent(y + N);
	
	if (x1 == y2 || x2 == y1)
		return true;
	return false;	
}

int main () {
	
	int op, x, y;

	scanf ("%d", &N);
	init();
	
	while (scanf ("%d%d%d", &op, &x, &y) != EOF && (op || x || y)) {
		
		if (op == 1) {
			if (setfriend(x, y) == false)
				printf("-1\n");
		} else if (op == 2) {
			if (setenemies(x, y) == false)
				printf ("-1\n");
		} else if (op == 3)
			printf ("%d\n", is_friend(x, y));
		else 
			printf ("%d\n", is_enemies(x, y));
	}
	return 0;
}

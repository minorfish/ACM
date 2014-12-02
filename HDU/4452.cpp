#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N, T;
const int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

struct Rabbit {
	int d, s, t;
	int x, y;
}r[2];

int change (char ch) {

	if (ch == 'N')
		return 0;
	else if (ch == 'W')
		return 1;
	else if (ch == 'S')
		return 2;
	else
		return 3;
}

void jumpe (int i) {

	int nx = r[i].x + r[i].s * dir[r[i].d][0];
	int ny = r[i].y + r[i].s * dir[r[i].d][1];

	if (nx > 0 && nx <= N && ny > 0 && ny <= N) {
		r[i].x = nx;
		r[i].y = ny;
	} else {

		if (r[i].d == 0) 
			r[i].x += r[i].s - 2 * (r[i].x - 1);
		else if (r[i].d == 1) 
			r[i].y += r[i].s - 2 * (r[i].y - 1);
		else if (r[i].d == 2) 
			r[i].x -= r[i].s - 2 * (N - r[i].x);
		else 
			r[i].y -= r[i].s - 2 * (N - r[i].y);
	
		r[i].d = (r[i].d + 2) % 4;
	}	
}

int main () {
	
	char str[10];
	while (scanf ("%d", &N) && N ) {
	
		scanf ("%s%d%d", str, &r[0].s, &r[0].t);
		r[0].d = change(str[0]);
		scanf ("%s%d%d", str, &r[1].s, &r[1].t);
		r[1].d = change(str[0]);
		r[0].x = r[0].y = 1;
		r[1].x = r[1].y = N;
		scanf ("%d", &T);

		for (int i = 1; i <= T; i++) {

			jumpe(0);
			jumpe(1);

//			printf ("%d %d\n%d %d\n", r[0].x, r[0].y, r[1].x, r[1].y);
			if (r[0].x == r[1].x && r[0].y == r[1].y)
				swap(r[0].d, r[1].d); 
			else {
				if ((i % r[0].t == 0))
					r[0].d = (r[0].d + 1) % 4;
				if ((i % r[1].t == 0))
					r[1].d = (r[1].d + 1) % 4;
			}
			
		}

		printf ("%d %d\n%d %d\n", r[0].x, r[0].y, r[1].x, r[1].y);
	}
	return 0;
}

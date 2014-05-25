#include <stdio.h>
#include <math.h>

const double esp = 1e-9;

struct POINT {

	double x, y;
}point[4], center;

struct LINE {

	double a, b, c;
};

LINE getline (POINT p1, POINT p2) {

	LINE l;
	l.a = (p2.y - p1.y);
	l.b = (p1.x - p2.x);
	l.c = p1.x * p2.y - p2.x * p1.y;
	return l;
}

POINT inter_point (LINE l1, LINE l2) {

	POINT p;
	p.y = (l2.a * l1.c - l1.a * l2.c) / (l2.b * l1.a - l2.a * l1.b);
	p.x = (l1.c * l2.b - l2.c * l1.b) / (l2.a * l1.b - l2.b * l1.a);
	return p;
}

POINT circle_p (POINT p1, POINT p2, POINT p3 ) {

	POINT p;
	double a = p2.x - p1.x;
	double b = p2.y - p1.y;
	double c = p2.y * p2.y - p1.y * p1.y + p2.x * p2.x - p1.x * p1.x;
	double d = p3.x - p1.x;
	double e = p3.y - p1.y;
	double f = p3.y * p3.y - p1.y * p1.y + p3.x * p3.x - p1.x * p1.x;
	p.y = (f * a - c * d) / (e * a - b * d) * 0.5;
	p.x = (c - 2 * p.y * b) / (2 * a);
	return p;

}

double dis (POINT p1, POINT p2) {

	double dx = p1.x - p2.x;
	double dy = p1.y - p2.y;
	return sqrt (pow (dx, 2) + pow (dy, 2));
}

bool solve () {

	double r = dis (center , point[0]);
	if (dis (center , point[3]) - r > esp)
		return false;
	LINE l1, l2;
	POINT p;
	int t;
	for (int i = 0; i < 3; i++) {
		
		t = (i + 2) % 3;
		l1 = getline (point[i], point[( i + 1 ) % 3]);
		l2.a = l1.b;
		l2.b = -l1.a;
		l2.c = l1.a * center.y - l1.b * center.x;
		p = inter_point (l1, l2);
		p.x = (p.x * 2 - center.x);
		p.y = (p.y * 2 - center.y);
		if (dis (p, point[t]) - r > esp)
			continue;
		if (dis (p, point[3]) - r > esp) 
			return false;	
	}	
	return true;
}

int main () {

	int t;
	double x, y;
	scanf ("%d", &t);
	for (int i = 1; i <= t; i++) {

		for (int j = 0; j < 4; j++) {

			scanf ("%lf%lf", &x, &y);
			point[j].x = x;
			point[j].y = y;
		}	
		center = circle_p(point[0], point[1], point[2]);	
		printf ("Case #%d: %s\n", i, solve()?"Danger":"Safe");
	}
	return 0;
}

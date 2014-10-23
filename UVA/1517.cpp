#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

const int N = 1e4 + 5;
typedef long long ll;

int S, R, W, P;

struct Point {

	int x, y;
	Point (int x = 0, int y = 0) : x(x) , y(y) {}
	bool operator < (const Point &a) const {

		return a.x == x ? y < a.y : x < a.x; 
	}

	Point operator - (const Point &a) const {

		Point ans;
		ans.x = x - a.x;
		ans.y = y - a.y;
		return ans;
	}
	
	Point operator + (const Point &a) const {

		Point ans;
		ans.x = x + a.x;
		ans.y = y + a.y;
		return ans;
	}
	
	int operator ^ (const Point &a) const {

		return x * a.y - y * a.x;
	}
};

struct Line {

	Point b, e;
	void init (int bx = 0, int by = 0, int ex = 0, int ey = 0) {
		b.x = bx;
		b.y = by;
		e.x = ex;
		e.y = ey;
	}
}l[15];

vector<Point> p;
set<Point> vis;

ll dis (Point a, Point b) {

	ll dx = a.x - b.x;
	ll dy = a.y - b.y;
	return dx * dx + dy * dy;
}

bool check (Point a, Point b, Point c, Point d) {

	if (min (a.x, b.x) > max (c.x, d.x) ||
		min (a.y, b.y) > max (c.y, d.y) ||
		min (c.x, d.x) > max (a.x, b.x) ||
		min (c.y, d.y) > max (a.y, b.y))
		return false;

	ll i = (a - b) ^ (a - c);
	ll j = (a - b) ^ (a - d);
	ll k = (c - d) ^ (c - a);
	ll l = (c - d) ^ (c - b);
	return i * j <= 0 && k * l <= 0;
}

bool judge (Point a, Point b) {

	if (vis.find(a) == vis.end())
		return false;

	ll d = dis (a, b);
	if (d > R * R)
		return false;

	int cnt = 0;
	for (int i = 0; i < W; i++) 
		if (check(a, b, l[i].b, l[i].e)) 
			cnt++;

	if (cnt > R)
		return false;
	return d <= (R - cnt) * (R - cnt);
}

int main () {

	int T;
	int x, y;
	Point tmp;
	scanf ("%d", &T);
	while (T--) {

		scanf ("%d%d%d%d", &S, &R, &W, &P);
		vis.clear();

		for (int i = 0; i < S; i++) {
			scanf ("%d%d", &tmp.x, &tmp.y);
			vis.insert (tmp);
		}
	
		int bx, by, ex, ey;
		for (int i = 0; i < W; i++) {

			scanf ("%d%d%d%d", &bx, &by, &ex, &ey);
			l[i].init(bx, by, ex, ey);
		}

		Point a;
		int d;
		for (int i = 0; i < P; i++) {

			p.clear();
			scanf ("%d%d", &tmp.x, &tmp.y);
			for (int j = -R; j <= R; j++) {
				d = sqrt (R * R - j * j);
				for (int k = max (-R, -d) ; k <= min (R, d); k++) {
			
					a.x = tmp.x + j;
					a.y = tmp.y + k;
					if (judge(a, tmp))
						p.push_back (a);
				}
			}
			
			printf ("%d", p.size());
			for (int j = 0; j < p.size(); j++) 
				printf (" (%d,%d)", p[j].x, p[j].y);
			printf ("\n");
		}	
	}
	return 0;
}

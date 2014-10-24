#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;
const int maxn = 2e5 + 5;
#define lowbit(x) ((x)&(-x))

vector<int> pos;
set<int> s;
map<int, int> x, y;
int n, C[maxn];

struct Point {

	int x, y, score;
}p[maxn];

void add (int x, int addv) {

	while (x < maxn - 5) {
		C[x] += addv;
		x += lowbit(x);
	}
}

int sum (int x) {

	int ret = 0;
	while (x > 0) {
		ret += C[x];
		x -= lowbit(x);
	}
	return ret;
}

inline int cmp_rx (const Point &a, const Point &b) {
	if (a.x == b.x)
		return a.y > b.y;
	return a.x < b.x;
}

inline int cmp_lx (const Point &a, const Point &b) {
	if (a.x == b.x)
		return a.y < b.y;
	return a.x > b.x;
}

void init () {

	x.clear();
	y.clear();
	pos.clear();

	for (int i = 0; i < n; i++) {
		scanf ("%d%d", &p[i].x, &p[i].y);
		p[i].score = 0;
		pos.push_back(p[i].y);
		x[p[i].x]++;
		y[p[i].y]++;
	}

	sort (pos.begin(), pos.end());
	pos.erase (unique(pos.begin(), pos.end()), pos.end());
}

void build (int flag) {

	int x;
	memset (C, 0, sizeof (C));
	for (int i = 0; i < n; i++) {

		x = lower_bound(pos.begin(), pos.end(), p[i].y) - pos.begin();
		if (flag)
			x = pos.size() - 1 - x;
		printf ("%d %d\n", p[i].y, x);
		add(x + 1, 1);	
	}
}

void solve (int flag) {

	int x;
	for (int i = 0; i < n; i++) {

		x = lower_bound(pos.begin(), pos.end(), p[i].y) - pos.begin();
		if (flag) {
			x = pos.size() - 1 - x;
			p[i].score += sum(x);
		} else 
			p[i].score += sum(x + 2);
		printf ("%d %d %d\n", p[i].x, p[i].y, p[i].score);
		add(x + 1, -1);
	}
}

void solve_rtop () {

	build(1);
	sort (p, p + n, cmp_rx);
	solve(1);
}

void solve_lboutom () {
	
	build(0);
	sort (p, p + n, cmp_lx);			
	solve(0);
}

void f_score () {

	int ans = -1;
	int score = p[0].score;
	int pre = p[0].x;

	for (int i = 1; i < n; i++) {
	
		if (p[i].x == pre)
			score = min(score, p[i].score);
		else {
		
			ans = max(ans, score);
			score = p[i].score;
			pre = p[i].x;
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (p[i].score == ans) {	
			s.insert(n - ans - x[p[i].x] - y[p[i].y] + 1);	
	//		printf ("%d %d\n", p[i].x, p[i].y);
		}
	}

	for (int i = 0; i < n; i++)
		printf ("%d %d %d\n", p[i].x, p[i].y, p[i].score);
	printf ("Stan: %d; Ollie:", ans);
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) 
		printf (" %d", *it);
	printf (";\n");

}

int main () {

	while (scanf ("%d", &n) == 1 && n) {

		init();

		solve_rtop();	
		solve_lboutom();
		
		f_score();	
	}	
	return 0;
}

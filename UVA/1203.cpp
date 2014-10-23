#include <cstdio>
#include <queue>

using namespace std;

const int N = 10;
const int maxn = 1005;

struct Item {

	int num, period, time;
	bool operator < (const Item &a) const {
		
		return time > a.time || (time == a.time && num > a.num);
	}
}item[maxn];

priority_queue <Item> q;

int main () {
		
	char str[N];
	Item tmp;
	int K;

	while (scanf ("%s", str) == 1 && str[0] != '#') {

		scanf ("%d%d", &tmp.num, &tmp.period);
		tmp.time = tmp.period;
		q.push (tmp);
	}
	
	scanf ("%d", &K);
	
	while (K--) {
		
		tmp = q.top();
		q.pop();
		printf ("%d\n", tmp.num);
		tmp.time += tmp.period;
		q.push (tmp);
	}
	return 0;
}

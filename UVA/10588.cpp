#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;
const int N = 1005;
const int INF = 1e6 + 5;
typedef long long ll;

struct Person {

	int th;
	ll t;
	Person () {}	
	Person (int th, ll t): th(th), t(t) {}
	bool operator < (const Person &a) const {

		return t > a.t || (t == a.t && th > a.th);
	}
};

priority_queue<Person> q[N];
queue<int> p[N];
ll t[N];

int main () {

	int T;
	int n, m, k, item;
	int P;
	ll now; 
	scanf ("%d", &T);
	while (T--) {

		scanf ("%d%d", &n, &m);
		now = INF;
		for (int i = 0; i < n; i++) {

			scanf ("%lld%d", &t[i], &k);
			now = min (now, t[i]);
			while (k--) {

				scanf ("%d", &item);
				p[i].push(item);
			}
		}
	
		for (int i = 0; i < n; i++) {

			if (!p[i].empty()) {
				P = p[i].front();
				p[i].pop();
				q[P].push(Person(i, t[i]));		
			}
		}

		Person person;

		while (1) {
			for (int i = 1; i <= m; i++) {

				if (!q[i].empty()) {

					person = q[i].top();
					if (person.t > now)
						continue;
					if (!p[person.th].empty()) {

						P = p[person.th].front();
						p[person.th].pop();	
						q[P].push(Person(person.th, now + 1));
					}
					q[i].pop();
				} 
			}

//			printf ("%lld\n", now);
			ll min_n = INF;
			for (int i = 1; i <= m; i++) {
				if (!q[i].empty())
					min_n = min (min_n, q[i].top().t);
			}
		
			now++;
			if (min_n != INF)
				now = max (now, min_n);
			else
				break;

		}
		printf ("%lld\n", now);
	}
	return 0;
}

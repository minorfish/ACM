#include <cstdio>
#include <set>

using namespace std;

typedef long long ll;

multiset<int> s;
multiset<int>::iterator first, last;

int main () {

	int n, k, num;
	ll ans;
	while (scanf ("%d", &n) && n) {

		ans = 0;
		s.clear();
		while (n--) {
			
			scanf ("%d", &k);
			for (int i = 0; i < k; i++) {
				scanf ("%d", &num);
				s.insert (num);
			}
			first = s.begin();
			last = s.end();
			last--;
			
			ans += *last - *first; 
			s.erase(first);
			s.erase(last);
		}
		printf ("%lld\n", ans);
	}
	return 0;
}

#include <stdio.h>
#include <set>
using namespace std;

int n;
multiset<int> num;

long long solve () {

	long long sum = 0;
	multiset<int>::iterator it1, it2;
	long long temp;
	while (1) {

		if (num.size() == 1)
			break;
		it1 = num.begin();
		it2 = it1++;
		temp = *it1 + *it2;
		sum += temp;
		num.erase(it1);
		num.erase(it2);
		num.insert(temp);
	}
	return sum;
}

int main () {

	int temp;
	while (scanf ("%d", &n), n) {
		
		num.clear();
		for (int i = 0; i < n; i++) {

			scanf ("%lld", &temp);
			num.insert (temp);
		}

		printf ("%lld\n", solve());
	}
	return 0;
}

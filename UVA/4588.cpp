#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

const int N = 35;
long long  x, y;
typedef long long ll;
ll s1[N], s2[N], t[N];
void handle (ll y, ll * s) {
	
	for (int i = 0; i <= 32; i++) {
		
		s[i] = y / t[ i + 1]  * t[i];
		ll d = y % t[i + 1] - t[i];
		s[i] += d > 0 ? d: 0;
	}
}

ll solve () {

	ll ans = 0;
	ll a = 0;
	for (int i = 0; i < 32; i++) {
			
		a  = ( s1[i] - s2[i] + a ) / 2;
		ans += a;
	}
		
	while (a) {

		ans += a / 2;
		a = a / 2;
	}
	return ans;
}

int main () {
	
	t[0] = 1;
	for (int i = 1; i < N; i++)
		t[i] = 2 * t[i - 1];

	while (cin>>x>>y) {
	
		memset (s1, 0, sizeof (s1));
		memset (s2, 0, sizeof (s2));
		handle (y + 1, s1);
		handle (x, s2);
		cout<<solve()<<endl;
	}
	return 0;
}

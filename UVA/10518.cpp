#include <cstdio>
#include <cstring>

typedef long long ll;
const int maxn = 2;
int base;

struct Mat {

	int s[maxn][maxn];

	void init () {
		s[0][0] = s[0][1] = s[1][0] = 1;
		s[1][1] = 0;
	}

	Mat operator ^ (const Mat& t) const {

		Mat arr;	
		memset (arr.s, 0, sizeof(arr.s));

		for (int i = 0; i < maxn; i++)
			for (int j = 0; j < maxn; j++)
				for (int k = 0; k < maxn; k++) 
					arr.s[i][j] = (arr.s[i][j] + s[i][k] * t.s[k][j]) % base;
		return arr; 
	}
};

Mat Fmod (ll n, Mat a) {

	if (n == 1)
		return a; 
	
	Mat tmp = Fmod(n/2, a);
	tmp = tmp ^ tmp;
	if (n % 2 == 1)
		tmp = tmp ^ a;

/*	printf ("%lld\n", n);
	for (int i = 0; i < maxn; i++)
			printf ("%d %d\n", tmp.s[i][0], tmp.s[i][1]);*/
	return tmp;
}

int main () {
			
	ll n;
	int cas = 0;
	Mat a, ans;

	while (scanf ("%lld%d", &n, &base) && (n || base)) {
	
		a.init();
		if (n)
			ans = Fmod(n, a);	
		else
			ans = a;
		printf ("Case %d: %lld %d %d\n", ++cas, n, base, (ans.s[0][0] * 2 + base - 1) % base);
	}
	return 0;
}

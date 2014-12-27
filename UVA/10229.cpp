#include <cstdio>
#include <cstring>

typedef long long ll;
const int maxn = 2;
int N, M;

struct Mat {
	ll s[maxn][maxn];
	void init () {
		s[0][0] = s[0][1] = s[1][0] = 1;
		s[1][1] = 0;
	}
	
	Mat operator ^ (const Mat a) const{
		
		Mat ans;
		memset (ans.s, 0, sizeof (ans.s));

		for (int i = 0; i < maxn; i++)
			for (int j = 0; j < maxn; j++)
				for (int k = 0; k < maxn; k++) 
					ans.s[i][j] = (ans.s[i][j] + (s[i][k] * a.s[k][j]) % (1<<M)) % (1<<M);
		return ans;
	}
};

Mat FastMod (Mat a, int n) {
	
	if (n <= 1)
		return a; 
	Mat tmp = FastMod (a, n / 2);
	tmp = tmp ^ tmp;
	if (n % 2 == 1)	
		tmp = tmp ^ a;

	return tmp;
}

int main () {

	Mat a;
	a.init();
	while (scanf ("%d%d", &N, &M) != EOF) {
		
		if (!N) {
			printf ("0\n");
			continue;
		}
		Mat ans = FastMod (a, N);
		printf ("%lld\n", ans.s[1][0]);			
	}
	return 0;
}


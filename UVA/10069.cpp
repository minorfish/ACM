#include <cstdio>
#include <cstring>
#include <string>

const int N = 10005;
const int M = 105;
const int base = 100000;

char s1[N], s2[M];

int max (const int a, const int b) { return a > b ? a: b; }

struct bign {

	int len, s[30];
	bign () { memset (s, 0, sizeof (s));}
	bign (int num) { *this = num;}
	bign (const bign& b) { *this = b;}
	bign operator = (int num);
	bign operator + (const bign& b);
	bign operator + (const int b);
	bign operator += (const bign& b);
	void DelZore ();
} dp[M][N];

void bign::DelZore () {

	while (len >= 0 && s[len - 1] == 0) {
		len--;		
	}
	if (len == 0)
		len = 1;
}

bign bign::operator = (int num) {

	if (num == 0) {

		len = 1;
		s[0] = 0;
	} else {

		len = 0;
		while (num > 0) {

			s[len++] = num % base;
			num = num / base;
		}
	}
	return * this;
}

bign bign::operator + (const bign& b) {

	bign c;
	c.len = 0;
	for (int i = 0, g = 0; g || i < max(len, b.len); i++) {

		int x = g;
		if (i < len) x += s[i];
		if (i < b.len) x += b.s[i];
		c.s[c.len++] = x % base;
		g = x / base;
	}
	return c;
}

bign bign::operator + (const int b) {

	bign b1;
	b1 = b;
	return *this + b1;
}

bign bign::operator += (const bign& b) {

	*this = *this + b;
	return *this;
}

int main () {

	int t, l1, l2;
	scanf ("%d%*c", &t);
	while (t--) {
		
		gets(s1);
		gets(s2);
		l1 = strlen (s1);
		l2 = strlen (s2);
			
		if (l2 == 0) {
		
			printf ("0\n");
			continue;
		}

		for (int i = 0; i < l2; i++) {
			dp[i][l1] = 0;
		}

		for (int i = l1 - 1; i >= 0; i--) {
			if (s1[i] == s2[l2 - 1]) 
				dp[l2 - 1][i] = dp[l2 - 1][i + 1] + 1;
			else
				dp[l2 - 1][i] = dp[l2 - 1][i + 1];
		}

		for (int i = l2 - 2; i >= 0; i--)
			for (int j = l1 - 1; j >= 0; j--) {

				dp[i][j] = dp[i][j + 1];
				if (s2[i] == s1[j])
					dp[i][j] += dp[i + 1][j + 1];
			}

		dp[0][0].DelZore();
		printf ("%d", dp[0][0].s[dp[0][0].len - 1]);
		for (int i = dp[0][0].len - 2; i >= 0; i--)
			printf ("%05d", dp[0][0].s[i]);
		printf ("\n");
	}
	return 0;
}

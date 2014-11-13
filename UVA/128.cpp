#include <cstdio>
#include <cstring>

typedef long long ll;
const int maxn = 1<<10 + 5;
const int MOD = 34943;

char str[maxn];
char num[4];
int t[4];

void init () {

	t[0] = 1;
	for (int i = 1; i < 4; i++)
		t[i] = t[i - 1] * 16;
}

int solve () {

	int len = strlen(str);
	ll ans = 0;
	for (int i = 0; i < len; i++) 
		ans = (ans * 256 + (ll)str[i]) % MOD;
	
	ans = ((ans * 256) %MOD * 256) % MOD;
	return (MOD - (int)ans) % MOD; 
}

char change(int num) {

	if (num >= 0 && num <= 9)
		return num + '0';
	else 
		return 'A' + num - 10;
}

void trans (int ans) {

	for (int i = 3; i >= 0; i--) {
		
		if (ans >= t[i]) {
			num[i] = change(ans / t[i]);
			ans = ans % t[i];
		} else 
			num[i] = '0';
	}
}

int main () {

	init();
	while(gets(str) != NULL) {
		if (str[0] == '#')
			break;

		trans(solve());	
		printf ("%c%c %c%c\n", num[3], num[2], num[1], num[0]);
	}
}

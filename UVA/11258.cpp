#include <cstdio>
#include <cstring>

typedef long long ll;

const int N = 205;
const ll maxn = 2147483647;

ll dp[N][N];
char str[N];
char s1[N];
char s2[N];
int len;

ll Max (const ll a, const ll b) { return a > b ? a : b; }

ll MaxNum (int j, int l) {

	ll ans;
	memcpy (s1, str + j, sizeof (char) * (l + 1));
	s1[l + 1] = '\0';
	sscanf (s1, "%lld", &ans);
	/*if (ans > maxn) {

		memcpy (s1, str + j + 1, sizeof (str + j + 1));
		s1[j + l] += str[j];
		s1[j + l  + 1] = '\0';
		memcpy (s2, str + j, sizeof (str + j));
		s2[j + l - 1] += str[j + l];
		s2[j + l] = '\0';

		if (strcmp (s1, s2) > 0)
			sscanf (s1, "%lld", &ans);
		else
			sscanf (s2, "%lld", &ans);
	}*/
	if (ans > maxn)
		return -1;
	return ans;
}

void init () {

	for (int i = 0; i < len; i++) 
		dp[i][i] = str[i] - '0'; 				
}

int main () { 

	int t;
	ll ans;
	ll temp;
	scanf ("%d", &t);
	while (t--) {

		scanf ("%s", str);

		len = strlen (str);

		if (len < 10) 	
			sscanf (str, "%lld", &ans);
		else {

			init();
//			printf ("%lld\n", MaxNum (0, 9));
			for (int l = 1; l < len; l++)
				for (int i = 0; i + l < len; i++) {

					temp = -1;
					if (l < 10) 
						temp = MaxNum(i, l);
					for (int k = 0; k < l; k++) 			
						temp = Max (temp, dp[i][i + k] + dp[i + k + 1][i + l]);
					dp[i][i + l] = temp;
				}

			ans = dp[0][len - 1];
		}

		printf ("%lld\n", ans);
	}
	return 0;
}

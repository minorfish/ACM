#include <cstdio>
#include <cstring>

const int maxn = 1e4 + 5;
const char *s1 = "MAI MAI MAI!";
const char *s2 = "SONY DAFA IS GOOD!";

char str[maxn];
int len;
bool is_sony (int k) {

	if (k + 3 >= len)
		return false;
	if (str[k] == 'S' && str[k + 1] == 'o' && str[k + 2] == 'n' && str[k + 3] == 'y')
		return true;
	return false;
}

bool is_apple (int k) {

	if (k + 4 >= len)
		return false;
	if (str[k] == 'A' && str[k + 1] == 'p' && str[k + 2] == 'p' && str[k + 3] == 'l' && str[k + 4] == 'e')
		return true;
	return false;
}

bool is_iphone (int k) {

	if (k + 5 >= len)
		return false;
	if (str[k] == 'i' && str[k + 1] == 'P' && str[k + 2] == 'h' && str[k + 3] == 'o' && str[k + 4] == 'n' && str[k + 5] == 'e')
		return true;
	return false;
}

bool is_ipod (int k) {

	if (k + 3 >= len)
		return false;
	if (str[k] == 'i' && str[k + 1] == 'P' && str[k + 2] == 'o' && str[k + 3] == 'd')
		return true;
	return false;

}

bool is_ipad (int k) {

	if (str[k] == 'i' && str[k + 1] == 'P' && str[k + 2] == 'a' && str[k + 3] == 'd')
		return true;
	return false;
}

int main () {

	while (gets (str) != NULL) {

		len = strlen (str);
		for (int i = 0; i < len; i++) {
			
			if (str[i] == 'A' && is_apple(i)) {
					
				printf ("%s\n", s1);
				i += 4;
			} else if (str[i] == 'S' && is_sony(i)) {
				printf ("%s\n", s2);
				i += 3;
			} else if (str[i] == 'i') {

				if (is_iphone(i)) {
					printf ("%s\n", s1);
					i += 5;
				} else if (is_ipod(i)) {
					printf ("%s\n", s1);
					i += 3;
				} else if (is_ipad(i)) {
					printf ("%s\n", s1);
					i += 3;
				} 
			}
		}
	}
	return 0;
}

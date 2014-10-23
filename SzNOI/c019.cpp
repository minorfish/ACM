#include <cstdio>
#include <stack>
#include <cstring>

using namespace std;

const int maxn = 260;
char str[maxn];

stack<char> s;

bool solve () {

	int len = strlen (str);

	while (!s.empty()) {
		s.pop();
	}

	for (int i = 0; i < len; i++) {

		if (str[i] == '(' || str[i] == '[')
			s.push(str[i]);
		else {

			if (s.empty())
				return false;
			if (str[i] == ')' && s.top() != '(')
				return false;
			if (str[i] == ']' && s.top() != '[')
				return false;
			s.pop();
		}
	}

	if (s.empty())
		return true;
	return false;
}

int main () {

	while (scanf(str) != EOF) {

		printf ("%s\n", solve()? "OK": "Wrong");
	}
	return 0;
}

#include <iostream>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

string str;
list<string> l;
list<string>::iterator it;

void solve () {

	int n;
	string tmp;

	n = 0;
	for (int i = 0; i < str.length(); i++, n++)
		if (str[i] == ']' || str[i] == '[')
			break;
	
	tmp = "";
	tmp = str.substr (0, n);
	l.push_back(tmp);

	for (int i = 0; i < str.length(); i++) {
		
		if(str[i] == '[') {

			n = 0;
			tmp = "";
			for (int j = i + 1; j < str.length() && str[j] != ']' && str[j] != '['; j++)
				n++;
			tmp = str.substr(i + 1, n);
			l.push_front(tmp);
			i += n;

		} else if (str[i] == ']') {

			n = 0;
			tmp = "";
			for (int j = i + 1; j < str.length() && str[j] != '[' && str[j] != ']'; j++)
				n++;

			tmp = str.substr(i + 1, n);
			l.push_back(tmp);	
			i += n;
		} 
	}
}
/*
Print_it (const string &a) {

	cout<<a;	
}*/

int main () {
	
	while (cin>>str) {

		solve ();
	//	for_each (l.begin(), l.end(), Print_it);
		for (it = l.begin(); it != l.end(); it++)
			cout<<*it;
		cout<<endl;
		l.erase(l.begin(), l.end());
	}
	return 0;
}

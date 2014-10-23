#include <stdio.h>
#include <string.h>

const int N = 15;
char op[N];
char str[3 * N];
long long num[N];

long long caculate_max (int count) {

	long long temp[N];
	for (int i = 0; i < count; i++)
		temp[i] = num[i];

	for (int i = count - 2; i >= 0; i--)
		if (op[i] == '+') {

			temp[i] += temp[i + 1];
			temp[i + 1] = temp[i];
		}

	long long sum = temp[0];
	for (int i = 0; i < count - 1; i++) {

		if (op[i] == '*') 
			sum *= temp[i + 1];

	}
	return sum;
}

long long caculate_min (int count) {

	long long temp[N];
	for (int i = 0; i < count; i++)
		temp[i] = num[i];

	for (int i = count - 2; i >= 0; i--) {

		if (op[i] == '*')
			temp[i] = temp[i] * temp[i + 1];
	}

	long long sum = temp[0];
	for (int i = 0; i <= count - 2; i++) {

		if (op[i] == '+')
			sum += temp[i + 1];
	}

	return sum;
}

int init () {

	int t = 0;
	long long sum;
	scanf ("%s", str);
	for (int i = 0; i < strlen (str); i++) {

		if (str[i] == '+' || str[i] == '*')
			op[t++] = str[i];
		else {

			sum = 0;
			while (str[i] >= '0' && str[i] <= '9') {

				sum = sum * 10 + str[i] - '0';
				i++;
			}
			num[t] = sum;
			i--;
		}
	}
	return t + 1;
}

int main () {

	int t;
	int count;
	scanf ("%d", &t);
	while (t--) {

		count = init();	
		printf ("The maximum and minimum are %lld and %lld.\n", caculate_max(count), caculate_min(count));
		
	}
	return 0;
}

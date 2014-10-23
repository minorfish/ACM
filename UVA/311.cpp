#include <stdio.h>

const int N = 6;
int packets[N];
//补足2*2的空缺
void need () {

	if (packets[1] < 0) {

		packets[0] += packets[1] * 4;
		packets[1] = 0;
	}
}
//判断3*3的特殊的情况
void judge (int a, int b) {
	
	packets[1] -= a;
	packets[0] -= b;
	need();
}

int solve () {

	int sum = packets[5];
	int temp;
	for (int i = N - 2; i >= 1; i--) {

		if (i == 4) {
			
			sum += packets[i];
			packets[0] -= 11 * packets[i];

		} else if (i == 3) {
			
			sum += packets[i];
			packets[1] -= packets[i] * 5;
			need();

		} else if (i == 2) {

			sum += packets[i] / 4;
			packets[i] %= 4;
			if (packets[i] == 3) {

				sum++;
				judge(1,5); 
			} else if (packets[i] == 2) {

				sum++;
				judge(3,6);
			} else if (packets[i] == 1) {

				sum++;
				judge(5,7);
			}
		} else {
			
			temp = packets[1] * 4;
			if (packets[0] > 0)
				temp += packets[0];
			sum += (temp  + 35)/ 36;
		}
	}
	return sum;
}

int main () {

	int count;
	while (1) {

		count = 0;
		for (int i = 0; i < N; i++) {

			scanf ("%d", &packets[i]);
			count += packets[i];
		}
		if (!count)
			break;

		printf ("%d\n", solve());
	}
	return 0;
}

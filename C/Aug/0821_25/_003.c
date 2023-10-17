#include <stdio.h>
#include<math.h>

int main() {
	for (int i = 101; i < 200; i+=2) {
		int flag = 1;
		for (int j = 2; j <= sqrt(i); j++) { //注意小于等于，否则可能会出现非素数被判断为素数的情况。此种数为 i = sqrt(i)*sqrt(i);
			if (i % j == 0) {
				flag = 0;
				break;
			}
		}
		if (flag) printf("%d ", i);
	}
	return 0;
}
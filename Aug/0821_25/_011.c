#include <stdio.h>
#include<math.h>

void self_pow_num_me(int len){
	for (int i = pow(10,len-1); i < pow(10, len); i++) {
		int sum = 0;
		int tmp = i;
		for (int j = 0; j < len; j++) {
			sum += pow(tmp % 10, len);
			tmp /= 10;
		}
		if (sum == i) printf("%d ", i);
	}
}

int main() {
	for (int i = 1; i <= 5; i++) {
		self_pow_num_me(i);
	}
	return 0;
}
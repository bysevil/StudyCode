#include <stdio.h>

int main() {
	int num;
	scanf("%d", &num);

	int sum = 0;
	while (num) {
		sum += num % 10;
		num /= 10;
	}
	printf("%d", sum);
	return 0;
}
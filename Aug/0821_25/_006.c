#include <stdio.h>

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	if (a < b) {
		a = a ^ b;
		b = b ^ a;
		a = a ^ b;
	}
	int mul = a * b;
	int k;
	while (k = a % b) {
		a = b;
		b = k;
	}
	printf("%d", mul/b);
	return 0;
}
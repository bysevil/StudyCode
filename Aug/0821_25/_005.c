#include<stdio.h>

int main() {
	int a, b, c = 0;
	scanf("%d %d", &a, &b);
	if (a < b) {
		a = a ^ b;
		b = b ^ a;
		a = a ^ b;
	}
	while (c = a % b) {
		a = b;
		b = c;
	}
	printf("%d", b);
	return 0;
}
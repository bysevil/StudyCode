#include <stdio.h>

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if (a + b > c && a + c > b && b + c > a) {
		if (a == b && b == c) {
			printf("等边三角形");
		}
		else if (a == b || a == c || b == c) {
			printf("等腰三角形");
		}
		else {
			printf("普通三角形");
		}
	}
	else {
		printf("非三角形");
	}
	return 0;
}
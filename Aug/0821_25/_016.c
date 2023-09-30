#include <stdio.h>

int average(int a,int b) {
	if (a > b) return b + (a - b >> 1);
	else return a + (b - a >> 1);
}
int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", average(a, b));
	return 0;
}
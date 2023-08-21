#include <stdio.h>

int main() {
	int max, min;
	scanf("%d %d", &max);
	min = max;

	int tmp;
	while (scanf("%d", &tmp) != EOF) {
		if (tmp > max) max = tmp;
		if (tmp < min) min = tmp;
	}
	printf("%d", max - min);
	return 0;
}
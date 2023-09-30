#include<stdio.h>

int num9() {
	int sum = 1;
	for (int i = 10; i < 100; i++) {
		if (i % 10 == 9) sum++;
		if (i / 10 == 9) sum++;
	}
	printf("%d", sum);
	return 0;
}
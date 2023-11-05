#include<stdio.h>

int leapyear() {
	int num = 0;
	for (int i = 1000; i < 2000; i++) {
		if ((0 == i % 4 && i % 100 != 0) || 0 == i % 400) {
			if (num%15 == 0) printf("\n");
			printf("%d\t", i);
			num++;
		}
	}
	return 0;
}
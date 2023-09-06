#include<stdio.h>

int multiplicationtable(){
	for (int i = 9; i > 0; i--) {
		for (int j = 9; j >= i; j--) {
			printf("%d*%d=%d\t", i, j, i * j);
		}
		printf("\n");
	}
	return 0;
}
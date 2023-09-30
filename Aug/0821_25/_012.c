#include <stdio.h>

int main() {
	int len;
	scanf("%d", &len);
	int flag = 0;
	for (int i = 1; i > 0; flag?i--:i++) {
		if (i == len) flag = 1;
		for (int j = 0; j < len-i; j++) {
			printf(" ");
		}
		for (int j = 0; j < i*2-1; j++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
#include <stdio.h>

int main() {
	int total = 0;
	int empty = 0;
	scanf("%d", &total);
	int flag = 1;
	for (int i = total; i > 0; i--) {
		flag = !flag;
		empty++;
		if (flag) i++;
	}
	printf("%d", empty);
	return 0;
}
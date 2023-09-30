#include <stdio.h>

int main() {
	char suspect[] = { 'a','b','c','d' };
	for (int i = 0; i < sizeof(suspect); i++) {
		if ((suspect[i] != 'a') + (suspect[i] == 'c') + (suspect[i] == 'd') + (suspect[i] != 'd') == 3) {
			printf("%c", suspect[i]);
		}
	}
	return 0;
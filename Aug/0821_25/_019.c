#include<stdio.h>
#include<string.h>

void swap(char* a, char* b) {
	*a = *a ^ *b;
	*b = *b ^ *a;
	*a = *a ^ *b;
}

void reverse(char* str) {
	int right = strlen(str) - 1;
	int left = 0;
	while (left < right) {
		swap(str + left++, str + right--);
	}
}

int main() {
	char str[30];
	scanf("%[^\n]", str);
	reverse(str);
	printf("%s", str);
	return 0;
}
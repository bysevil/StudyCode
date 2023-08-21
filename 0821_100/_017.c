#include <stdio.h>

int me_strlen(char* str){
	int len = 0;
	while (str[len] != '\0') {
		len++;
	}
	return len;
}
int main() {
	char str[30];
	scanf("%[^\n]", str);
	printf("%d",me_strlen(str));
	return 0;
}
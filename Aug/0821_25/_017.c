#include <stdio.h>

int my_strlen(char* str){
	int len = 0;
	while (str[len++] != '\0') {}
	return len-1;
}
int main() {
	char str[30];
	scanf("%[^\n]", str);
	printf("%d",me_strlen(str));
	return 0;
}
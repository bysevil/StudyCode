#include <stdio.h>

int my_strlen(char* str){
	if (*str != '\0') return 1 + me_strlen(++str);
	else return 0;
}
int main() {
	char str[30];
	scanf("%[^\n]", str);
	printf("%d",me_strlen(str));
	return 0;
}
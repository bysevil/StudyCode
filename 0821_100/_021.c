#include <stdio.h>
#include<stdio.h>

int main() {
	char str[31];
	scanf("%s", str);

	int right = strlen(str) - 1;
	int left = 0;
	int flag = 1;
	while (left < right) {
		if (str[left] != str[right]) {
			flag = 0;
			break;
		}
		left++; right--;
	}
	
	if (flag) printf("%s是回文字符串", str);
	else printf("%s不是回文字符串", str);

	return 0;
}
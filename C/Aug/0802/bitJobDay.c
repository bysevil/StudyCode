/*写一个函数void StatCharCount(char str[])，该函数接收一个字符串作为参数，请统计该字符串中字母、数字、空格和其他字符的个数，在main函数调用该函数，分别打印字母、数字、空格 和 其他字符的出现次数。
返回提示：一个函数只能返回一个值，此处的统计结果有4个，因此返回结果可以使用全局变量带出来。*/
#include<stdio.h>
#include<string.h>

int numnum = 0, phanum = 0, blanknum = 0, othernum = 0;

void StatCharCount(char str[]) {
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (isdigit(str[i])) numnum++;
		else if (isalpha(str[i])) phanum++;
		else if (isblank(str[i])) blanknum++;
		else othernum++;
	}
}

int main() {
	char str[100];
	gets(str);
	StatCharCount(str);
	printf("%d %d %d %d", numnum, phanum, blanknum, othernum);
	return 0;
}

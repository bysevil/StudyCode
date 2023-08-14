/*https://www.nowcoder.com/questionTerminal/cc57022cb4194697ac30bcb566aeb47b?answerType=1&f=discussion*/
#include<stdio.h>
#include<string.h>

void swap(char* a, char* b) {
    *a = *a ^ *b;
    *b = *b ^ *a;
    *a = *a ^ *b;
}

void stropp(char* str) {
    char* ends = str + strlen(str) - 1;
    while (ends > str) {
        swap(ends, str);
        ends--;
        str++;
    }
}

int main() {
    char str[10000];
    gets(str);

    stropp(str);
    printf("%s", str);

    return 0;
}
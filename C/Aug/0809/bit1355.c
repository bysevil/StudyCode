#include<stdio.h>
#include<string.h>

void strleft(char* str, int k) {
    char temp[100];
    strncpy(temp, str, k);

    *(temp + k) = '\0';

    char* temp1 = str+k;

    while (*temp1 != '\0') {
        *(temp1 - k) = *temp1;
        temp1++;
    }

    *(temp1 - k) = '\0';

    strcat(str, temp);
}

int main() {
    int k;
    char str[100];

    scanf("%d\n%s",&k,str);

    strleft(str, k);

    printf("%d %s", k, str);

    return 0;
}
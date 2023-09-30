#include<stdio.h>

int my_strlen(char* starts){
    char* ends = starts;
    while(*ends != '\0'){
        ends++;
    }
    return ends-starts;
}

int main(){
    char arr[100];
    scanf("%s",arr);
    int len = my_strlen(arr);
    printf("%d ",len);
    return 0;
}

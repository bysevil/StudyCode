#include<stdio.h>

int rabbit(int month){
    if(month == 1) return 2;
    else if(month == 2) return 3;
    else return rabbit(month - 2) + rabbit(month-1);
}

int rabbitTwo()
{
    int month;
    scanf("%d",&month);
    int num[month] = {2,3};
    for(int i = 3;i<month;i++){
        num[i] = num[i-1]+num[i-2];
    }
    printf("%d",num[month-1]);
}

int rabbitThree() {
    int month;
    scanf("%d", &month);
    int little = 0, big = 1;
    for (int i = 0; i < month; i++) {
        big += little;
        little = big - little;
    }
    printf("%d", big+little);
    return 0;
}

int main(){
    int month;
    scanf("%d",&month);
    printf("%d",rabbit(month));
    return 0;
}
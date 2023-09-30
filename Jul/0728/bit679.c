#include<stdio.h>

int year(int y){
    if( y % 400 == 0 ||(y % 4 == 0 && y%100 != 0) )
        return 1;
    else
        return 0;
}

int main(){
    int y,flag = 0;
    scanf("%d",&y);
    flag = year(y);
    if(flag) printf("%d是闰年",y);
    else    printf("%d不是闰年",y);
}

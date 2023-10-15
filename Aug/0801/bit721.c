#include<stdio.h>
/*输出指定图案*/
int main(){
    int flag = 1;
    for(int i =0;i>=0;){
        for(int j =0;j<13;j++){
                if(j>6+i || j < 6-i) printf(" ");
                else printf("*");
        }
        if(i == 6) flag = 0;
        flag?i++:i--;
        printf("\n");
    }
    return 0;
}
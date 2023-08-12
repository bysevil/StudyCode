/*https://www.nowcoder.com/questionTerminal/9c3b8a8d9f1c4ae3b709d04625586225*/
#include <stdio.h>

int main() {
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF) { // 注意 while 处理多个 case
        // 64 位输出请用 printf("%lld") to 
        a ^= b;
        b = 0;
        while(a>0){
            if(a&1) b++;//这种方法按位判断是否为1。有多少位（最高位的1在第几位）就循环几次；
            a >>= 1;
            //a = a &(a-1);这种方法每次循环都消去一个1，有多少个1就循环几次。更优秀；
            //b++;
        }
        printf("%d",b);
    }
    return 0;
}
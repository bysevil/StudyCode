/*https://www.nowcoder.com/questionTerminal/9c3b8a8d9f1c4ae3b709d04625586225*/
#include <stdio.h>

int main() {
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF) { // 注意 while 处理多个 case
        // 64 位输出请用 printf("%lld") to 
        a ^= b;
        b = 0;
        while(a>0){
            if(a&1) b++;
            a >>= 1;
        }
        printf("%d",b);
    }
    return 0;
}
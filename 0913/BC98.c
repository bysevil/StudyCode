//https://www.nowcoder.com/practice/7bbcdd2177a445a9b66da79512b32dd7?tpId=107&&tqId=33379&rp=1&ru=/ta/beginner-programmers&qru=/ta/beginner-programmers/question-ranking

#include <stdio.h>

int main() {
    int N;
    scanf("%d",&N);
    int nums[N];
    for(int i = 0; i < N; i++) scanf("%d",nums+i);
    int flag;
    scanf("%d",&flag);

    for(int i = 0; i < N; i++){
        if(nums[i] != flag) printf("%d ",nums[i]);
    }
    return 0;
}
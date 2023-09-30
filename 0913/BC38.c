#include <stdio.h>
#include <math.h>

int main() {
    for(int i = 10000; i < 100000; i++){
        int sum = (i % 10) * (i / 10) + (i % 100) * (i / 100) + (i % 1000) * (i / 1000) + (i % 10000) * (i / 10000);
        if(sum == i) printf("%d ",i);
    }

    return 0;
}

/*
求出0～100000之间的所有“水仙花数”并输出。
“水仙花数”是指一个n位数，其各位数字的n次方之和确好等于该数本身，如:153＝1^3＋5^3＋3^3，则153是一个“水仙花数”。
*/
#include<math.h>

int main() {
    for (int i = 1; i < 100000; i++) {
        int num = i;
        int arr[5];
        int n = 0;
        while (num > 0) {
            arr[n++] = num % 10;
            num /= 10;
        }

        int j = n - 1;
        int sum = 0;
        while (j > -1) sum += pow(arr[j--], n);
        if (sum == i) printf("%d ", i);
    }
    return 0;
}
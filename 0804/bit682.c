/*编写一个函数实现n的k次方，使用递归实现。*/

int pow(int n, int k) {
    if (k) return n * pow(n, k - 1);
    else return 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d\n", pow(n, k));
    return 0;
}
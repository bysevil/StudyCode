//https://www.nowcoder.com/questionTerminal/8ee967e43c2c4ec193b040ea7fbb10b8
int NumberOf1(int n) {
    // write code here
    int num = 0;
    while(n!=0){
        num++;
        n = (n-1)&n;
    }
    return num;
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d",NumberOf1(n));
    return 0;
}
/*递归方式实现打印一个整数的每一位*/
int print(int n){
	printf("%d ",n%10);
	if(n>10)  print(n/10);
}

int main(){
    int n;
    scanf("%d",&n);
    print(n);
    return 0;
}
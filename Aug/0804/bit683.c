/*计算一个数的每位之和（递归实现）*/
int DigitSum(int n){
	if(n<10) return n;
	else return (n%10)+DigitSum(n/10);
}


int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",DigitSum(n));
    return 0;
}
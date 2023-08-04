/*递归和非递归分别实现求n的阶乘（不考虑溢出的问题）*/
int factorial(int n){
	if(n) return n+factorial(n-1);
	else return 0;
}

int factorialTWO(int n){
	int sum = n;
	for(int i = n-1;i>0;i--)  sum+=i;
	return sum; 
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",factorial(n));
    printf("%d\n",factorialTWO(n));
    return 0;
}
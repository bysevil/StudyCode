/*计算斐波那契数*/
int Fibonacci(int n){
	if(n < 3 ) return 1;
	else return Fibonacci(n-1)+Fibonacci(n-2);
}

int FibonacciTwo(int n){
	int a=1,b=1;
	if(n == 1) return a;
	else if(n == 2) return b;
	else{
		for(int i = n;i > 2;i--){
			a += b;
			b = a - b;
	    }
    }
	return a;
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",Fibonacci(n));
    printf("%d\n",FibonacciTwo(n));
    return 0;
}
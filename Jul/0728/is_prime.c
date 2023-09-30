#include <stdio.h>
#include <math.h>

int is_prime(int n){
    int i;
	int a = sqrt(n);
	for (i = 2; i <= a; i++) 
		if (n % i == 0) break;
	if (i > a) printf("%d ", n);
	return 0;
}

int main(){
    for(int i = 100;i<200;i++){
        is_prime(i);
    }
    return 0;
}
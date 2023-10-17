#include <stdio.h>
#include <math.h>

int primenumber(){
	int i,j,n;
	for (i = 100; i < 200; i++) {
		n = sqrt(i);
		for (j = 2; j <= n; j++) 
			if (i % j == 0) break;
		if (j > n) printf("%d ", i);
	}
	return 0;
}
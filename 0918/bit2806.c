#include<stdio.h>

int main(){
    int** p = (int*)malloc(3*sizeof(int*));
    for(int i = 0; i < 3; i++){
        p[i] = (int*)malloc(3*sizeof(int));
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            p[i][j] = i*j;
            printf("%d\t", p[i][j]);
        }
        printf("\n");
    }
}
#include<stdio.h>

int main(){
    FILE* fpr = fopen("data.txt","r");
    if(fpr == NULL){
        perror("Error read file:");
        return -1;
    }

    FILE* fpw = fopen("data_copy.txt","w");
    if(fpw == NULL){
        perror("Error write file:");
        return -1;
    }
    
    char ch;
    while((ch = fgetc(fpr) )!= EOF) fputc(ch, fpw);
    
    fclose(fpw);
    fclose(fpr);

    return 0;
}
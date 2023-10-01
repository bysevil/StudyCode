#include<stdio.h>
#include<stdlib.h>

int main(void){
    FILE* fp = fopen("test.txt", "w+");
    if(fp == NULL){
        perror("fopen error");
        return -1;
    }

    fprintf(fp, "Hello,World!\n");
    fputs("Hello,bit!\n",fp);
    fputc('a',fp);

    rewind(fp);
    
    char str1[20],str2[20];
    char ch = 'a';
    
    fscanf(fp, "%s\n", str1);
    fgets(str2,20,fp);
    ch = fgetc(fp);

    fclose(fp);
    fp = NULL;

    printf("%s\n%s%c\n", str1,str2,ch);

    return 0;
}
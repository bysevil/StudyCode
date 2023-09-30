#include<stdio.h>
#include<stdlib.h>

int cmp_int(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int cmp_char(const void* a, const void* b) {
    return *(char*)a - *(char*)b;
}

int main() {
    int arrint[] = { 3,6,4,8,3,5,1 };
    char arrchar[] = { 'a','c','d','b' };
    int lenint = sizeof(arrint) / sizeof(arrint[0]);
    int lenchar = sizeof(arrchar) / sizeof(arrchar[0]);
    qsort(arrint, lenint, sizeof(int), cmp_int);
    qsort(arrchar, lenchar, sizeof(char), cmp_char);
    for (int i = 0; i < lenint; i++) printf("%d ", arrint[i]);
    printf("\n");
    for (int i = 0; i < lenchar; i++) printf("%c ", arrchar[i]);
    printf("\n");
}
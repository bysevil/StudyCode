#include<stdio.h>

void print(void* arr, size_t len, size_t sz) {
    switch (sz)
    {
    case sizeof(int) :
        for (int i = 0; i < len; i++) {
            printf("%d ", *((int*)arr + i));
        }
        break;
    case sizeof(char):
        for (int i = 0; i < len; i++) {
            printf("%c ", *((char*)arr + i));
        }
        break;
    }
    printf("\n");
}

int cmp(void* a, void* b, size_t sz) {
    switch (sz)
    {
    case sizeof(int) :
        return *(int*)a - *(int*)b;
        break;
    case sizeof(char) :
        return *(char*)a - *(char*)b;
        break;
    }
}

void swap(void* a, void* b, size_t sz) {
    for (int i = 0; i < sz; i++) {
        *((char*)a + i) = *((char*)a + i) ^ *((char*)b + i);
        *((char*)b + i) = *((char*)b + i) ^ *((char*)a + i);
        *((char*)a + i) = *((char*)a + i) ^ *((char*)b + i);
    }     
}

void BubbleSort(void* arr, size_t len, size_t sz, int(*p_cmp)(void*, void*,size_t)) {
    for (int i = len-1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (p_cmp((char*)arr + j * sz, (char*)arr + (j + 1) * sz,sz) > 0) {
                swap((char*)arr + j * sz, (char*)arr + (j + 1) * sz,sz);
            }
        }
    }
}

int main() {
    int arr_int[] = { 1,6,4,5,4,7,3 };
    char arr_ch[] = { 'a','r','g','f','h' };

    int(*p_cmp)(void*, void*,size_t) = cmp;

    int len_int = sizeof(arr_int) / sizeof(arr_int[0]);
    int len_ch = sizeof(arr_ch) / sizeof(arr_ch[0]);

    BubbleSort(arr_int,len_int,sizeof(int),p_cmp);
    BubbleSort(arr_ch, len_ch,sizeof(char),p_cmp);

    print(arr_int, len_int, sizeof(int));
    print(arr_ch, len_ch,sizeof(char));
    return 0;
}
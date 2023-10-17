 #include<stdio.h>

int bin_search(int* arr, int left, int right, int key) {
    while (left <= right) {
        int flag = left + (right - left >> 2);
        if (arr[flag] == key) return flag;
        else if (arr[flag] < key)  left = flag+1;
        else right = flag-1;
    }
    return -1;
}

int main() {
    int arr[] = { 0,1,2,3,4,5,6,7,8,9,10 };
    int right = sizeof(arr) / sizeof(*arr) - 1;
    int kay;
    scanf("%d", &kay);
    printf("%d", bin_search(arr, 0, right, kay));
    return 0;
}
/*在一个整型数组中，只有一个数字出现一次，其他数组都是成对出现的，请找出那个只出现一次的数字。
例如：
数组中有：1 2 3 4 5 1 2 3 4，只有5出现一次，其他数字都出现2次，找出5*/

int main(){
    int arr[] = {1,2,3,4,5,1,2,3,4};
    int len = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0;i<len;i++){
        int flag = 1;
        for(int j = i+1;j<len;j++){
            if( arr[j] == arr[i] ) {
                flag = 0;
                break;
            }
        }
        if(flag){
            printf("%d",arr[i]);
            break;
        }
    }
    return 0;
}
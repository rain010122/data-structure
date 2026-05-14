// 线性表查找-折半查找（二分查找）
// 依赖有序顺序表结构
#include<stdio.h>

int binary_search(int * data, int len, int value){
    int low = 0;
    int high = len - 1;
    int mid;
    while(low <= high){
        mid = (low + high)/2;
        if (value > data[mid]){
            low = mid + 1;
        }
        else if (value < data[mid]){
            high = mid - 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int main(){
    int arr[] = {2,15,22,38,56,58,66,88,89,90};
    int len = sizeof(arr)/sizeof(arr[0]);
    // printf("%d\n",len);
    int pos = binary_search(arr,len,66);
    printf("%d\n",pos);
    return 0;
}
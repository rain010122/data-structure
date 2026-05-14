// 线性表查找-顺序查找
#include<stdio.h>

int search(int * data, int len, int value){
    for (int i = 0; i<len; i++){
        if (data[i] == value){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[] = {14,345,56,35,4,45,12};
    int len = sizeof(arr)/sizeof(arr[0]);
    int pos = search(arr,len,45);
    printf("%d\n",pos);
    return 0;
}
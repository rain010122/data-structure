// 冒泡排序
#include<stdio.h>

void swap(int* data, int m, int n){
    int temp = data[m];
    data[m] = data[n];
    data[n] = temp;
}

void bubblesort(int *data, int len){
    for (int i = 0; i<len; i++){
        int swapped = 0;
        for (int j = 0; j<len-i-1; j++){
            if (data[j] > data[j+1]){
                swap(data, j, j+1);
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

int main(){
    int data[] = {47,35,60,94,7,15,28};
    int len = sizeof(data)/sizeof(data[0]);
    bubblesort(data,len);
    for (int i = 0; i<len; i++){
        printf("%d\n",data[i]);
    }
    return 0;
}
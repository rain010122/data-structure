// 简单选择排序
#include<stdio.h>

void swap(int *data, int m, int n){
    int temp = data[m];
    data[m] = data[n];
    data[n] = temp;
}

void selectsort(int *data, int len){
    int min;

    for(int i = 0; i<len; i++){
        min = i;
        for (int j = i; j<len; j++){
            if (data[min] > data[j]){
                min = j;
            }
        }
        if(i!=min){
                swap(data,i,min);
        }
    }
}

int main(){
    int data[] = {47,35,60,94,7,15,28};
    int len = sizeof(data)/sizeof(data[0]);
    printf("%d\n",len);
    selectsort(data,len);
    for (int i = 0; i<len; i++){
        printf("%d ",data[i]);
    }
    return 0;
}
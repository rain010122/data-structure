// 插入排序
#include<stdio.h>

void insertsort(int *data, int len){
    int key; //待插入元素存放
    for (int i = 1; i<len; i++){
        key = data[i];
        int j = i-1; //向前比较
        while(j>=0 && data[j]>key){
            data[j+1] = data[j];
            j--; //不断向前比较
        }

        data[j+1] = key;
    }
}

int main(){
    int data[] = {47,35,60,94,7,15,28};
    int len = sizeof(data)/sizeof(data[0]);
    insertsort(data,len);
    for (int i = 0; i<len; i++){
        printf("%d\n",data[i]);
    }
    return 0;
}
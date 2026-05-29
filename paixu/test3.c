// 折半插入排序
#include<stdio.h>

void binaryinsertsort(int *data, int len){
    int low, high, mid;
    int key;

    // 从第二个开始遍历
    for (int i = 1; i<len; i++){
        key = data[i];
        low = 0;
        high = i-1;

        // 
        while (low <= high){
            mid = (low+high)/2;
            if (data[mid]>key){
                high = mid-1;
            }
            else{
                low = mid+1;
            }

        }

        // 从后往前依次将大于key的元素后移
        int j = i-1;
        while(j>=low){
            data[j+1] = data[j];
            j--;
        }

        // 插入key到正确位置
        data[low] = key;

    }
}

int main(){
    int data[] = {47,35,60,94,7,15,28};
    int len = sizeof(data)/sizeof(data[0]);
    binaryinsertsort(data,len);
    for (int i = 0; i<len; i++){
        printf("%d\n",data[i]);
    }
    return 0;
}
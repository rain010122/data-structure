#include <stdio.h>
// 实现m n的交换
// 指针传入的一定是地址
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    printf("a = %d, b = %d\n", *a, *b);
}

int main(){
    int m = 5;
    int n = 10;
    swap(&m, &n);
    printf("m = %d, n = %d\n", m, n);
    return 0;
}
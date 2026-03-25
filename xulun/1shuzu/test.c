#include<stdio.h>
// 指针位置
int main(){
    int a[] = {1, 2, 3, 4, 5};
    printf("%p\n", &a[1]);
    printf("%p\n", &a[0]);
}
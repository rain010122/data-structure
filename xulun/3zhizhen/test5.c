#include<stdio.h>
// 指针与数组
int main(){
    int a[] = {1, 2, 3, 4, 5};
    int *p = a; // 数组名就是数组首元素的地址

    printf("%p\n", a);
    printf("%p\n",p);
    printf("%p\n", &p);
    printf("%d\n", *p);
    return 0;
}
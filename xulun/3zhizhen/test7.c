#include<stdio.h>
// 给指针加一个整数，其实是加的是整数与指针数据类型对应字节数的乘积
int main(){
    int a = 5;
    int *p = &a; // 指针变量存储的是地址
    printf("%p\n", p);
    // printf("%p\n", &p);
    p++;
    printf("%p\n", p);
    return 0;
}
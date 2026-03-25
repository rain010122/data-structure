#include <stdio.h>
// 通过指针修改变量的值
int main(){
    int a = 5;
    int *p = &a;
    printf("%d\n", *p);
    *p = 10;
    printf("%d\n", a);
}
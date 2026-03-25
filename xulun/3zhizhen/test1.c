#include <stdio.h>
int main() {
    int a = 5;
    int *p = &a;
    printf("a指向的地址为%p, a指向的值为%d\n", &a, a);
    printf("p本身的地址为%p, p储存的地址为%p, p指向的值为%d\n", &p, p, *p);
    // 定义时，*p表示p是指针变量，指向一个int类型的变量a
    // 使用时，*p表示p指向的值a
}
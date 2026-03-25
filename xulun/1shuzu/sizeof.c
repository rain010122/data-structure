#include <stdio.h>
// 内存中占多少字节
int main() {
    int a = 6;
    printf("%zu\n", sizeof(a));
    printf("%zu\n", sizeof(int));
    printf("%zu\n", sizeof(3.14));
}
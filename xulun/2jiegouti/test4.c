#include <stdio.h>
// typedef 数据类型 别名
typedef int tp1;
typedef char tp2;

int main(){
    tp1 a = 5;
    tp2 b = 'o';
    printf("%d\n", a);
    printf("%c\n", b);
    return 0;
}
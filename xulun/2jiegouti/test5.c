#include <stdio.h>
// 使用别名定义结构体，在声明的时候无需加struct
typedef struct
{
    int x;
    int y;
}po;

int main(){
    po p;
    p.x = 5;
    p.y = 10;
    printf("%d\n", p.x);
    printf("%d\n", p.y);
    return 0;
}
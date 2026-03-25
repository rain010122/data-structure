#include<stdio.h>
// 结构体是一个或多个变量的集合，可以是不同类型
struct point{
    int x;
    int y;
};

int main(){
    struct point p;
    p.x = 5;
    p.y = 10;
    printf("%d\n", p.x);
    printf("%d\n", p.y);
    return 0;
}
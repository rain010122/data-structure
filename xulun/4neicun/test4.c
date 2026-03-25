#include<stdio.h>
#include<stdlib.h>
// 动态内存-结构体
// 结构体成员访问用.指针要用->

typedef struct
{
    int x;
    int y;
}po;

int main(){
    po *p;
    p = (po*)malloc(sizeof(po));
    p->x = 5;
    p->y = 10;
    printf("%d\n", p->x);
    printf("%d\n", p->y);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
// 动态内存分配（堆内存可控）
int main(){
    int *p;
    p = (int*)malloc(sizeof(int));
    *p = 15;
    printf("%d\n", *p);
    free(p);
    return 0;
}
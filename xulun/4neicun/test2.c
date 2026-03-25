#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 动态内存分配（堆内存可控）,字符串
int main(){
    char *s;
    s = (char*)malloc(10);
    strcpy(s, "Hello");  //赋值字符串类型变量
    printf("%s\n", s);
    free(s);
    return 0;
}
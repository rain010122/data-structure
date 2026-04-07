// 枚举1
#include<stdio.h>

enum weekday{
    mon, tue,wed, thu, fri, sat, sun
};

int main(){
    enum weekday a;
    a = mon;
    enum weekday b;
    b = tue;
    printf("%d\n",a);
    printf("%d",b);
    return 0;
}
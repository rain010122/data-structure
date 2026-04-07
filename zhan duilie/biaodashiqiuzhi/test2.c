// 枚举2
#include<stdio.h>

typedef enum{
    mon,tue,wed,thu,fri,sat,sun
}weekday;

int main(){
    weekday a = mon;
    weekday b = sun;
    printf("%d\n",a);
    printf("%d\n",b);
    return 0;
}
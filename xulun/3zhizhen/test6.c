#include <stdio.h>

int main(){
    int a[] = {15,33,65,89,45};
    int *p = a; // 数组名就是数组首元素的地址
    for(int i = 0; i < sizeof(a)/sizeof(a[0]); i++){
        printf("%d\n", a[i]);
    }
    for(int i = 0; i < sizeof(a)/sizeof(a[0]); i++){
        printf("%d\n",*(p+i));
    }
    return 0;
}
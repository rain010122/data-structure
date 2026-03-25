#include <stdio.h>
// int main(){
//     int a[] = {1, 2, 3, 4, 5};
//     printf("%zu\n", sizeof(a));
//     printf("%zu\n", sizeof(a[0]));
//     int len = sizeof(a) / sizeof(a[0]);
//     printf("%d\n", len);
// }

// sizeof用于判断数组长度
int main(){
    int a[] = {1, 2, 3, 4, 5};
    for (int i =0; i < sizeof(a)/sizeof(a[0]); i++)
    {
        printf("%d\n", a[i]);
    }
}
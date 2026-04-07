// 递归求和
#include<stdio.h>

// int fun(int n){
//     int sum = 0;
//     for (int i = 1; i<n; i++){
//         sum+=i;
//     }
//     return sum;
// }

int fun(int n){
    if (n == 1) return 1;
    else return fun(n-1) + n;
}

int main(){
    printf("%d\n",fun(4));
    return 0;
}
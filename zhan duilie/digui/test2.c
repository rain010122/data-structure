// 斐波那契数列
#include<stdio.h>

// int fib(int n){
//     int a1 = 1;
//     int a2 = 1;
//     int an;
//     for (int i = 3; i<=n; i++){
//         an = a1+a2;
//         a1 = a2;
//         a2 = an;
//     }
//     return an;
// }

int fib(int n){
    if (n == 1 || n==2) return 1;
    else return fib(n-1)+fib(n-2);
}

int main(){
    printf("%d\n",fib(5));
    return 0;
}
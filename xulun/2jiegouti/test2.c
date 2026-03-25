#include<stdio.h>
struct point{
    int x;
    int y;
};

struct point createPoint(int x,int y){
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

int main(){
    struct point p = createPoint(5,10);
    printf("%d\n", p.x);
    printf("%d\n", p.y);
    return 0;
}
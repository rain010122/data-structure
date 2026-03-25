// 顺序表初始化
#include<stdio.h>
#define MAXSIZE 100
typedef int elemtype;

typedef struct{
    elemtype data[MAXSIZE];
    int length;
}seqlist;

void initlist(seqlist *L)
{
    L->length = 0;
}

int main(){
    seqlist list;
    initlist(&list);
    printf("初始化成功，长度占用%d\n",list.length);
    printf("占用内存%zu字节\n", sizeof(list.data));
    return 0;
}
// 顺序表-在尾部添加元素
#include<stdio.h>

#define MAXSIZE 100

typedef int elemtype;

typedef struct{
    elemtype data[MAXSIZE];
    int length;
}seqlist;

void initlist(seqlist *L){
    L->length = 0;
}


int appendelem(seqlist *L, elemtype e){
    if (L->length >= MAXSIZE){
        printf("已满\n");
        return 0;
    }
    L->data[L->length] = e;
    L->length ++;
    return 1;
}

int main(){
    seqlist list;
    initlist(&list);
    printf("长度%d\n", list.length);
    printf("内存占用%zu\n", sizeof(list.data));
    appendelem(&list, 88);
    return 0;
}

// 验证顺序表添加-遍历
// elemtype变量只用于确定数据类型
#include<stdio.h>

#define MAXSIZE 100

typedef int elemtype;

typedef struct{
    elemtype data[MAXSIZE];
    int length;
}seqlist;

// 初始化
void initlist(seqlist *L){
    L->length = 0;
};

// 添加
int appendelem(seqlist *L, elemtype e){
    if (L->length >= MAXSIZE){
        printf("已满\n");
        return 0;
    }
    L->data[L->length] = e;
    L->length ++;
    return 1;
}

// 验证
void listelem(seqlist *L){
    for(int i = 0; i < L->length; i++){
        printf("%d ",L->data[i]);
    }
    printf("\n");
}

int main(){
    seqlist list;
    initlist(&list);
    printf("长度%d\n", list.length);
    printf("内存占用%zu\n", sizeof(list.data));
    appendelem(&list, 88);
    appendelem(&list, 12);
    listelem(&list);
    printf("长度%d\n", list.length);
    printf("内存占用%zu\n", sizeof(list.data));
    return 0;
}


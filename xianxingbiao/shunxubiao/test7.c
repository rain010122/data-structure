// 顺序表-动态分配内存地址初始化
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef int elemtype;
typedef struct{
    elemtype *data;
    int length;
}seqlist;

seqlist* initlist(){
    seqlist *L = (seqlist*)malloc(sizeof(seqlist));
    L->data = (elemtype*)malloc(sizeof(elemtype) * MAXSIZE);
    L->length = 0;
    return L;
}


int appendelem(seqlist *L, elemtype e){
    if (L->length >= MAXSIZE){
        printf("已满\n");
        return 0;
    }
    L->data[L->length] = e;
    L->length++;
    return 1;
}

void listelem(seqlist *L){
    for (int i = 0; i < L->length; i++){
        printf("%d ",L->data[i]);
    }
    printf("\n");
}

int insertelem(seqlist *L, int pos, elemtype e){
    if (L->length >= MAXSIZE){
        printf("已满\n");
        return 0;
    }
    if (pos < 1 || pos > L->length + 1){
        printf("插入位置有误\n");
        return 0;
    }
    for (int i = L->length - 1; i >= pos - 1; i--){
        L->data[i+1] = L->data[i];
    }
    L->data[pos - 1] = e;
    L->length++;
    return 1;
}

int delelem(seqlist *L, int pos, elemtype *e){
    if (L->length == 0){
        printf("空表\n");
        return 0;
    }
    if (pos < 1 || pos > L->length){
        printf("删除位置有误\n");
        return 0;
    }
    *e = L->data[pos-1];
    for (int i = pos; i < L->length; i++){
        L->data[i-1] = L->data[i];
    }
    L->length--;
    return 1;
}

int findelem(seqlist *L, elemtype e){
    if (L->length == 0){
        printf("空表\n");
        return 0;
    }
    for (int i = 0; i < L->length; i++){
        if (L->data[i] == e){
            return i+1;
        }
    }
    return 0;
}

int main(){
    seqlist *L = initlist();
    appendelem(L,1);
    appendelem(L,2);
    appendelem(L,3);
    appendelem(L,4);
    appendelem(L,5);
    appendelem(L,6);
    appendelem(L,7);
    appendelem(L,8);
    listelem(L);

    insertelem(L, 4, 999);
    listelem(L);

    elemtype deldata;
    delelem(L, 9, &deldata);
    printf("被删的%d\n",deldata);
    listelem(L);

    printf("查找的元素位置在%d\n",findelem(L,999));

    return 0;

}
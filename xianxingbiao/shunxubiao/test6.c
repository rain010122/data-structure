// 顺序表-查找
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
    seqlist list;
    initlist(&list);
    appendelem(&list,1);
    appendelem(&list,2);
    appendelem(&list,3);
    appendelem(&list,4);
    appendelem(&list,5);
    appendelem(&list,6);
    appendelem(&list,7);
    appendelem(&list,8);
    listelem(&list);

    insertelem(&list, 4, 999);
    listelem(&list);

    elemtype deldata;
    delelem(&list, 9, &deldata);
    printf("被删的%d\n",deldata);
    listelem(&list);

    printf("查找的元素位置在%d\n",findelem(&list,999));

    return 0;

}

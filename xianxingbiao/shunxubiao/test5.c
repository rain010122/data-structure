// 顺序表-删除元素
#include<stdio.h>

#define MAXSIZE 100

typedef int elemtype;

typedef struct{
    elemtype data[MAXSIZE];
    int length;
}seqlist;

void initlist(seqlist *L){
    L -> length = 0;
}

int appendelem(seqlist *L, elemtype e){
    if(L->length >= MAXSIZE){
        printf("已满\n");
        return 0;
    }
    L->data[L->length] = e;
    L->length++;
    return 1;
}

void listelem(seqlist *L){
    for(int i = 0; i < L->length; i++){
        printf("%d ",L->data[i]);
    }
    printf("\n");
}

int insertelem(seqlist *L, int pos, elemtype e){
    if(pos < 1 || pos >L->length + 1){
        // 允许在表后 length + 1 添加
        printf("插入位置错误\n");
        return 0;
    }
    if(L->length >= MAXSIZE){
        printf("已满\n");
        return 0;
    }
    // 插入从后开始移动，i从最后一个值开始移动
    for (int i = L->length - 1; i >= pos - 1; i--){
        L->data[i+1] = L->data[i];
    }
    L->data[pos - 1] = e;
    L->length++;
    return 1;
}

// 删除
int delelem(seqlist *L, int pos, elemtype *e){
    if (L->length == 0){
        printf("空表\n");
        return 0;
    }
    if (pos < 1 || pos > L->length){
        printf("删除位置有误\n");
        return 0;
    }
    *e = L->data[pos - 1];
    // 删除从被删位置开始移动，i从pos - 1开始移动
    for (int i = pos - 1; i < L->length - 1; i++){
                    // 此处i < L->length - 1 不能= 会越界访问垃圾值
        L->data[i] = L->data[i+1];
    }
    L->length--;
    return 1;
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

    insertelem(&list, 3, 999);
    listelem(&list);

    elemtype deldata;
    delelem(&list, 9, &deldata);
    listelem(&list);
    return 0;
}
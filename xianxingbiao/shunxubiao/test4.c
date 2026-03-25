// 顺序表-插入元素
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
    if(L->length > MAXSIZE){
        printf("已满\n");
        return 0;
    }
    L->data[L->length] = e;
    L->length ++;
    return 1;
}

void listelem(seqlist *L){
    for(int i = 0; i < L->length; i++){
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

// 插入
int insertelem(seqlist *L, int pos, elemtype e){
    if(L->length >= MAXSIZE){
        printf("已满\n");
        return 0;
    }
    if(pos < 1 || pos > L->length){
        printf("插入位置错误\n");
        return 0;
    }
    if (pos <= L->length){
        for(int i = L->length-1; i >= pos - 1; i--){
            L->data[i+1] = L->data[i];
        }
        L->data[pos-1] = e;
        L->length++;
    }
    return 1;
}

int main(){
    seqlist list;
    initlist(&list);
    printf("%d\n", list.length);
    printf("%zu\n", sizeof(list.data));
    appendelem(&list,22);
    appendelem(&list,33);
    appendelem(&list,55);
    appendelem(&list,88);
    appendelem(&list,99);
    appendelem(&list,100);
    printf("%d\n", list.length);
    printf("%zu\n", sizeof(list.data));
    listelem(&list);
    insertelem(&list, 5, 44);
    listelem(&list);
    return 0;
}

// 插入最好时间复杂度O(1)，最坏O(n)
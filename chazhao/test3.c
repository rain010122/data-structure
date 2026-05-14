// 二叉排序树-查找
#include<stdio.h>
#include<stdlib.h>

typedef int elemtype;
typedef struct treenode{
    elemtype data;
    struct treenode *lchild;
    struct treenode *rchild;
}treenode;

typedef treenode* bitree;

int treearr[] = {70,55,49,30,-1,39,-1,-1,53,-1,-1,-1,80,75,-1,-1,98,95,-1,-1,-1};
int idx = 0;

void createtree(bitree * T){
    elemtype num;
    num = treearr[idx++];

    if(num == -1){
        *T = NULL;
    }
    else{
        *T = (bitree)malloc(sizeof(treenode));
        (*T)->data = num;
        createtree(&(*T)->lchild);
        createtree(&(*T)->rchild);
    }
}

// 先序遍历打印二叉树
void preorder(bitree T){
    if(T ==NULL){
        return;
    }
    printf("%d ",T->data);
    preorder(T->lchild);
    preorder(T->rchild);
}

int search_bst(bitree T, int value, bitree parent, bitree *pos){
    if (T == NULL){
        *pos = parent;
        return 0;
    }
    if (T->data == value){
        *pos = T;
        return 1;
    }
    if(T->data > value){
        return search_bst(T->lchild,value,T,pos);
    }
    else{
        return search_bst(T->rchild,value,T,pos);
    }
}


int main(){
    bitree T;
    createtree(&T);

    bitree searchT;
    search_bst(T,53,NULL,&searchT);

    preorder(T);
    printf("\n");
    printf("%d\n",searchT->data);
    return 0;
}
// 二叉排序树-插入
#include<stdio.h>
#include<stdlib.h>

typedef int elemtype;
typedef struct treenode{
    elemtype data;
    struct treenode *lchild;
    struct treenode *rchild;
}treenode;

typedef treenode *bitree;
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

int insert_bst(bitree *T, int value){
    bitree parent, pos;
    bitree curr;
    
    // 查找插入位置
    int status = search_bst(*T, value, NULL, &pos);
    if (status == 0){
        // 未找到则创建新节点
        curr = (bitree)malloc(sizeof(treenode));
        curr->data = value;
        curr->lchild = NULL;
        curr->rchild = NULL;
        // 如果树为空，新节点作为根节点
        if (pos == NULL){
            *T = curr;
        }
        // insert 左子节点
        else if (value < pos->data){
            pos->lchild = curr;
        }
        // insert 右子节点
        else{
            pos->rchild = curr;
        }
        return 1;
    }
    else{
        // 若已存在。不插入
        return 0;
    }
}

int main(){
    int i = 0;
    bitree T = NULL;

    int treearr[] = {70,55,49,30,39,53,80,75,98,95};

    for (int i = 0; i<10; i++){
        insert_bst(&T,treearr[i]);
    }
    preorder(T);
    printf("\n");

    insert_bst(&T,99);

    preorder(T);
    printf("\n");

    return 0;
}
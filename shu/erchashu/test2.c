// 线索二叉树-储存结构-中序遍历线索化

#include<stdio.h>
#include<stdlib.h>

typedef char elemtype;
typedef struct threadnode{
    elemtype data;
    struct threadnode *lchild;
    struct threadnode *rchild;
    int ltag;
    int rtag;
}threadnode;

typedef threadnode* threadtree;

char str[] = "ABDH#K###E##CFI###G#J##";
int idx = 0;

// 存放上一个访问的结点
threadtree prev;

void createtree(threadtree *T){
    elemtype ch;
    ch = str[idx++];
    if (ch == '#'){
        *T = NULL;    //解指针
    }
    else{
        *T = (threadtree)malloc(sizeof(threadnode));
        (*T)->data = ch;

        createtree(&(*T)->lchild);
        if ((*T)->lchild != NULL){
            (*T)->ltag = 0;
        }

        createtree(&(*T)->rchild);
        if ((*T)->rchild != NULL){
            (*T)->rtag =0;
        }
    }
}

void threading(threadtree T){
    if (T != NULL){
        threading(T->lchild);
        if (T->lchild == NULL){
            T->ltag = 1;
            T->lchild = prev;
        }
        if (prev->rchild == NULL){
            prev->rtag = 1;
            prev->rchild = T;
        }
        prev = T;
        threading(T->rchild);
    }
}

// 线索化
// 1. 头节点的lchild指向二叉树的根
// 2. 头结点的rchild指向遍历的最后一个结点
// 3. 第一个结点的lchild指向头结点
// 4. 最后一个结点的rchild指向头结点
void inorderthreading(threadtree *head, threadtree T){
    *head = (threadtree)malloc(sizeof(threadnode));
    (*head)->ltag = 0;
    (*head)->rtag = 1;
    (*head)->rchild = (*head);

    if(T == NULL){
        (*head)->lchild = *head;
    }
    else{
        (*head)->lchild = T;
        prev = (*head);

        threading(T);

        // 最后一个结点线索化
        prev->rchild = *head;
        prev->rtag = 1;

        // 头结点右孩子指向最后一个结点
        (*head)->rchild = prev;
    }
}

void inorder(threadtree T){
    threadtree curr;
    curr = T->lchild;

    while (curr != T){
        while (curr->ltag == 0){
            curr = curr->lchild;
        }
    
        printf("%c",curr->data);

        while(curr->rtag == 1 && curr->rchild != T){
            curr = curr->rchild;
            printf("%c", curr->data);
        }
        curr = curr->rchild;
    }
    printf("\n");

}

int main(){
    threadtree head;
    threadtree T;
    createtree(&T);
    // 线索化
    inorderthreading(&head,T);
    // 基于线索遍历
    inorder(head);
    return 0;
}
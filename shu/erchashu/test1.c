// 二叉树的储存结构-链式结构
#include<stdio.h>
#include<stdlib.h>

typedef char elemtype;
typedef struct treenode{
    elemtype data;
    struct treenode *lchild;
    struct treenode *rchild;

}treenode;

typedef struct treenode *bitree;

// 前序遍历
void preorder(bitree T){
    if (T==NULL) return;
    printf("%c",T->data);
    preorder(T->lchild);
    preorder(T->rchild);
}

// 中序遍历
void inorder(bitree T){
    if (T == NULL) return;
    inorder(T->lchild);
    printf("%c",T->data);
    inorder(T->rchild);
}

// 后序遍历
void postorder(bitree T){
    if (T == NULL) return;
    postorder(T->lchild);
    postorder(T->rchild);
    printf("%c",T->data);
}

char str[] = "ABDH#K###E##CFI###G#J##";
int idx = 0;

void createtree(bitree *T){
    elemtype ch;
    ch = str[idx++];
    if (ch == '#'){
        *T = NULL;
    }
    else{
        *T = (bitree)malloc(sizeof(treenode));
        (*T)->data = ch;
        createtree(&(*T)->lchild);
        createtree(&(*T)->rchild);
    }
}


int main(){
    bitree T;
    createtree(&T);

    preorder(T);
    printf("\n");

    inorder(T);
    printf("\n");

    postorder(T);
    printf("\n");
    return 0;
    
}
// 层序遍历
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef char treetype;

typedef struct treenode{
    treetype data;
    struct treenode*lchild;
    struct treenode*rchild;
    // int ltag;
    // int rtag;
}treenode;

typedef treenode* elemtype;

typedef struct {
    elemtype *data;
    int front;
    int rear;
}queue;

typedef treenode* bitree;

char str[] = "ABDH#K###E##CFI###G#J##";
int idx = 0;

void createtree(bitree *T){
    treetype ch;
    ch = str[idx++];
    if (ch == '#'){
        *T = NULL;    //解指针
    }
    else{
        *T = (bitree)malloc(sizeof(treenode));
        (*T)->data = ch;

        createtree(&(*T)->lchild);
        createtree(&(*T)->rchild);
    }
}

queue* initqueue(){
    queue*q = (queue*)malloc(sizeof(queue));
    q->data = (elemtype*)malloc(sizeof(elemtype)*MAXSIZE);
    q->front = 0;
    q->rear = 0;
    return q;
}

int isempty(queue* q){
    return q->front == q->rear;
}

int enqueue(queue* q, elemtype e){
    if ((q->rear+1)%MAXSIZE == q->front) return 0;
    q->data[q->rear] = e;
    q->rear = (q->rear + 1)%MAXSIZE;  //
    return 1;
}

int dequeue(queue* q, elemtype *e){
    if (q->rear == q->front) return 0;
    *e = q->data[q->front];
    q->front = (q->front + 1)%MAXSIZE;  //
    return 1;
}

int queuesize(queue*q){
    if(!isempty(q)){
        return q->rear - q->front;
    }
    else{
        return 0;
    }
}

int maxdepth(treenode* root){
    if (root == NULL) return 0;

    int depth = 0;
    queue*q = initqueue();
    enqueue(q,root);

    while (!isempty(q)){
        int count = queuesize(q);
        while(count > 0){
            treenode* curr;
            dequeue(q, &curr);
            if(curr->lchild != NULL){
                enqueue(q, curr->lchild);
            }
            if(curr->rchild != NULL){
                enqueue(q, curr->rchild);
            }
            count--;
        }
        depth++;
    }
    return depth;

}

int main(){
    bitree T;
    createtree(&T);
    printf("%d\n",maxdepth(T));
    return 0;
}
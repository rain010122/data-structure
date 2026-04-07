// 队列的链式结构
// 顺序结构rear指向尾元素下一个位置，链式结构rear指向尾节点,front指向头节点
#include<stdio.h>
#include<stdlib.h>

typedef int elemtype;

typedef struct queuenode{
    elemtype data;
    struct queuenode *next;
}queuenode;

typedef struct{
    queuenode *front;
    queuenode *rear;
}queue;

queue* initqueue(){
    queue*q = (queue*)malloc(sizeof(queue));
    queuenode*node = (queuenode*)malloc(sizeof(queuenode));
    node->data = 0;
    node->next = NULL;
    q->front = node;
    q->rear = node;
    return q;
}

void enqueue(queue* q, elemtype e){
    queuenode*node = (queuenode*)malloc(sizeof(queuenode));
    node->data = e;
    node->next = NULL;
    q->rear->next = node;
    q->rear = node;
}

int dequeue(queue*q, elemtype *e){
    if(q->front->next == NULL) return 0;

    queuenode*node = q->front->next;
    *e = node->data;

    q->front->next = node->next;
    if(q->rear == node) {
        q->rear = q->front;
    }
    free(node);
    return 1;
}

int gethead(queue*q, elemtype *e){
    if (q->front->next == NULL) return 0;
    queuenode*node = q->front->next;
    *e = node->data;
    return 1;
}

int main(){
    queue*q = initqueue();
    for(int i = 1; i<6; i++){
        enqueue(q,i*10);
    }
    elemtype e;
    dequeue(q,&e);
    printf("出队%d\n",e);
    dequeue(q,&e);
    printf("出队%d\n",e);
    gethead(q,&e);
    printf("头%d\n",e);
    return 0;
}
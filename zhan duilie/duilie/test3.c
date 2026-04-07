// 队列顺序结构-循环队列
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef int elemtype;
typedef struct{
    elemtype *data;
    int front;
    int rear;
}queue;

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

int main(){
    queue*q = initqueue();
    for (int i=1; i<5; i++){
        enqueue(q,i);
    }
    elemtype e;
    dequeue(q,&e);
    printf("%d",e);
    return 0;
}
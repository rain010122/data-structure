// 队列的顺序结构-动态分配内存
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef int elemtype;
typedef struct {
    elemtype *data;
    int front;
    int rear;
}queue;

queue* initqueue(){
    queue *q = (queue*)malloc(sizeof(queue));
    q->data = (elemtype*)malloc(sizeof(elemtype)*MAXSIZE);
    q->front = 0;
    q->rear = 0;
    return q;
}

int dequeue(queue* q, elemtype *e){
    if(q->front == q->rear) return 0;
    *e = q->data[q->front];
    q->front++;
    return 1;
}

int isfull(queue* q){
    if (q->front > 0){
        int temp = q->front;
        for (int i=q->front; i<q->rear; i++){
            q->data[i-temp] = q->data[i];
        }
        q->rear = q->rear - temp;
        q->front = q->front - temp;
        return 0;
    }
    else return 1;
}

int enqueue(queue* q, elemtype e){
    if (q->rear == MAXSIZE){
        if (isfull(q)) return 0;
    }
    else{
        q->data[q->rear] = e;
        q->rear++;
        return 1;
    }
}

int gethead(queue* q, elemtype *e){
    if (q->front == q->rear) return 0;
    *e = q->data[q->front];
    return 1;
}

int main(){
    queue* q = initqueue();
    for (int i=1; i<5; i++){
        enqueue(q,i);
    }
    elemtype e;
    dequeue(q,&e);
    printf("%d\n",e);

    gethead(q,&e);
    printf("%d\n",e);
    return 0;
}
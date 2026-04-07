// 队列顺序结构实现
// 出队和获取值的时候要用指针
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef int elemtype;
typedef struct{
    elemtype data[MAXSIZE];
    int front;
    int rear;
}queue;

void initqueue(queue *q){
    q->front = 0;
    q->rear = 0;
}

int isempty(queue *q){
    return q->front == q->rear;
}

int dequeue(queue *q, elemtype *e){
    if(q->front == q->rear) return 0;
    *e = q->data[q->front];
    q->front++;
    return 1;
}

int queuefull(queue *q){
    if (q->front > 0){
        int step = q->front;
        for (int i = q->front; i<q->rear; i++){   //rear是队尾的下一个位置
            q->data[i-step] = q->data[i];
        }
        q->front = 0;
        q->rear = q->rear-step;
        return 0;
    }
    else{
        printf("真已满\n");
        return 1;
    }
}

int enqueue(queue *q, elemtype e){
    if(q->rear >= MAXSIZE) {
        if(queuefull(q)){           //若无法移动
            printf("已满\n");
            return 0;
        }
    }
    q->data[q->rear] = e;
    q->rear++;
    return 1;
}

int gethead(queue *q, elemtype *e){
    if(q->front == q->rear) return 0;
    *e = q->data[q->front];
    return 1;
}

int main(){
    queue q;
    initqueue(&q);
    for (int i = 1; i<5; i++){
        equeue(&q,i*10);
    }

    elemtype e;
    dequeue(&q,&e);
    printf("%d\n",e);

    gethead(&q,&e);
    printf("%d\n",e);
    return 0;

}
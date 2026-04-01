// 动态分配内存
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef int elemtype;
typedef struct{
    elemtype *data;
    int top;
}stack;

stack* initstack(){
    stack*s = (stack*)malloc(sizeof(stack));
    s->data = (elemtype*)malloc(sizeof(elemtype)*MAXSIZE);
    s->top = -1;
    return s;
}

int push(stack*s,elemtype e){
    if(s->top >= MAXSIZE-1) return 0;
    s->top++;
    s->data[s->top] = e;
    return 1;
}

int pop(stack *s,elemtype *e){
    if(s->top == -1) return 0;
    *e = s->data[s->top];
    s->top--;
    return 1;
}

int gettop(stack*s,elemtype *e){
    if(s->top == -1) return 0;
    *e = s->data[s->top];
    return 1;
}

int main(){
    stack *s = initstack();
    for (int i=1; i<4; i++){
        push(s,i*10);
    }

    elemtype e;
    pop(s,&e);
    printf("%d\n",e);

    gettop(s,&e);
    printf("%d\n",e);
    return 0;
}


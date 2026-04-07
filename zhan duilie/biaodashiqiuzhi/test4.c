// 中缀表达式转后缀表达式
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef int elemtype;
typedef struct stack{
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
    if(s->top >= MAXSIZE) return 0;
    s->top++;
    s->data[s->top] = e;
    return 1;
}

int pop(stack*s,elemtype*e){
    if(s->top==-1) return 0;
    *e = s->data[s->top];
    s->top--;
    return 1;
}


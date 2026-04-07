// 栈的链式结构实现
#include<stdio.h>
#include<stdlib.h>

typedef int elemtype;

typedef struct stack{
    elemtype data;
    struct stack *next;
}stack;

stack* initstack(){
    stack* s = (stack*)malloc(sizeof(stack));
    s->data = 0;
    s->next = NULL;
    return s;
}

int isempty(stack* s){
    return s->next == NULL;
}

int push(stack* s, elemtype e){
    stack*p = (stack*)malloc(sizeof(stack));
    p->data = e;
    p->next = s->next;
    s->next = p;
    return 1;
}

int pop(stack* s, elemtype* e){
    if(s->next ==NULL) return 0;
    *e = s->next->data;
    stack*q = s->next;
    s->next = q->next;
    free(q);
    return 1;
}

int gettop(stack*s, elemtype *e){
    if(s->next == NULL) return 0;
    *e = s->next->data;
    return 1;
}

int main(){
    stack* s = initstack();
    for (int i = 1; i<4; i++){
        push(s,i*10);
    }
    
    elemtype e;
    pop(s,&e);
    printf("%d\n",e);

    gettop(s,&e);
    printf("%d\n",e);
    return 0;
}
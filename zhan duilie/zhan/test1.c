// 
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef int elemtype;
typedef struct {
    elemtype data[MAXSIZE];
    int top;
}stack;

void initstack(stack *s){
    s->top = -1;
}

// 判断是否为空栈
int isempty(stack *s){
    if (s->top == -1){
        printf("空的\n");
        return 1;
    }
    else{
        return 0;
    }
}

// 进栈
int push(stack *s, elemtype e){
    if (s->top >= MAXSIZE-1){
        printf("已满\n0");
        return 0;
    }
    s->top++;
    s->data[s->top] = e;
    return 1;
}

// 出栈
int pop(stack *s, elemtype *e){
    if(s->top == -1){
        printf("空\n");
        return 0;
    }
    *e = s->data[s->top];
    s->top--;
    return 1;
}

// 获取栈顶元素
int gettop(stack *s, elemtype *e){
    if (s->top == -1){
        printf("空\n");
        return 0;
    }
    *e = s->data[s->top];
    return 1;
}

int main(){
    stack s;
    initstack(&s);
    for (int i=1; i<4; i++){
        push(&s,i*10);
    }
    elemtype e;
    pop(&s,&e);
    printf("%d\n",e);
    gettop(&s,&e);
    printf("%d\n",e);
    return 0;
}
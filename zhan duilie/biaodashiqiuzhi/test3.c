// 后缀表达式求值
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef int elemtype;
typedef struct stack{
    elemtype *data;
    int top;
}stack;

typedef enum{
    L_P,R_P,
    ADD,SUB,MUL,DIV,MOD,
    EOS,NUM
}contenttype;

char expr[] = "82/2+56*-";

stack* initstack(){
    stack*s = (stack*)malloc(sizeof(stack));
    s->data = (elemtype*)malloc(sizeof(elemtype)*MAXSIZE);
    s->top = -1;
    return s;
}

int push(stack*s, elemtype e){
    if(s->top >= MAXSIZE-1) return 0;
    s->top++;
    s->data[s->top] = e;
    return 1;
}

int pop(stack*s, elemtype *e){
    if(s->top == -1) return 0;
    *e = s->data[s->top];
    s->top--;
    return 1;
}

contenttype gettoken(char *symbol, int *index){
    *symbol = expr[*index];
    *index = *index + 1;
    switch(*symbol){
        case '(' : return L_P;
        case ')' : return R_P;
        case '+' : return ADD;
        case '-' : return SUB;
        case '*' : return MUL;
        case '/' : return DIV;
        case '%' : return MOD;
        case '\0': return EOS;
        default : return NUM;
    }
}

int eval(stack*s){
    int op1,op2;
    char symbol;
    int index = 0;
    contenttype token;
    token = gettoken(&symbol, &index);
    elemtype result;
    while (token != EOS){
        if (token == NUM){
            push(s, symbol - '0');
        }
        else{
            pop(s, &op2);
            pop(s, &op1);
            switch(token){
                case ADD:
                    push(s, op1+op2);
                    break;
                case SUB:
                    push(s, op1-op2);
                    break;
                case MUL:
                    push(s, op1*op2);
                    break;
                case DIV:
                    push(s, op1/op2);
                    break;
                case MOD:
                    push(s, op1%op2);
                    break;
                default:
                    break;
            }
        }
        token = gettoken(&symbol, &index);
    }
    pop(s, &result);
    printf("%d\n",result);
    return 1;
}

int main(){
    stack*s = initstack();
    eval(s);
    return 0;
}
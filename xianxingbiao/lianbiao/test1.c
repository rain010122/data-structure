// 单链表-初始化
#include<stdio.h>
#include<stdlib.h>

typedef int elemtype;

typedef struct node{
    elemtype data;
    struct node *next;
}node;

node* initlist(){
    node *head = (node*)malloc(sizeof(node));
    head->data = 0;
    head->next = NULL;
    return head;
}
// 第一行node*代表返回node的指针，返回头节点的地址
// 第二行node *head 变量定义：head是指向node的指针，储存头节点地址
// (node*)把malloc结果强制转换为node*类型

int main(){
    node *list = initlist();
    return 1;
}
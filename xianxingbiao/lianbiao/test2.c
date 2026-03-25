//单链表-头插法：每次都插入在头节点的后面
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

int inserthead(node* L, elemtype e){
    node *p = (node*)malloc(sizeof(node));
    p->data = e;
    p->next = L->next;
    L->next = p;
}
// 先赋值
// 新节点指向原来的第一个节点
// 头节点指向新节点

int main(){
    node *list = initlist();
    inserthead(list,23);
    inserthead(list,35);
}
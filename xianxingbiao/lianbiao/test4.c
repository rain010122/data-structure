// 单链表-尾插法
// 1.获取尾节点 2.在尾节点插入新尾节点并返回新尾节点
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
    return 1;
}

void listnode(node* L){
    node *p = L->next;
    while (p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

node* gettail(node* L){
    node *p = L;
    while (p->next != NULL){
        p = p->next;
    }
    return p;
}

node* inserttail(node* tail, elemtype e){
    node *p = (node*)malloc(sizeof(node));
    p->data = e;
    p->next = NULL;
    tail->next = p;
    return p;
}



int main(){
    node* list = initlist();
    inserthead(list,111);
    inserthead(list, 222);
    inserthead(list, 333);
    listnode(list);
    node *tail = gettail(list);
    tail = inserttail(tail,777);
    tail = inserttail(tail,888);
    tail = inserttail(tail,999);
    listnode(list);
}
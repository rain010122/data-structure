// 单链表-遍历
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

int main(){
    node *list = initlist(); // list始终指向头节点
    inserthead(list, 11);
    inserthead(list, 22);
    inserthead(list, 33);
    listnode(list);
    return 0;
}


// 应用4. 反转链表
// 三指针
#include<stdio.h>
#include<stdlib.h>

typedef int elemtype;
typedef struct node{
    elemtype data;
    struct node* next;
}node;

node* initnode(){
    node*head = (node*)malloc(sizeof(node));
    head->next = NULL;
    head->data = 0;
    return head;
}

node* gettail(node* L){
    node*p = L;
    while (p->next!=NULL){
        p = p->next;
    }
    return p;
}

node* inserttail(node* tail, elemtype e){
    node*p = (node*)malloc(sizeof(node));
    p->data = e;
    p->next = NULL;
    tail->next = p;
    return p;
}

int listnode(node* L){
    node*p = L->next;
    while(p!=NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

node* invertnode(node* L){
    node* p1 = NULL;
    node* p2 = L->next;
    node* p3 = p2->next;
    while(p2 != NULL){
        p2->next = p1;
        p1 = p2; //
        p2 = p3;
        if(p3!=NULL) p3= p3->next;
    }
    L->next = p1;
    return L;
}

int main(){
    node* list = initnode();
    node* tail = gettail(list);
    tail = inserttail(tail,1);
    tail = inserttail(tail,2);
    tail = inserttail(tail,3);
    tail = inserttail(tail,4);
    tail = inserttail(tail,5);
    tail = inserttail(tail,6);
    listnode(list);

    invertnode(list);
    listnode(list);
}
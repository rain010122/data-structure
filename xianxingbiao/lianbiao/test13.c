// 应用5. 删除链表中间节点
// 快慢指针
#include<stdio.h>
#include<stdlib.h>

typedef int elemtype;
typedef struct node{
    elemtype data;
    struct node* next;
}node;

node* initnode(){
    node* head = (node*)malloc(sizeof(node));
    head->next = NULL;
    head->data = 0;
    return head;
}

node* gettail(node* L){
    node* p = L;
    while(p->next != NULL){
        p = p->next;
    }
    return p;
}

node* inserttail(node* tail, elemtype e){
    node* p = (node*)malloc(sizeof(node));
    p->data = e;
    p->next = NULL;
    tail->next = p;
    return p;
}

node* listnode(node* L){
    node* p = L->next;
    while (p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

node* delmid(node* L){
    node* p = L->next;
    node* q = L;
    while (p != NULL && p->next != NULL){
        p = p->next->next;
        q = q->next;
    }
    node*temp = q->next;
    q->next = temp->next;
    free(temp);
    return L;
}

int main(){
    node*L = initnode();
    node*tail = gettail(L);
    for (int i = 1; i<8; i++){
        tail = inserttail(tail,i);
    }
    listnode(L);
    delmid(L);
    listnode(L);
}
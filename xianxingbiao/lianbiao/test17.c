// 头插法、尾插法、指定位置插入
// 删除节点
#include<stdio.h>
#include<stdlib.h>

typedef int elemtype;
typedef struct node{
    elemtype data;
    struct node *prev, *next;
}node;

node* initnode(){
    node*head = (node*)malloc(sizeof(node));
    head->next = NULL;
    head->prev = NULL;
    head->data = 0;
    return head;
}

int inserthead(node* L, elemtype e){
    node*p = (node*)malloc(sizeof(node));
    p->data = e;
    p->next = L->next;
    p->prev = L;
    if(L->next!=NULL) L->next->prev = p;
    L->next = p;
    return 1;
}

node* gettail(node* L){
    node*p = L;
    while(p->next!=NULL){
        p = p->next;
    }
    return p;
}

node* inserttail(node* tail, elemtype e){
    node*p = (node*)malloc(sizeof(node));
    p->data = e;
    p->next = NULL;
    p->prev = tail;
    tail->next = p;
    return p;
}

int insertnode(node* L, int pos, elemtype e){
    if (pos<1) return 0;

    node*p = L;
    for (int i = 0; i<pos-1; i++){
        p = p->next;
        if (p == NULL) return 0;
    }

    node*q = (node*)malloc(sizeof(node));
    q->data = e;
    q->next = p->next;
    q->prev = p;
    if (p->next != NULL) {
        p->next->prev = q;
    }
    p->next = q;
    return 1;
}

int delnode(node* L, int pos){
    if(pos<1) return 0;

    node*p = L;
    for (int i=0; i<pos-1; i++){
        p = p->next;
        if(p == NULL ) return 0;
    }
    if(p->next == NULL) return 0;

    node*q = p->next;
    p->next = q->next;
    if(q->next != NULL){
        q->next->prev = p;
    }
    free(q);
    return 1;
}

void listnode(node* L){
    node*p = L->next;
    while(p!=NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

int main(){
    node*L = initnode();
    for (int i = 6; i>0; i--){
        inserthead(L,i);
    }
    listnode(L);
    
    // node*tail = gettail(L);
    // for (int i = 1; i<7; i++){
    //     tail = inserttail(tail,i);
    // }
    // listnode(L);

    // insertnode(L,3,9);
    // listnode(L);
    delnode(L,6);
    listnode(L);
    return 0;
}
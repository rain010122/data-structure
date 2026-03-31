// 单链表-删除节点
// 1. 找前置节点(不能为null) 2. 删除节点（不能为null）
#include<stdio.h>
#include<stdlib.h>

typedef int elemtype;
typedef struct node{
    elemtype data;
    struct node *next;
}node;

node* initnode(){
    node* head = (node*)malloc(sizeof(node));
    head->data = 0;
    head->next = NULL;
    return head;
}

int inserthead(node* L, elemtype e){
    node* p = (node*)malloc(sizeof(node));
    p->data = e;
    p->next = L->next;
    L->next = p;
    return 1;
}

node* gettail(node* L){
    node* p = L;
    while (p->next != NULL){
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

int insertnode(node* L, int pos, elemtype e){
    node* p = L;
    int i = 0;
    while (i < pos - 1){
        p = p->next;
        i++;
        if(p == NULL){
            return 0;
        }
    }
    node* q = (node*)malloc(sizeof(node));
    q->data = e;
    q->next = p->next;
    p->next = q;
    return 1;
}

int delenode(node* L, int pos){
    if(pos<1) return 0;
    node*p = L;
    for (int i = 0; i < pos-1; i++){
        p = p->next;
        if (p == NULL){
            printf("删除位置超出范围\n");
            return 0;
        }
    }

    if(p->next == NULL){
        printf("删除位置超出范围\n");
        return 0;
    }
    node*q = p->next;
    p->next = q->next;
    free(q);
    return 1;
}

void listnode(node* L){
    node* p = L->next;
    while (p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

int main(){
    node* list = initnode();
    inserthead(list,333);
    inserthead(list, 222);
    inserthead(list, 111);
    listnode(list);

    node* tail = gettail(list);
    tail = inserttail(tail,777);
    tail = inserttail(tail,888);
    tail = inserttail(tail, 999);
    listnode(list);

    insertnode(list,4,444);
    insertnode(list,5,555);
    insertnode(list,6,666);
    listnode(list);

    delenode(list,9);
    listnode(list);
}
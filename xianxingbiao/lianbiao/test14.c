// 应用6. 链表重排序
// 
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

void listnode(node* L){
    node* p = L->next;
    while (p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

node* reoderlist(node*L){
    if (L == NULL || L->next == NULL || L->next->next == NULL) return L;
    // 双指针找中间位置(奇数长度要保证拼接时上半段长于下半段，因此node*q = L->next)
    node*p = L->next;
    node*q = L->next;
    while (p!=NULL && p->next!=NULL){
        p = p->next->next;
        q = q->next;
    }
    node* temp = q->next;
    q->next = NULL;

    // 后半段反转
    node*p1 = NULL;
    node*p2 = temp;
    node*p3 = p2->next;
    while(p2 != NULL){
        p2->next = p1;
        p1 = p2;
        p2 = p3;
        if (p3 != NULL) p3 = p3->next;
    }

    // 插入
    node*m1 = L->next;
    node*n1 = p1;
    while(n1 != NULL){
        node*m2 = m1->next;
        node*n2 = n1->next;

        m1->next = n1;
        n1->next = m2;
        m1 = m2;
        n1 = n2;
    }
    return L;
}

int main(){
    node*L = initnode();
    node*tail = gettail(L);
    for (int i = 1; i<8; i++){
        tail = inserttail(tail,i);
    }
    listnode(L);
    reoderlist(L);
    listnode(L);

}
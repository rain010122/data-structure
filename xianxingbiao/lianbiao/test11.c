// 应用3. 利用数组标记去重
#include <stdio.h>
#include <stdlib.h>

typedef int elemtype;

typedef struct node{
    elemtype data;
    struct node* next;
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

node* inserttail(node* tail , elemtype e){
    node* p = (node*)malloc(sizeof(node));
    p->next = NULL;
    p->data = e;
    tail ->next = p;
    return p;
}

int insertnode(node* L, int pos, elemtype e){
    node* p = L;
    if (L == NULL) return 0;
    for (int i = 0; i<pos-1; i++){
        p = p->next;
        if(p == NULL) return 0;
    }
    node* q = (node*)malloc(sizeof(node));
    q->next = p->next;
    q->data = e;
    p->next = q;
    return 1;
}

int listnode(node* L){
    node* p = L->next;
    while (p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
    return 1;
}

void removenode(node* L, int n){
    node*p = L;
    int index;
    int *q = (int*)malloc(sizeof(int)*(n+1));

    // 遍历数组，设置为0
    for (int i = 0; i<n+1; i++){
        *(q+i) = 0;
    }

    while(p->next != NULL){
        index = abs(p->next->data);
        if(*(q+index) == 0){
            *(q+index) =1;
            p = p->next;
        }
        else{
            node*temp = p->next;
            p->next = temp->next;
            free(temp);
        }
    }
    free(q);
}

int main(){
    node* list = initnode();
    node* tail = gettail(list);
    tail = inserttail(tail,21);
    tail = inserttail(tail,-15);
    tail = inserttail(tail,-15);
    tail = inserttail(tail,-7);
    tail = inserttail(tail,15);
    listnode(list);

    removenode(list,21);
    listnode(list);
}
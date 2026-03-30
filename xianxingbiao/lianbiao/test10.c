// 应用2. 两个链表找公共后缀节点
// 双指针
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef char elemtype;

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

node* initnodewithelem(elemtype e){
    node* head = (node*)malloc(sizeof(node));
    head->data = e;
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

node* inserttailnode(node* tail, node* L){
    // node* p = (node*)malloc(sizeof(node));
    tail->next = L;
    L->next = NULL;
    return L;
}

int insertnode(node* L, int pos, elemtype e){
    node* p = L;
    for (int i = 0; i < pos-1; i++){
        p = p->next;
        if (p == NULL) return 0;
    }

    node* q = (node*)malloc(sizeof(node));
    q->data = e;
    q->next = p->next;
    p->next = q;
    return 1;
}

int delenode(node* L, int pos){
    node* p = L;
    for (int i = 0; i<pos-1; i++){
        p = p->next;
        if (p == NULL) return 0;
    }

    node* q = p->next;
    if (q == NULL) return 0;
    p->next = q->next;
    free(q);
    return 1;
}

int listnode(node* L){
    node* p = L->next;
    while (p != NULL){
        printf("%c ",p->data);
        p = p->next;
    }
    printf("\n");
    return 0;
}

int getlength(node* L){
    node* p = L;
    int i = 0;
    while (p != NULL){
        p = p->next;
        i++;
    }
    return i;
}

void freenode(node* L){
    node* p = L->next;
    while (p != NULL){
        node* q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL;
}

int findnode(node* L, int k){
    node* p = L;
    node* q = L;
    for (int i = 0; i<k; i++){
        p = p->next;
    }
    while (p != NULL){
        p = p->next;
        q = q->next;
    }
    printf("倒数第%d个节点值为%d\n",k,q->data);
    return 1;
}

node* findpositionnode(node* head1,node* head2){
    if (head1 == NULL || head2 == NULL) return 0;
    int len1 = 0;
    int len2 = 0;
    node* p = head1;
    while (p != NULL){
        p = p->next;
        len1 ++;
    }
    p = head2;
    while (p != NULL){
        p = p->next;
        len2 ++;
    }
    node* m = head1;
    node* n = head2;
    if (len1 > len2){
        int step = len1 - len2;
        for (int i = 0; i < step; i++){
            m = m->next;
        }
    }
    if (len1 < len2){
        int step = len2 - len1;
        for (int i = 0;i < step; i++){
            n = n->next;
        }
    }
    while (m != n){
        m = m->next;
        n = n->next;
    }
    return m;
}

int main(){
    node* list1 = initnode();
    node* list2 = initnode();
    node* tail1 = gettail(list1);
    node* tail2 = gettail(list2);
    tail1 = inserttail(tail1,'l');
    tail1 = inserttail(tail1,'o');
    tail1 = inserttail(tail1,'a');
    tail1 = inserttail(tail1,'d');
    tail2 = inserttail(tail2,'b');
    tail2 = inserttail(tail2,'e');

    node* nodei = initnodewithelem('i');
    tail1 = inserttailnode(tail1,nodei);
    tail2 = inserttailnode(tail2,nodei);
    node* noden = initnodewithelem('n');
    tail1 = inserttailnode(tail1,noden);
    tail2 = inserttailnode(tail2,noden);
    node* nodeg = initnodewithelem('g');
    tail1 = inserttailnode(tail1,nodeg);
    tail2 = inserttailnode(tail2,nodeg);

    listnode(list1);
    listnode(list2);

    printf("%c\n",findpositionnode(list1,list2)->data);
    return 0;
}
// 应用7. 判断是否是循环链表、环有几个节点、找循环链表入口
#include<stdio.h>
#include<stdlib.h>

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

node* gettail(node* L){
    node*p = L;
    while (p->next != NULL){
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

node* listnode(node* L){
    node*p = L->next;
    while (p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

node* reodernode(node* L){
    node*fast = L->next;
    node*slow = L->next;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    node*temp = slow->next;
    slow->next = NULL;

    node*p1 = NULL;
    node*p2 = temp;
    node*p3 = p2->next;
    while (p2 != NULL){
        p2->next = p1;
        p1 = p2;
        p2 = p3;
        if (p3 != NULL) p3 = p3->next;
    }

    node*m1 = L->next;
    node*n1 = p1;
    while (n1 != NULL){
        node*m2 = m1->next;
        node*n2 = n1->next;

        m1->next = n1;
        n1->next = m2;
        m1 = m2;
        n1 = n2;
    }
    return L;
}

node* findbegin(node*L){
    node*fast = L;
    node*slow = L;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            printf("有环\n");
            break;
        }
    }

    if (fast == NULL || fast->next ==NULL){
        printf("无环\n");
        return NULL;
    }

    fast = fast->next;
    int count = 1;
    while (fast != slow){
        fast = fast->next;
        count++;
    }
    printf("环有%d个节点\n",count);

    node*p = L;
    while(p != fast){
        p = p->next;
        fast = fast->next;
    }
    return p;
}

int main(){
    node*L = initnode();
    node*tail = gettail(L);
    for (int i = 1; i<9; i++){
        tail = inserttail(tail,i);
    }
    listnode(L);
    tail->next = L->next->next->next;

    printf("环起点%d",findbegin(L)->data);
}
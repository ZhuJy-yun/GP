#include <iostream>
#include<list>
using namespace std;

typedef struct Node{

    int val;
    struct Node *next;
    struct Node *prev;
} NODE,*PNODE;

class MyList{

public:
    MyList(){
        size=0;
        head= nullptr;
    };
    void insert(int val){

        PNODE node=(PNODE) malloc(sizeof(NODE));
        node->val=val;
        node->next= nullptr;
        node->prev=last;

        last=node;
        size++;
    }
    void pop(){

    }

    bool empty(){
        return size<1;
    }

    int size;
    PNODE head;
    PNODE last;

};


int main(){

    PNODE node1=(PNODE) malloc(sizeof(NODE));
    node1->val=1;
    node1->next= nullptr;
    node1->prev= nullptr;

    PNODE node2=(PNODE) malloc(sizeof(NODE));
    node2->val=2;
    node2->next= nullptr;
    node2->prev= nullptr;

    PNODE node3=(PNODE) malloc(sizeof(NODE));
    node3->val=3;
    node3->next= nullptr;
    node3->prev= nullptr;

    PNODE node4=(PNODE) malloc(sizeof(NODE));
    node4->val=4;
    node4->next= nullptr;
    node4->prev= nullptr;

    node1->next=node2;
    node2->next=node3;
    node3->next=node4;

    node4->prev=node3;
    node3->prev=node2;
    node2->prev=node1;


    PNODE head=node1;
    while (head != nullptr){
        cout<<head->val<<endl;
        head=head->next;
    }
    cout<<endl;
    PNODE last = node4;
    while (last != nullptr){
        cout<<last->val<<endl;
        last=last->prev;
    }

    MyList mylist;

    node4->next=node1;
    node1->prev=node4;


    return 0;
}
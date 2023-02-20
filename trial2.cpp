#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node(int d){
        data=d;
        next=NULL;
    }
};

node* takeInput(){
    int d;
    cin >> d;
    node *head=NULL;
    node *tail=NULL;
    while(d!=-1){
        node *n=new node(d);
        if(head==NULL){
            head=n;
            tail=n;
        }else{
            tail->next=n;
            tail=n;
        }
        cin >> d;
    }
    return head;
}

void printList(node *head){
    if(head==NULL) return;
    cout << head->data << " ";
    printList(head->next);
}

void insertAtEnd(node *head, int d){
    while(head->next!=NULL) head=head->next;
    node *n=new node(d);
    head->next=n;
}

int main(){
    node *head=takeInput();
    printList(head);
    cout << endl;
    int d;
    cin >> d;
    insertAtEnd(head, d);
    printList(head);
}
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node *prev;
    node(int d){
        data=d;
        prev=NULL;
        next=NULL;
    }
};

node* takeInput(){
    int d;
    cin >> d;
    node *head=NULL;
    node *n=NULL;
    while(d!=-1){
        node *temp=new node(d);
        if(head==NULL){
            head=temp;
            n=temp;
        }else{
            temp->prev=n;
            n->next=temp;
            n=temp;
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

void reverseList(node *head){
    if(head==NULL) return;
    reverseList(head->next);
    cout << head->data << ' ';
}

int main(){
    cout << "Enter the elements of the Linked List : ";
    node *head=takeInput();
    printList(head);
    // cout << endl << "Enter the new node to be added at the end of the Linked List : ";
    // int d;
    // cin >> d;
    // insertAtEnd(head, d);

    // cout << endl << "Reverse Linked List is : ";
    // reverseList(head);
}
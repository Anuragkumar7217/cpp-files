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
        node *temp=new node(d);
        if(head==NULL){
            head=temp;
            tail=temp;
        }else{
            tail->next=temp;
            tail=temp;
        }
        cin >> d;
    }
    tail->next=head;
    return head;
}

void printList(node *head){
    node *h=head;
    while(h->next!=head){
        cout << h->data << " ";
        h=h->next;
    }
    cout << h->data << endl;
}

void deleteLastNode(node *head){
    node *h=head;
    node *prev=NULL;
    while(h->next!=head){
        prev=h;
        h=h->next;
    }
    prev->next=head;
}

int main(){
    cout << "Enter the elements of the Linked List : ";
    node *head=takeInput();
    printList(head);
    deleteLastNode(head);
    cout << "After deletion of last node remaining list is :";
    printList(head);
}
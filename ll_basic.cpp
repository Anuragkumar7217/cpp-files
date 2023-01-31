#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *next;
    
    node(int data){
        this->data=data;
        next=NULL;
    }
};

void print(node *head){
    node *temp=head;
    while(temp!=NULL){
        cout << temp->data <<' ';
        temp=temp->next;
    }
    cout << endl;
}

int main(){
    
    node n1(1);
    node n2(2);
    node n3(3);
    node *head=&n1;
    n1.next=&n2;
    n2.next=&n3;
    print(head);

    node *d1=new node(10);
    node *d2=new node(20);
    node *d3=new node(30);
    node *dhead=d1;
    d1->next=d2;
    d2->next=d3;
    print(dhead);
}
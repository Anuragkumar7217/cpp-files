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

node* takeinput(){
    int data;
    cin >> data;
    node *head=NULL;
    node *tail=NULL;
    while(data!=-1){
        node *n=new node(data);
        if(head==NULL){
            head=n;
            tail=n;
        }else{
            tail->next=n;
            tail=n;
        }
        cin >> data;
    }
    return head;
}

node* removeDuplicates(node *head){
    node *temp=head;
    while(head!=NULL && head->next!=NULL){
        if(head->data==head->next->data){
            head->next=head->next->next;
            if(head->next==NULL) break;
        }else{
            head=head->next;
        }
    }
    return temp;
}

void print(node *head){
    while(head!=NULL){
        cout << head->data <<' ';
        head=head->next;
    }
    cout << endl;
}

int main(){
    node *head=takeinput();
    print(head);
    head=removeDuplicates(head);
    print(head);
}
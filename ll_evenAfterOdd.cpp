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

node* evenAfterOdd(node *head){
    node *oh=NULL;
    node *ot=NULL;
    node *eh=NULL;
    node *et=NULL;
    node *temp=head;
    while(head!=NULL){
        if(head->data %2 !=0){
            if(oh==NULL){
                oh=head;
                ot=head;
            }else{
                ot->next=head;
                ot=head;
            }
        }else{
            if(eh==NULL){
                eh=head;
                et=head;
            }else{
                et->next=head;
                et=head;
            }
        }
        head=head->next;
    }
    if(oh==NULL || eh==NULL) return temp;
    ot->next=eh;
    et->next=NULL;
    return oh;
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
    head=evenAfterOdd(head);
    print(head);
}
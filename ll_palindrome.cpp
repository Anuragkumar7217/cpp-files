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

node* reverse(node *head){
    node *next;
    node *prev=NULL;
    node *curr=head;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
    return head;
}

bool isPalindrome(node *head){
    if(head==NULL || head->next==NULL) return true;
    node *h1=head;
    node *h2=head;
    node *temp=NULL;
    while(head!=NULL && head->next!=NULL){
        head=head->next->next;
        temp=h2;
        h2=h2->next;
    }
    temp->next=NULL;
    h2=reverse(h2);
    while(h1!=NULL && h2!=NULL){
        if(h1->data != h2->data) return false;
        h1=h1->next;
        h2=h2->next;
    }
    return true;
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
    if(isPalindrome(head)) cout << "true";
    else cout << "false";
    cout << endl;
}
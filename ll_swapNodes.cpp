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

node* swapNodes(node *head, int i, int j){
    node *mhead=head;
    node *p1=NULL, *p2=NULL;
    node *c1=NULL, *c2=NULL;
    int count=0;
    while(head!=NULL){
        if(count==i-1){
            p1=head;
            c1=head->next;
        }
        if(count==j-1){
            p2=head;
            c2=head->next;
        }
        head=head->next;
        count++;
    }
    if(i-1==-1 || j-1==-1){
        c1=mhead;
        if(p1!=NULL){
            p2=p1;
            c2=c1;
        }
        node *temp=c1->next;
        p2->next=c1;
        c1->next=c2->next;
        c2->next=temp;
        return c2;
    }
    if(p1==NULL || p2==NULL) return mhead;
    p1->next=c2;
    p2->next=c1;
    node *temp=c2->next;
    c2->next=c1->next;
    c1->next=temp;
    return mhead;
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
    int i,j;
    cin >> i >> j;
    head=swapNodes(head, i, j);
    print(head);
}
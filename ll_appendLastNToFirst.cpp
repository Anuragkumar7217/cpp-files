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

int length(node *head){
    if(head==NULL) return 0;
    return length(head->next) +1;
}

node* appendLastNToFirst(node *head, int n){
    if(head==NULL || n==0) return head;
    n=length(head)-n;
    int count=1;
    node *temp=head, *a;
    while(count<=n){
        a=temp;
        temp=temp->next;
        count++;
    }
    a->next=NULL;
    a=head;
    head=temp;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=a;
    return head;
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
    int n;
    cin >> n;
    head=appendLastNToFirst(head,n);
    print(head);
}
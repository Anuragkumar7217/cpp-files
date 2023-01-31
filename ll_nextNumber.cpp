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

void print(node *head){
    while(head!=NULL){
        cout << head->data <<' ';
        head=head->next;
    }
    cout << endl;
}

node *helper(node *head){
    if(head->next==NULL){
        head->data+=1;
        return head;
    }
    node *temp=helper(head->next);
    if(temp->data/10!=0){
        temp->data%=10;
        head->data+=1;
    }
    return head;
}

node* NextLargeNumber(node *head){
    if(head==NULL) return head;
    int ans=head->next->data;
    node *temp=helper(head->next);
    if(temp->data!=ans){
        temp->data%=10;
        head->data+=1;
        head->data%=10;
        node *n=new node(1);
        n->next=head;
        head=n;
    }
    return head;
}

int main(){
    node *head=takeinput();
    print(head);
    head=NextLargeNumber(head);
    print(head);
}
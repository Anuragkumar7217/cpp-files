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
node* insertNode(node *head,int i,int data){
    int count=0;
    node *n=new node(data);
    node *temp=head;
    if(i==0){
        n->next=head;
        head=n;
        return n;
    }
    while(temp!=NULL && count<i-1){
        count++;
        temp=temp->next;
    }
    if(temp!=NULL){
        n->next=temp->next;
        temp->next=n;
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
int main(){
    node *head=takeinput();
    print(head);
    int i, data;
    cin >>i >>data;
    head=insertNode(head,i,data);
    print(head);
}
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
void print(node *head){
    while(head!=NULL){
        cout << head->data <<' ';
        head=head->next;
    }
    cout << endl;
}

node* insertNode(node *head,int i,int data){
    if(head==NULL) return head;
    if(i==0){
        node *n=new node(data);
        n->next=head;
        head=n;
        return head;
    }
    node *x=insertNode(head->next,i-1,data);
    head->next=x;
    return head;
}

int main(){
    node *head=takeinput();
    print(head);
    int i, data;
    cin >>i >>data;
    head=insertNode(head,i,data);
    print(head);
}
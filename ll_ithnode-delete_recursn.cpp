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
node* deleteNode(node *head,int i){
    if(head==NULL) return head;
    if(i==0){
        head=head->next;
        return head;
    }
    node *x=deleteNode(head->next,i-1);
    head->next=x;
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
    int i;
    cin >> i;
    head=deleteNode(head,i);
    print(head);
}
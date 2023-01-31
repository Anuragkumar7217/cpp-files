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

int helper(node *head, int n, int i){
    if(head==NULL) return -1;
    if(head->data==n) return i;
    return helper(head->next, n, i+1);
}

int findNode(node *head, int n){
    return helper(head,n,0);
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
    cout << findNode(head,n);
}
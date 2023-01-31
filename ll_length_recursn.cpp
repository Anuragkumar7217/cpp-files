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
            tail=head;
        }else{
            tail->next=n;
            tail=tail->next;
        }
        cin >> data;
    }
    return head;
}
int length(node *head){
    if(head==NULL) return 0;
    return length(head->next) +1;
}
void print(node *head){
    node *temp=head;
    while(temp!=NULL){
        cout << temp->data <<' ';
        temp=temp->next;
    }
    cout << endl;
}

int main(){
    node *head = takeinput();
    print(head);
    cout << length(head);
    return 0;
}
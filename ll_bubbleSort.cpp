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
    int l=0;
    while(head!=NULL){
        l++;
        head=head->next;
    }
    return l;
}

node *bubbleSort(node *head){
    if(head==NULL || head->next==NULL) return head;
    int len=length(head);
    for(int i=0; i<len; i++){
        node *prev=NULL, *curr=head;
        while(curr->next!=NULL){
            node *next=curr->next;
            if(curr->data > next->data){
                if(prev==NULL){
                    curr->next=next->next;
                    next->next=curr;
                    prev=next;
                    head=next;
                }else{
                    prev->next=next;
                    curr->next=next->next;
                    next->next=curr;
                    prev=next;
                }
            }else{
                prev=curr;
                curr=curr->next;
            }
        }
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
	head = bubbleSort(head);
	print(head);
}
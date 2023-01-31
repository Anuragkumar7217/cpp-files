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

node* midpoint(node *head){
    node *fast=head;
    node *slow=head;
    node *temp=NULL;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        temp=slow;
        slow=slow->next;
    }
    temp->next=NULL;
    return slow;
}

node* mergeTwoSortedLinkedLists(node *head1, node *head2){
    node *fh=NULL;
    node *ft=NULL;
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    while(head1!=NULL && head2!=NULL){
        if(head1->data < head2->data){
            if(fh==NULL){
                fh=head1;
                ft=head1;
            }else{
                ft->next=head1;
                ft=head1;
            }
            head1=head1->next;
        }else{
            if(fh==NULL){
                fh=head2;
                ft=head2;
            }else{
                ft->next=head2;
                ft=head2;
            }
            head2=head2->next;
        }
    }
    if(head1!=NULL) ft->next=head1;
    if(head2!=NULL) ft->next=head2;
    return fh;
}

node* mergeSort(node *head){
    if(head==NULL || head->next==NULL) return head;
    node *h1=head;
    node *h2=midpoint(head);
    h1=mergeSort(h1);
    h2=mergeSort(h2);
    return mergeTwoSortedLinkedLists(h1,h2);
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
    head=mergeSort(head);
    print(head);
}
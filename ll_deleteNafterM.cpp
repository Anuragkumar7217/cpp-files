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

node* skipMdeleteN(node *head, int m, int n){
    node *nh=NULL;
    node *nt=NULL;
    int i=1;
    int count=m+n;
    while(head!=NULL){
        if(i<=m){
            if(nh==NULL){
                nh=head;
                nt=head;
            }else{
                nt->next=head;
                nt=head;
            }
        }
        if(i==count){
            i=0;
        }
        head=head->next;
        i++;
    }
    if(nh==NULL) return nh;
    nt->next=NULL;
    return nh;
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
    int m,n;
    cin >> m >> n;
    head=skipMdeleteN(head, m, n);
    print(head);
}
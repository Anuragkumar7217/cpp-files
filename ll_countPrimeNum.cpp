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

int countPrimeNum(node *head){
    int count=0;
    bool check=true;
    while(head!=NULL){
        int d=head->data;
        for(int i=2; i<d; i++){
            if(d%i != 0){
                check=true;
            }else{
                check=false;
                break;
            }
        }
        if(check==true) count++;
        head=head->next;
    }
    return count;
}

int main(){
    node *head=takeinput();
    print(head);
    cout << countPrimeNum(head);
}
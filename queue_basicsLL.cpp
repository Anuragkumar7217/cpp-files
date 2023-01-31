#include<bits/stdc++.h>
using namespace std;

template <typename T>
class node{
    public:
    T data;
    node<T> *next;
    node(int d){
        data=d;
        next=NULL;
    }
};

template <typename T>
class queueLL{
    node<T> *head;
    node<T> *tail;
    int n;

    public:
    queueLL(){
        head=NULL;
        tail=NULL;
        n=0;
    }
    int size(){
        return n;
    }
    bool empty(){
        return n==0;
    }
    void enqueue(T element){
        node<T> *nn=new node<T>(element);
        if(head==NULL){
            head=nn;
            tail=nn;
        }else{
            tail->next=nn;
            tail=nn;
        }
        n++;
    }
    T dequeue(){
        if(head==NULL) return 0;
        T ans=head->data;
        node<T> *temp=head;
        head=head->next;
        delete temp;
        n--;
        return ans;
    }
    T front(){
        if(head==NULL) return 0;
        return head->data;
    }
};

int main(){
    queueLL<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    cout << q.front() << endl;
    cout << q.dequeue() << endl;

    cout << q.size() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    q.enqueue(100);
    cout << q.size() << endl;
    
    cout << q.empty() << endl;
}
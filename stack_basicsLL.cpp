#include<bits/stdc++.h>
using namespace std;

template <typename T>
class node{
    public:
    T data;
    node<T> *next;
    node(T d){
        data=d;
        next=NULL;
    }
};

template <typename T>
class stackLL{
    node<T> *head;
    int size;

    public:

    stackLL(){
        head=NULL;
        size=0;
    }

    void push(T element){
        node<T> *n=new node<T>(element);        
        n->next=head;
        head=n;
        size++;
    }

    T pop(){
        if(head==NULL) return -1;
        T ans=head->data;
        node<T> *temp=head;
        head=head->next;
        delete temp;
        size--;
        return ans;
    }

    T top(){
        if(head==NULL) return -1;
        return head->data;
    }

    int getSize(){
        return size;
    }

    bool empty(){
        return size==0;
    }
};

int main(){
    stackLL<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << s.pop() << endl;
    cout << s.top() << endl;
    cout << s.getSize() << endl;
    cout << s.empty() << endl;

    s.push(50);
    cout << s.top() << endl;
}
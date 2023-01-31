#include<bits/stdc++.h>
using namespace std;

template <typename T>
class stackArr{
    T *data;
    int ni;
    int capacity;

    public:
    stackArr(){
        data= new T[4];
        ni=0;
        capacity=4;
    }

    void push(T element){
        if(ni==capacity){
            T *newData=new T[2*capacity];
            for(int i=0; i<capacity; i++){
                newData[i]=data[i];
            }
            capacity*=2;
            delete [] data;
            data=newData;
        }
        data[ni]=element;
        ni++;
    }
    T top(){
        if(isEmpty()){
            cout << "Stack is empty." << endl;
            return 0;
        }
        return data[ni-1];
    }
    T pop(){
        if(isEmpty()){
            cout << "Stack is empty." << endl;
            return 0;
        }
        ni--;
        return data[ni];
    }
    int size(){
        return ni;
    }
    bool empty(){
        return ni==0;
    }
};

int main(){
    stackArr<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    
    cout << s.size() << endl;
    
    cout << s.empty() << endl;
}
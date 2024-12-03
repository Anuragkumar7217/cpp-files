#include<bits/stdc++.h>
using namespace std;

template <typename T>
class queueArr{
    T *data;
    int ni, fi, n, capacity;

    public:
    queueArr(int size){
        data=new T[size];
        ni=0;
        fi=-1;
        n=0;
        capacity=size;
    }
    int size(){
        return n;
    }
    bool isEmpty(){
        return n==0;
    }
    void enqueue(T element){
        if(n==capacity){
            T *newData=new T[2*capacity];
            int j=0;
            for(int i=fi; i<capacity; i++){
                newData[j]=data[i];
                j++;
            }
            for(int i=0; i<fi; i++){
                newData[j]=data[i];
                j++;
            }
            delete [] data;
            data=newData;
            ni=capacity;
            fi=0;
            capacity*=2;
        }
        data[ni]=element;
        ni=(ni+1)%capacity;
        if(fi==-1){
            fi=0;
        }
        n++;
    }
    T dequeue(){
        if(n==0){
            cout << "Queue is empty !" << endl;
            return 0;
        }
        T ans=data[fi];
        fi=(fi+1)%capacity;
        n--;
        return ans;
    }
    T front(){
        if(n==0){
            cout << "Queue is empty !" << endl;
            return 0;
        }
        return data[fi];
    }
};

int main(){
    queueArr<int> q(5);
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
    
    cout << q.isEmpty() << endl;
}
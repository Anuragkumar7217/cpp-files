#include<bits/stdc++.h>
using namespace std;

class Deque{
    int *data;
    int fi, fni;
    int ri, rni;
    int capacity;
    int size;

    public:
    Deque(int n){
        data=new int[n];
        capacity=n;
        fi=-1;
        fni=0;
        ri=-1;
        rni=n-1;
        size=0;
    }
    void insertFront(int element){
        if(size==capacity-1){
            cout << -1 << endl;
            return;
        }
        data[fni]=element;
        fni=(fni+1)%capacity;
        size++;
    }
    void insertRear(int element){
        if(size==capacity-1){
            cout << -1 << endl;
            return;
        }
        data[rni]=element;
        rni=(rni+1)%capacity;
        size++;
    }
    void deleteFront(){
        if(size==0){
            cout << -1 << endl;
            return;
        }
        fi++;
        size--;
    }
    void deleteRear(){
        if(size==0){
            cout << -1 << endl;
            return;
        }
        ri++;
        size--;
    }
    int getFront(){
        if(size==0){
            return -1;
        }
        return data[fi];
    }
    int getRear(){
        if(size==0){
            return -1;
        }
        return data[ri];
    }
};

template <typename T>
class queueArr{
    T *data;
    int ni;
    int fi;
    int n;
    int capacity;

    public:
    queueArr(int size){
        data=new T[n];
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
    Deque dq(10);
    int choice,input;
    while(true) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                dq.insertFront(input);
                break;
            case 2:
                cin >> input;
                dq.insertRear(input);
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                cout << dq.getFront() << "\n";
                break;
            case 6:
                cout << dq.getRear() << "\n";
                break;
            default:
                return 0;
        }
    }
}
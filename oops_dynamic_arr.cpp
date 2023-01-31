#include<bits/stdc++.h>
using namespace std;

class DynamicArr{
    int *data;
    int ni;
    int capacity;

    public:
    DynamicArr(){
        data=new int[5];
        ni=0;
        capacity=5;
    }
    DynamicArr(DynamicArr const &da1){
        data=new int[da1.capacity];
        for(int i=0; i<da1.ni; i++){
            data[i]=da1.data[i];
        }
        ni=da1.ni;
        capacity=da1.capacity;
    }
    void operator=(DynamicArr const &da1){
        data=new int[da1.capacity];
        for(int i=0; i<da1.ni; i++){
            data[i]=da1.data[i];
        }
        ni=da1.ni;
        capacity=da1.capacity;
    }
    void print(){
        for(int i=0; i<ni; i++){
            cout << data[i] <<' ';
        }
        cout << endl;
    }
    void add(int element){
        if(ni==capacity){
            int *temp=new int[2*capacity];
            for(int i=0; i<capacity; i++){
                temp[i]=data[i];
            }
            delete [] data;
            data=temp;
            capacity*=2;
        }
        data[ni]=element;
        ni++;
    }
    void add(int i, int element){
        if(i<ni){
            data[i]=element;
        }else if(ni==i){
            add(element);
        }else{
            return;
        }
    }
};

int main(){
    int n;
    cin >> n;
    int *arr=new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    DynamicArr da1;
    for(int i=0; i<n; i++){
        da1.add(arr[i]);
    }
    da1.print();
    DynamicArr da2(da1);
    DynamicArr da3;
    da3=da1;
    da2.print();
    da3.print();
    da1.add(0,100);
    da1.add(5,200);
    da1.print();
    da2.print();
    da3.print();
}
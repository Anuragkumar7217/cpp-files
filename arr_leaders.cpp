#include<iostream>
using namespace std;

void leaders(int a[], int n){
    for(int i=0; i<n; i++){
        int val=a[i];
        bool inc=false;
        for(int j=i+1; j<n; j++){
            if(val>=a[j]){
                inc=true;
            }else{
                inc=false;
                break;
            }
        }
        if(inc==true || i==n-1){
            cout << val << ' ';
        }
    }
}

int main(){
    int a[10], n;
    cout << "Enter the no. of inputs :";
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        cout << a[i] << ' ';
    }
    cout << endl;

    leaders(a,n);
}
#include<iostream>
using namespace std;

int rotate_check(int a[], int n){
    bool inc=true;
    for(int i=0; i<n-1; i++){
        if(a[i]<=a[i+1]){
            inc=false;
        }else{
            return i+1;
        }
    }
    if(!inc){
        return 0;
    }
}

int main(){
    int t;
    cout << "Enter the no. of test cases: ";
    cin >> t;
    while(t-->0){
        int n, a[15];
        cout << "Enter the size of an array: ";
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        cout << rotate_check(a,n) << endl;
    }
}
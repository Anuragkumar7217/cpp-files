#include<iostream>
using namespace std;

int binarysearch(int a[], int n, int x){
    int s=0, e=n-1;
    while(s<=e){
        int m=(s+e)/2;
        if(a[m]==x){
            return m;
        }else if(a[m]<x){
            s=m+1;
        }else{          //(a[m]>x)
            e=m-1;
        }
    }
    return -1;
}

int main(){
    int n,a[15];
    cout << "Enter the size of an array: ";
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int x;
    cout << "Enter the no. to be searched: ";
    cin >> x;
    cout << binarysearch(a,n,x) << endl;;
}
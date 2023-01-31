#include<bits\stdc++.h>
using namespace std;

int sum(int a[], int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return a[0];
    }
    int op=a[0];
    return op+sum(a+1,n-1);
}

int main(){
    int n;
    cout << "Enter the size of an array :";
    cin >> n;

    int *a = new int[n];

    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    
    cout << sum(a,n);
    delete [] a;
}
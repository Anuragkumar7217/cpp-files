#include<bits/stdc++.h>
using namespace std;

bool checkno(int a[], int n, int x){
    if(n==1){
        return (a[0]==x) ? true : false;
    }
    if(a[0]==x){
        return true;
    }
    bool check = checkno(a+1, n-1 ,x);
    return check;
}

int main(){
    int n;
    cin >> n;

    int *a = new int[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int x;
    cin >> x;

    if(checkno(a,n,x)){
        cout << "True";
    }else{
        cout << "False";
    }

    delete [] a;
}
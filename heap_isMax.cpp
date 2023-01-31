#include<bits/stdc++.h>
using namespace std;

bool isMaxHeap(int *a, int n){
    int pi=0;
    int lci=1;
    int rci=2;
    while(lci<n){
        if(a[pi]<a[lci] || (a[pi]<a[rci] && rci<n)) return false;
        pi++;
        lci=2*pi+1;
        rci=2*pi+2;
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    int *a=new int[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cout << isMaxHeap(a,n);
    delete [] a;
}
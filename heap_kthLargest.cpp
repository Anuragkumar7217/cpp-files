#include<bits/stdc++.h>
using namespace std;

int kthLargest(int *a, int n, int k){
    priority_queue<int> pq;
    for(int i=0; i<n; i++){
        pq.push(a[i]);
    }
    while(k-->1){
        pq.pop();
    }
    return pq.top();
}

int main(){
    int n;
    cin >> n;
    int *a=new int[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int k;
    cin >> k;
    cout << kthLargest(a,n,k);
    delete [] a;
}
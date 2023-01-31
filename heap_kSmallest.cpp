#include<bits/stdc++.h>
using namespace std;

vector<int> kSmallest(int *a, int n, int k){
    priority_queue<int> pq;
    for(int i=0; i<k; i++){
        pq.push(a[i]);
    }
    for(int i=k; i<n; i++){
        if(a[i]<pq.top()){
            pq.pop();
            pq.push(a[i]);
        }
    }
    vector<int> v;
    while(!pq.empty()){
        v.push_back(pq.top());
        pq.pop();
    }
    return v;
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
    vector<int> v=kSmallest(a,n,k);
    for(int i=0; i<k; i++){
        cout << v[i] <<' ';
    }
    delete [] a;
}
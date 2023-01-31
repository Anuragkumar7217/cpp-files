#include<bits/stdc++.h>
using namespace std;

int buyTicket(int *a, int n, int k){
    queue<int> q;
    priority_queue<int> pq;
    for(int i=0; i<n; i++){
        q.push(i);
        pq.push(a[i]);
    }
    int time=0;
    while(1){
        int i=q.front();
        if(a[i]==pq.top()){
            pq.pop();
            q.pop();
            time++;
            if(i==k) return time;
        }else{
            int temp=q.front();
            q.pop();
            q.push(temp);
        }
    }
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
    cout << buyTicket(a,n,k);
    delete [] a;
}
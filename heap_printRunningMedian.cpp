#include<bits/stdc++.h>
using namespace std;

void printRunningMedian(int *a, int n){
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int i=0; i<n; i++){
        if(maxHeap.empty()){
            maxHeap.push(a[i]);
            cout << a[i] << ' ';
            continue;
        }
        if(a[i]<maxHeap.top()){
            maxHeap.push(a[i]);
            if(maxHeap.size()-minHeap.size()>1){        //abs(,)
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }else{
            minHeap.push(a[i]);
            if(maxHeap.size()-minHeap.size()>1){        //abs(,)
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
        if((maxHeap.size()+minHeap.size())%2==0){
            cout << (maxHeap.top()+minHeap.top())/2 <<' ';
        }else{
            if(maxHeap.size()>minHeap.size()){
                cout << maxHeap.top() <<' ';
            }else{
                cout << minHeap.top() <<' ';
            }
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
    printRunningMedian(a,n);
    delete [] a;
}
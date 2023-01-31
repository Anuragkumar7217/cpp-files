#include<bits/stdc++.h>
using namespace  std;

int maximumProfit(int budget[], int n){
    sort(budget,budget+n);
    int *output=new int[n];
    for(int i=0; i<n; i++){
        output[i]=budget[i]*(n-i);
    }
    int max=-9999;
    for(int i=0; i<n; i++){
        if(output[i]>max) max=output[i];
    }
    return max;
}

int main(){
    int n;
    cin >>n;
    int *budget=new int[n];
    for(int i=0; i<n; i++){
        cin >>budget[i];
    }
    cout <<maximumProfit(budget,n);
}
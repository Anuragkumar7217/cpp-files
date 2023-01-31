#include<bits/stdc++.h>
using namespace std;

int highestFrequency(int a[], int n){
    unordered_map<int,int> um;
    for(int i=0; i<n; i++){
        if(um.count(a[i])==0){
            um[a[i]]=1;
        }else{
            um[a[i]]+=1;
        }
    }
    int max=0, ans;
    for(int i=0; i<n; i++){
        if(um[a[i]]>max){
            max=um[a[i]];
            ans=a[i];
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    int *a=new int[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cout << highestFrequency(a,n);
    delete [] a;
}
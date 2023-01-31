#include<bits/stdc++.h>
using namespace std;

void intersection(int a1[], int a2[], int n, int m){
    unordered_map<int,int> um;
    for(int i=0; i<n; i++){
        um[a1[i]]++;
    }
    sort(a2,a2+m);
    for(int i=0; i<m; i++){
        if(um[a2[i]]>0){
            cout << a2[i] <<' ';
            um[a2[i]]--;
        }
    }
}

int main(){
    int n;
    cin >> n;
    int *a1=new int[n];
    for(int i=0; i<n; i++){
        cin >> a1[i];
    }
    int m;
    cin >> m;
    int *a2=new int[m];
    for(int i=0; i<m; i++){
        cin >> a2[i];
    }
    intersection(a1,a2,n,m);
    delete [] a1;
    delete [] a2;
}
#include<bits/stdc++.h>
using namespace std;

int pairSum(int a[], int n){
    unordered_map<int,int> m;
    int count=0;
    for(int i=0; i<n; i++){
        if(m[-a[i]]>0){
            count+=m[-a[i]];
        }
        m[a[i]]++;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << pairSum(a, n);
    delete[] a;
}
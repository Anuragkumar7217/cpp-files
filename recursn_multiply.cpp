#include<bits/stdc++.h>
using namespace std;

int multiply(int m, int n){
    if(n==0){
        return 0;
    }
    int ans = multiply(m,n-1);
    if(n>0){
        ans=ans+m;
    }
    return ans;
}

int main(){
    int m,n;
    cin >> m >> n;

    cout << multiply(m,n);
}
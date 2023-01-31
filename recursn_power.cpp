#include<bits/stdc++.h>
using namespace std;

int power(int x, int n){
    if(n==0){
        return 1;
    }
    if(n==1){
        return x;
    }
    int ans= power(x,n-1);
    return ans*x;
}

int main(){
    int x,n;
    cout << "Enter the num and power :";
    cin >> x >> n;

    cout << power(x,n);
}
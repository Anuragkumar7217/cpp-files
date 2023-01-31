#include<bits/stdc++.h>
using namespace std;

int count(int n){
    if(n==0){
        return 0;
    }
    int ans = count(n/10);
    return ans +1;
}

int main(){
    int n;
    cout << "Enter the no. of inputs :";
    cin >> n;

    cout << count(n);
}
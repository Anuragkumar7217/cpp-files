#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    if(n==0){
        return 1;
    }
    int pnum= factorial(n-1);
    return n*pnum;
}

int main(){
    int n;
    cout << "Enter the number :";
    cin >> n;

    cout << factorial(n);
}
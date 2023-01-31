#include<bits/stdc++.h>
using namespace std;

int fib(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    int op1 = fib(n-1);
    int op2 = fib(n-2);
    return op1 + op2;
}

int main(){
    int n;
    cout << "Enter the number :";
    cin >> n;
    
    cout << fib(n); 
}
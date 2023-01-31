#include<bits/stdc++.h>
using namespace std;

bool helper(int input[], int n, int sum5, int sum3){
    if(n==0) return sum5==sum3;
    if(input[0]%5==0) sum5+=input[0];
    else if(input[0]%3==0) sum3+=input[0];
    else return helper(input+1,n-1,sum5+input[0],sum3) || helper(input+1,n-1,sum5,sum3+input[0]);
    return helper(input+1,n-1,sum5,sum3);
}

bool splitArray(int input[], int n){
    helper(input,n,0,0);
}

int main(){
    int n;
    cin >>n;
    int *input=new int[n];
    for(int i=0; i<n; i++){
        cin >>input[i];
    }
    cout << splitArray(input,n);
}
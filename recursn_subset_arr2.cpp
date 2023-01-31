#include<bits/stdc++.h>
using namespace std;

void helper(int input[], int n, int output[], int m){
    if(n==0){
        for(int i=0; i<m; i++){
            cout <<output[i] <<' ';
        }
        cout << endl;
        return;
    }
    int smalloutput[10],k=0;
    for(int j=0; j<m; j++){
        smalloutput[k]=output[j];
        k++;
    }
    smalloutput[k]=input[0];
    helper(input+1,n-1,smalloutput,m+1);
    helper(input+1,n-1,output,m);
}

void printSubsetsOfArray(int input[], int n){
    int output[10];
    int m=0;
    helper(input,n,output,m);
}

int main(){
    int n, input[10];
    cin >>n;
    for(int i=0; i<n; i++){
        cin >>input[i];
    }
    printSubsetsOfArray(input,n);
}
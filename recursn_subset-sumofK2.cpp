#include<iostream>
using namespace std;

void helper(int input[], int n, int output[], int osize, int k){
    if(n==0){
        if(k==0){
            for(int i=0; i<osize; i++){
                cout <<output[i] <<' ';
            }
            cout <<endl;
        }
        return;
    }
    helper(input+1,n-1,output,osize,k);
    int smalloutput[50];
    if(k>0){
        int j;
        for(j=0; j<osize; j++){
        smalloutput[j]=output[j];
        }
        smalloutput[j]=input[0];
    }
    helper(input+1,n-1,smalloutput,osize+1,k-input[0]);
}

void printSubsetSumToK(int input[], int n, int k){
    int output[50];
    helper(input,n,output,0,k);
}

int main(){
    int n,input[20],k;
    cin >>n;
    for(int i=0; i<n; i++){
        cin >>input[i];
    }
    cin >>k;
    printSubsetSumToK(input,n,k);
}
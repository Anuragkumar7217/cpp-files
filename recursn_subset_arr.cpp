#include<bits/stdc++.h>
using namespace std;

int subset(int input[], int n, int output[][25]){
    if(n==0){
        output[0][0]=0;
        return 1;
    }
    int size=subset(input+1,n-1,output);
    for(int i=0; i<size; i++){
        output[i+size][0]=1+output[i][0];
        output[i+size][1]=input[0];
        for(int j=1; j<output[i+size][0]; j++){
            output[i+size][j+1]=output[i][j];
        }
    }
    return 2*size;
}

int main(){
    int n,input[15];
    cin >>n;
    for(int i=0; i<n; i++){
        cin >>input[i];
    }
    int output[25][25];
    int size = subset(input,n,output);
    for(int i=0; i<size; i++){
        for(int j=1; j<=output[i][0]; j++){
            cout <<output[i][j] <<' ';
        }
        cout <<endl;
    }
}
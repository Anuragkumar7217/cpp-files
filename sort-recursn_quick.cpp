#include<bits/stdc++.h>
using namespace std;

int partition(int input[], int si, int ei){
    int x=input[si];
    int count=0;
    for(int i=si+1; i<=ei; i++){
        if(x>=input[i]) count++;
    }
    int swap=input[count+si];
    input[count+si]=input[si];
    input[si]=swap;
    int i=si, j=ei;
    while(i<(count+si) && j>(count+si)){
        if(input[i]<=x){
            i++;
        }else if(input[j]>x){
            j--;
        }else{
            int temp=input[i];
            input[i]=input[j];
            input[j]=temp;
            i++;
            j--;
        }
    }
    return count+si;
}

void helper(int input[], int si, int ei){
    if(si>=ei) return;
    int dev= partition(input,si,ei);
    helper(input,si,dev-1);
    helper(input,dev+1,ei);
}

void quickSort(int input[], int n){
    if(n==0 || n==1) return;
    helper(input,0,n-1);
}

int main(){
    int n;
    cin >> n;
    int *input=new int[n];
    for(int i=0; i<n; i++){
        cin >> input[i];
    }
    quickSort(input,n);
    for(int i=0; i<n; i++){
        cout << input[i] << ' ';
    }
    delete [] input;
}
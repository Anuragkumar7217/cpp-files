#include<bits/stdc++.h>
using namespace std;

void sort(int a[], int si, int mid, int ei){
    int copy[ei-si+1];
    int i=si, j=mid+1, k=0;
    while(i<=mid && j<=ei){
        if(a[i]<a[j]){
            copy[k]=a[i];
            k++;
            i++;
        }else{
            copy[k]=a[j];
            k++;
            j++;
        }
    }
    while(i<=mid){
        copy[k]=a[i];
        k++;
        i++;
    }
    while(j<=ei){
        copy[k]=a[j];
        k++;
        j++;
    }
    for(int i=si, k=0; k<(ei-si+1); k++){
        a[i]=copy[k];
        i++;
    }
}

void helper(int a[], int si, int ei){
    if(si>=ei) return;
    int mid=(si+ei)/2;
    helper(a,si,mid);
    helper(a,mid+1,ei);
    sort(a,si,mid,ei);
}

void pairSum(int a[], int n, int x){
    helper(a,0,n-1);
    int i=0, j=n-1;
    while(i<j){
        int sum=a[i]+a[j];
        if(sum<x){
            i++;
            j=n-1;
        }else if(sum>x){
            j--;
        }else{
            cout <<a[i] <<' ' <<a[j] <<endl;
            j--;
        }
        if(i==j){
            i++;
            j=n-1;
        }
    }
}

int main(){
    int n,a[15],x;
    cin >>n;
    for(int i=0; i<n; i++){
        cin >>a[i];
    }
    cin >>x;
    pairSum(a,n,x);
}
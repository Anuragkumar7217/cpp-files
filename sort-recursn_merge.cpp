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
    int mid=(si+ei)/2;                      //sort(a,a+n);
    helper(a,si,mid);
    helper(a,mid+1,ei);
    sort(a,si,mid,ei);
}

void mergeSort(int a[], int n){
    if(n==0 || n==1) return;
    helper(a,0,n-1);
}

int main(){
    int n;
    cin >> n;
    int *a=new int[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    mergeSort(a,n);
    for(int i=0; i<n; i++){
        cout << a[i] << ' ';
    }
    delete [] a;
}
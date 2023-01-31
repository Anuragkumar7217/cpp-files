#include<bits/stdc++.h>
using namespace std;

void heapSort(int *a, int n){
    for(int i=0; i<n; i++){
        int ci=i;
        while(ci>0){
            int pi=(ci-1)/2;
            if(a[pi]>a[ci]){
                int temp=a[pi];
                a[pi]=a[ci];
                a[ci]=temp;
            }else{
                break;
            }
            ci=pi;
        }
    }

    int size=n-1;
    while(size>0){
        int temp=a[size];
        a[size]=a[0];
        a[0]=temp;
        size--;
        int pi=0;
        int lci=1;
        int rci=2;
        while(lci<=size){
            int i=pi;
            if(a[i]>a[lci]) i=lci;
            if(a[i]>a[rci] && rci<=size) i=rci;
            if(i==pi) break;
            int temp=a[pi];
            a[pi]=a[i];
            a[i]=temp;
            pi=i;
            lci=(2*pi)+1;
            rci=(2*pi)+2;
        }
    }
}

int main(){
    int n;
    cin >> n;
    int *a=new int[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    heapSort(a,n);
    for(int i=0; i<n; i++){
        cout << a[i] << ' ';
    }
    delete [] a;
}
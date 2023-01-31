#include<iostream>
using namespace std;

void bubblesort(int a[], int n){
    for(int i=0; i<=n-1; i++){
        for(int j=0; j<n-1-i ;j++){
            if(a[j]>a[j+1]){
                int swap=a[j];
                a[j]=a[j+1];
                a[j+1]=swap;
            }
        }
    }
}

int main(){
    int n,a[15];
    cout << "Enter the size of an array: ";
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    bubblesort(a,n);
    for(int i=0; i<n; i++){
        cout << a[i] << ' ';
    }
}
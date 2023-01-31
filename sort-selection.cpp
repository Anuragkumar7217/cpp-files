#include<iostream>
using namespace std;

void sorting(int a[], int n){
    for(int i=0; i<n-1; i++){
        int min=a[i], minInd=i;
        for(int j=i+1; j<n; j++){
            if(min>a[j]){
                min=a[j];
                minInd=j;
            }
        }
        int swap=a[i];
        a[i]=a[minInd];
        a[minInd]=swap;
    }
}

int main(){
    int a[15],n;
    cout << "Enter the size of an array: ";
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sorting(a,n);
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
}
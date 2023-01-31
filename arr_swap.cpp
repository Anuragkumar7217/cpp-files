#include <iostream>
using namespace std;

void swap(int a[], int n){
    int i=0, j=n-1, swap=0;
    while(i<j){
        swap=a[i];
        a[i]=a[j];
        a[j]=swap;
        i++;
        j--;
    }
}

void swapalternate(int arr[], int size){
    int swap=0;
        for(int i=0; i<size; i=i+2){
            if(size%2==0){
               swap=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=swap;
                }else if(i<size-1){
                    swap=arr[i];
                    arr[i]=arr[i+1];
                    arr[i+1]=swap;
                    }
        }
}

int main(){
    int t;
    cout << "Enter the no. of test cases: ";
    cin >> t;

    while(t-->0){
        int arr[15],n;
        cout << "Enter the size of an array: ";
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        swap(arr,n);                              //Swaping of whole ARRAY
        for(int i=0;i<n;i++){
            cout << arr[i] << ' ';
        }
        cout << endl;
        swapalternate(arr,n);                       //Swaping of alternate elements of an ARRAY
        for(int i=0;i<n;i++){
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
}
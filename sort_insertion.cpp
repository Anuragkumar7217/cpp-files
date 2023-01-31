#include<iostream>
using namespace std;

void insertionsort(int a[], int n){
    for(int i=1; i<n; i++){
        int current=a[i];
        int j;
        for(j=i-1; j>=0; j--){
            if(current<a[j]){
                a[j+1]=a[j];
            }else{
                break;
            }
        }
        a[j+1]=current;
    }
}

int main(){
    int t;
    cout << "Enter the no. of test cases: ";
    cin >> t;
    while(t-->0){
        int a[15],n;
        cout << "Enter the size of an array: ";
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a[i];
        }

        insertionsort(a,n);
        for(int i=0; i<n; i++){
            cout << a[i] << ' ';
        }
        cout << endl;
    }
}
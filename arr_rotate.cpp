#include<iostream>
using namespace std;

void rotate(int a[], int d, int n){
    int temp[100];
	for(int i=0; i<n; i++){
        temp[i]=a[i];
    }
    for(int i=0; i<n; i++){
        a[i]=a[i+d];
    }
    for(int i=n-d, j=0; i<n; i++){
        a[i]=temp[j];
        j++;
    }
    
    /*int temp[100], j=0;
    for(int i=d; i<n; i++){
            temp[j]=a[i];
            j++;
    }
    for(int i=0; i<d; i++){
        temp[j]=a[i];
        j++;
    }
    for(int i=0; i<n; i++){
        a[i]=temp[i];
    }*/
}

int main(){
    int t;
    cout << "Enter the no. of test cases: ";
    cin >> t;
    while(t-->0){
        int n, a[15];
        cout << "Enter the size of an array: ";
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        int d;
        cout << "Enter the value of D: ";
        cin >> d;

        rotate(a,d,n);
        for(int i=0; i<n; i++){
            cout << a[i] << ' ';
        }
        cout << endl;
    }
}
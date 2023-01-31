#include<iostream>
using namespace std;

void merge(int a[], int n, int b[], int m, int c[]){
    int i=0, j=0, k=0;
    while(i<n && j<m){
        if(a[i]<b[j]){
            c[k]=a[i];
            i++;
            k++;
        }else{                      //(a[i]>b[j])
            c[k]=b[j];
            j++;
            k++;
        }
    }
    while(i<n){
        c[k]=a[i];
        i++;
        k++;
    }
    while(j<m){
        c[k]=b[j];
        j++;
        k++;
    }
}

int main(){
    int t;
    cout << "Enter the no. of test cases: ";
    cin >> t;
    while(t-->0){
        int a[15],n;
        cout << "Enter the size of 1st array: ";
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a[i];
        }

        int b[15],m;
        cout << "Enter the size of 2nd array: ";
        cin >> m;
        for(int j=0; j<m; j++){
            cin >> b[j];
        }

        int c[50];
        merge(a,n,b,m,c);
        for(int k=0; k<n+m; k++){
            cout << c[k] << ' ';
        }
        cout << endl;
    }
}
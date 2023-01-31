#include<iostream>
using namespace std;

void sort_01(int a[], int n){
    /*int zero=0;
    for(int i=0; i<n; i++){
        if(a[i]== 0){
            zero++;
        }
    }
    for(int i=0; i<n; i++){
        if(i<zero){
            a[i]=0;
        }else{
            a[i]=1;
        }
    }*/

    int i=0, j=n-1;
    while(i<j){
        if(a[i]==0){
            i++;
        }else{
            if(a[j]==0){
                int swap;
                swap=a[i];
                a[i]=a[j];
                a[j]=swap;
                i++;
                j--;
            }else{
                j--;
            }
        }
    }
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

        sort_01(a,n);

        for(int i=0; i<n; i++){
            cout << a[i] << ' ';
        }
        cout << endl;
    }
}
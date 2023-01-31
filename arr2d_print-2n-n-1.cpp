#include<iostream>
using namespace std;

void print_arr(int a[][10], int n, int m){
    int temp=n;
    for(int i=0; i<n ;i++){
        int row=temp;
        while(row>0){
            for(int j=0; j<m; j++){
                cout << a[i][j] << ' ';
            }
            cout << endl;
            row--;
        }
        temp--;
    }
}

int main(){
    int a[10][10], n, m;
    cout << "Enter the no. rows and columns :";
    cin >> n >> m;

    for(int i=0; i<n ;i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }

    print_arr(a,n,m);
}
#include<iostream>
using namespace std;

void spiral_print(int a[][20] ,int m ,int n){
    int count=0;
    int rs=0, re=m-1, cs=0, ce=n-1;
    while(count<m*n){
        for(int i=cs; i<=ce; i++){
            cout << a[cs][i] << ' ';
            count++;
        }
        rs++;
        for(int i=rs; i<=re; i++){
            cout << a[i][ce] << ' ';
            count++;
        }
        ce--;
        for(int i=ce; i>=cs; i--){
            cout << a[re][i] << ' ';
            count++;
        }
        re--;
        for(int i=re; i>=rs; i--){
            cout << a[i][cs] << ' ';
            count++;
        }
        cs++;
    }
}

int main(){
    int a[20][20], m, n;
    cout << "Enter the no. of rows and columns :";
    cin >> m >> n;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }    
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << a[i][j] << ' ';
        }    
        cout << endl;
    }
    cout << endl;

    spiral_print(a,m,n);
}
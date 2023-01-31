#include<iostream>
using namespace std;
int main(){
    int m,n,a[10][10];
    cout << "Enter the no. of rows and columns :";
    cin >> m >> n;

    cout << "Enter the elements :";
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

    for(int j=0; j<n; j++){
        int sum=0;
        for(int i=0; i<m; i++){
            sum+=a[i][j];
        }
        cout << sum << ' ';
    }
}
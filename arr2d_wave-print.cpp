#include<iostream>
using namespace std;

void wave_print(int a[][20], int m, int n){
    for(int j=0; j<n; j++){
        if(j%2==0){
            for(int i=0; i<m; i++){
                cout << a[i][j] << ' ';
            }
        }else{
            for(int i=m-1; i>=0; i--){
                cout << a[i][j] << ' ';
            }
        }
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

    wave_print( a, m, n);
}
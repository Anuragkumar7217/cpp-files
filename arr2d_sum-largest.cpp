#include<iostream>
using namespace std;

void large_rorc(int a[][20], int m, int n){
    int rsum=-2147483648, r=0;
    for(int i=0; i<m; i++){
        int sum=0;
        for(int j=0; j<n; j++){
            sum+=a[i][j];
        }
        if(sum>rsum){
            rsum=sum;
            r=i;
        }
    }
    int csum=-2147483648, c=0;
    for(int j=0; j<n; j++){
        int sum=0;
        for(int i=0; i<m; i++){
            sum+=a[i][j];
        }
        if(sum>csum){
            csum=sum;
            c=j;
        }
    }
    if(rsum<csum){
        cout <<"column " << c << ' ' << csum;
    }else
    {
        cout <<"row " << r << ' ' << rsum;
    }
}

int main(){
    int m,n,a[20][20];
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

    large_rorc(a,m,n);
}
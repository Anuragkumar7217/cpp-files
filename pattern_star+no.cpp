#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "Enetr the number of rows: ";
    cin >> n;

    int i=n;
    while(i>=1){
        int j=1;
        while(j<=i){
            cout << j;
            j++;
        }

        int k=1;
        while(k<=2*(n-i)){
            cout << "*";
            k++;
        }

        int l=2*n, val=i;
        while(l>2*n-i){
            cout << val;
            l--;
            val--;
        }
        cout << endl;
        i--;
    }
}
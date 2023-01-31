#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter the no. of rows: ";
    cin >> n;

    int i=1;
    while(i<=n){
        int k=1;
        while(k<=n-i){
            cout << ' ';
            k++;
        }

        int j=1, print=i;
        while(j<=i){
            cout << print;
            j++;
            print--;
        }

        int l=1;
        while(l<=i-1){
            cout << print+2;
            l++;
            print++;
        }
        cout << endl;
        i++;
    }
}
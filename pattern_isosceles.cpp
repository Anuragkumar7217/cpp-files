#include <iostream>
using namespace std;

int main(){
  /*  int n;
    cout << "Enter the no. of rows:";
    cin >> n;

    int i=1;
    while(i<=n){
        int k=1;
        while(k<=n-i){
            cout << " ";
            k++;
        }

        int j=1;
        while(j<=i){
            cout << j;
            j++;
        }

        int l;
        l=i-1;
        while(l>=1){
            cout << l;
            l--;
        }
        cout << endl;
        i++;
    }*/

    int n;
    cout << "Enter the no. of rows:";
    cin >> n;

    int i=1;
    while(i<=n){
        int k=1;
        while(k<=n-i){
            cout << " ";
            k++;
        }

        int j=1,inc;
        inc=i;
        while(j<=i){
            cout << inc;
            j++;
            inc++;
        }

        int l=1;
        int dec;
        dec=2*i-2;
        while(l<=i-1){
            cout << dec;
            dec--;
            l++;
        }
        cout << endl;
        i++;
    }
}
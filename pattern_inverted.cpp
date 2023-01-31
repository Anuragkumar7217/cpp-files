#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the number of rows:";
    cin >> n;

    if(n%2!=0){
    int i,l=1;
    i=n/2+1;
    while(i>=1){
        int k=1;
        while(k<=l-1){
            cout << " ";
            k++;
        }

        int j=1;
        while(j<=2*i-1){
            cout << "*";
            j++;
        }
        cout << endl;
        i--;
        l++;
    }
    }
}
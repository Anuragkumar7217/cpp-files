#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter the decimal no.: ";
    cin >> n;

    long int ans=0;
    long int mul=1;
    while(n!=0){
        int r;
        r=n%2;
        ans=ans + r*mul;
        n=n/2;
        mul=mul*10;
    }
    cout << ans ;
}
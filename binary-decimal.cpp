#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter the binary no.: ";
    cin >> n;

    int op=0,power=1;
    while(n>0){
        int r=0;
        r=n%10;
        op= op + r*power;
        power=power*2;
        n/=10;
        }

    cout << op;
}
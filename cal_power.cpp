#include <iostream>
using namespace std;
#include<math.h>

int main(){
    int x=0, n=0, i;
    cout << "Enter the value and power:"; 
    cin >> x >> n;
    i=x;

    if(n == 0){
        cout << "1";
    }else{
    while(n>1){
        x=x*i;
        n--;
    }
    cout << x;
    //cout << pow(i,n);
    }
}
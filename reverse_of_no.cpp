#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter the number : ";
    cin >> n;
    
    int op=0,rem;
    while(n>0){
        rem=n%10;
        op= op*10 +rem;
        n/=10;
    }
    cout << op;
}
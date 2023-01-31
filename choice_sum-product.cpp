#include <iostream>
using namespace std;
int main(){
    int n,c;
    cout << "Enter the value and ur choice : ";
    cin >> n;
    cin >> c;

    if(c == 1){
        int sum=0;
        for(int i=1; i<=n; i++){
            sum= sum + i;
        }
        cout << sum;
    }else if(c == 2){
        int product=1;
        for(int j=1; j<=n; j++){
            product= product*j;
        }
        cout << product;
    }else
        cout << "-1";
    
}
#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the number : ";
    cin >> n;
    
    bool devided;
    for(int i=2; i<=n; i++){
        devided=false;
        for(int d=2; d<i; d++){
            if(i%d == 0){
                devided=true;
                break;
                }
            }
        if(devided==false){
            cout << i << endl;
        }
    }
}
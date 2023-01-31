#include <iostream>
using namespace std;
int main(){
    int x;
    cout << "Enter the no. of terms : ";
    cin >> x;

    int val=0;
    for(int i=1; i<=x; i++){
        val= 3*i +2;
        if(val%4 == 0){
            x++;
        }else 
            cout << val << ' ' ;
    }
}
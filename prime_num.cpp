#include<iostream>
using namespace std;

int main(){
    int num, d=2;
    cout << "Enter the Number ";
    cin >> num;

    bool devided = false;
    while(d < num){
        if(num%d ==0){
            cout << "Number is not a prime no." <<endl;
            devided= true;
            break;
        }
        d = d+1;
    }
    if(!devided)
    cout << "Number is a prime no." <<endl;
}
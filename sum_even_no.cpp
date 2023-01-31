#include<iostream>
using namespace std;

int main(){
    int n, i=1, sum=0;
    cout << "Enter the number" <<endl;
    cin >> n;
    
    while(i<=n){
        if(i%2 == 0){
        sum=sum+i;
        }
        i++;
    }
    cout << "Sum is:" << sum <<endl;
}


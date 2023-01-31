#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;

    if(n==0){
        cout << "0";
    }else{
        int i=0,ans=0;
        while(ans<=n){
            i++;
            ans=i*i;
        }
        cout << i-1;
    }
}
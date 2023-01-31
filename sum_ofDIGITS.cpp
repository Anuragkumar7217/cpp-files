#include<iostream>
using namespace std;

int main(){
    int n=0, rem=0, even=0, odd=0;

    cout << "Enter the number:";
    cin >> n;
    
    while(n>0){
        rem = n%10;
        n = n/10;

        if(rem%2 !=0){
            odd=odd+rem;
            rem=0;
        }else{
            even=even+rem;
            rem=0;
        }

    }
    cout <<even <<"\t" <<odd;
}
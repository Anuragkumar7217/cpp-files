#include<iostream>
using namespace std;

bool checkMember(int n){
    int a=1,b=1,c=0;
    while(c<=n){
        c=a+b;
        a=b;
        b=c;
        if(c==n){
            return true;
        }
    }
    return false;
}

int main(){

  int n; 
  cout << "Enter the no.: ";
  cin >> n ;
  if(checkMember(n)){
    cout << "true" << endl;
  }else{
    cout << "false" << endl;
  }
}
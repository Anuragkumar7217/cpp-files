#include<iostream>
using namespace std;
int main(){
    int n,pv,cv;
    cout << "Enter the no. of inputs: ";
    cin >> n;
    cin >> pv;

   bool isDec=true;
    int i=1;
    int flag=0;
    while(i<=n-1){
        cin >> cv;
        if(pv==cv){
            cout << "false";
            flag=1;
            break;
        }else if(cv>pv){
            isDec = false;
        }else if(cv<pv){
            if(isDec == false){
                cout << "false";
                flag=1;
                break;
            }
        }
        pv=cv;
        i++;
    }
    if(flag==0)
        cout << "true";
}
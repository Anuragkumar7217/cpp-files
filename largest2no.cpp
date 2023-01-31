#include<iostream>
using namespace std;
#include <climits>
int main(){
    int n;
    cout << "Enter the no. of inputs :";
    cin >> n;

    int l=INT_MIN, s=INT_MIN, x;
    for(int i=0; i<n; i++){
        cin >> x;
        if(x>l){
            s=l;
            l=x;
        }else if(x>s && x<l){
            s=x;
        }
    }
    cout << s;

    /*int n, pv, cv;
    int l=INT_MIN, s=INT_MIN;
    cout << "Enter the no. inputs: ";
    cin >> n;
    cin >> pv;

    if(n<=1){
        pv =s;
    }

    for(int i=0; i<n-1; i++){
        cin >> cv;
        if(pv>cv){
            if(l<pv){
                l=pv;
                pv=cv;
            }
        }else if(pv<cv){
            if(l<cv){
                pv=l;
                l=cv;
            }else{
                pv=cv;
            }
        }else{
            pv=s;
            break;
        }
    }

    cout << pv;*/
}
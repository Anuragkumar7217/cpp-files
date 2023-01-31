#include<bits/stdc++.h>
using namespace std;

/*int power(int k){
    if(k==1){
        return 2;
    }
    int op=power(k-1);
    return 2*op;
}

double geometricSum(int k){
    if(k==0){
        return 1;
    }
    double ans = geometricSum(k-1);
    return ans + (double)1/power(k);
}*/

double geometricSum(int k){
    if(k==0) return 1;
    return 1/pow(2,k) + geometricSum(k-1);
}

int main(){
    int k;
    cin >> k;
    cout << geometricSum(k);
}
#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "ENter the no. of rows:";
    cin >> n;

    int i=1;
    while(i<=n){
        int j=1;
        char s_ch= 'A'+n-i;
        while(j<=i){
            char ch = s_ch +j-1;
            cout <<ch ;
            j++;
        }
        cout<<endl;
        i++;
    }

}
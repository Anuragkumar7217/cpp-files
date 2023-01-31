#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the nuo. of rows:";
    cin >> n;

    int i=1, val;
    while(i<=n){
        int j=1;
        val=i;
        while(j<=i){
            cout << val;
            j++;
            val-=1;
        }
        cout << endl;
        i++;
    }
}
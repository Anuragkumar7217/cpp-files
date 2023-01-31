#include <iostream>
using namespace std;

int main(){
    int n,n1,n2;
    cout << "Enter the number of rows:";
    cin >> n;

    if(n%2 !=0){
        n1=n/2 +1;
        int i=1;
        while(i<=n1){
            int k=1;
            while(k<=n1-i){
                cout << ' ';
                k++;
            }
            int j=1;
            while(j<=2*i-1){
                cout << "*";
                j++;
            }
            cout << endl;
            i++;
        }

        n2=n/2;
        int a=n2,d=1;
        while(a>=1){
            int b=1;
            while(b<=d){
                cout << ' ';
                b++;
            }
            int c=1;
            while(c<=2*a-1){
                cout << "*";
                c++;
            }
            cout << endl;
            a--;
            d++;
        }

    }
}
#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the number of rows:";
    cin>> n;
    int i=1,val=1;
   while(i<=n){
     int j=1,k=1;
     while(k<= n-i){
       cout << " ";
       k++;
     }
     while(j<=i){
       cout << val;
       j++;
       val++;
     }
     cout <<endl;
     i++;
     val=i;
   }

    /* int n,val=1;
    cin >> n;

    int i=1;
    while(i<=n){
      int j=1;
      while(j<=i){
        cout << val;
        j++;
        val++;
      }
      cout << endl;
      i++;
      val=i;
    }  */
}
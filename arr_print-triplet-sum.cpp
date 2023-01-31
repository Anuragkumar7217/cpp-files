#include<bits/stdc++.h>
using namespace std;

void FindTriplet(int a[], int n, int x){
    sort(a,a+n);
	for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(a[i] +a[j] +a[k] == x){
                    cout <<a[i] <<' ' <<a[j] <<' ' << a[k] <<endl;
                }
            }
        }
    }
}

int main(){
    int n, a[15], x;
    cin >>n;
    for(int i=0; i<n; i++){
        cin >>a[i];
    }
    cin >>x;
    FindTriplet(a,n,x);
}
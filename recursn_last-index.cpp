#include<bits\stdc++.h>
using namespace std;

int lastIndex(int a[], int n, int x){
    if(n==0){
        return -1;
    }
    int ans = lastIndex(a+1, n-1, x) ;
    if(ans != -1){
        return ans+1;
    }
    if(a[0]==x){
        return 0;
    }
    if(ans==-1){
        return -1;
    }
}

int main(){
    int n;
    cin >> n;
    int *a=new int[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int x;
    cin >> x;
    cout << lastIndex(a,n,x);
    delete [] a;
}
#include<bits\stdc++.h>
using namespace std;

int firstIndex(int a[], int n, int x){
    if(n==0){
        return -1;
    }
    if(a[0]==x){
        return 0;
    }
    int ans = firstIndex(a+1, n-1, x);
    if(ans==-1){
        return ans;
    }else{
        return 1+ ans;
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

    cout << firstIndex(a,n,x);
    delete [] a;
}
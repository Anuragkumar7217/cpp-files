#include<bits/stdc++.h>
using namespace std;

int allIndexes(int a[], int n, int x, int op[]){
    if(n==0){
        return 0;
    }
    int ans = allIndexes(a,n-1,x,op);
    if(a[n-1]==x){
        op[ans]=n-1;
        return ans+1;
    }else{
        return ans;
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

    int *op=new int[n];

    int size= allIndexes(a,n,x,op);
    for(int i=0; i<size; i++){
        cout << op[i] << ' ';
    }

    delete [] a;
    delete [] op;
}
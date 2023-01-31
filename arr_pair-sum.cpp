#include<iostream>
using namespace std;

int pairsum(int a[],int n, int x){
    int ans=0;
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            if(k<i){
                if(a[k]+a[i]==x){
                    ans++;
                }
            }
        }
    }
    return ans;
}

int main(){
    int t;
    cout << "Enter the no. of test cases: ";
    cin >> t;

    while(t-->0){
        int n,a[15];
        cout << "Enter the size of an array: ";
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        int x;
        cout << "Enter the value: ";
        cin >> x;

        cout << pairsum(a,n,x) << endl;
    }
}
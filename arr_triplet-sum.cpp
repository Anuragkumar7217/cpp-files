#include<iostream>
using namespace std;

int tripletsum(int a[], int n, int x){
    int ans=0;
	for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(a[i] +a[j]+a[k]==x){
                    if(a[i] +a[j] +a[k] ==x){
                        ans++;
                    }
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
        int n, a[15];
        cout << "Enter the size of an array: ";
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        int x;
        cout << "Enter the value: ";
        cin >> x;

        cout << tripletsum(a,n,x) << endl;
    }
}
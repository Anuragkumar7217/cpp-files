#include<iostream>
using namespace std;

void sumof2arr(int a1[], int n1, int a2[], int n2, int arr[]){
    int n=1+ max(n1,n2);
    int k=n-1;
    int carry=0;
    int i=n1-1,j=n2-1;
    for(; i>=0 && j>=0; i--,j--){
        int ans= a1[i]+ a2[j]+ carry;
        if(ans/10 == 0){
            arr[k]=ans;
            carry=0;
        }else{
            carry= ans/10;
            arr[k] = ans%10;
        }
        k--;
    }

    if(n1==n2){
        arr[k]=carry;
        carry=0;
    }else{
        while(i>=0){
            arr[k]= a1[i]+carry;
            carry=0;
            k--;
            i--;
        }
        while(j>=0){
            arr[k]= a2[j]+carry;
            carry=0;
            k--;
            j--;
        }   
    }
}

int main(){
    int t;
    cout << "Enter the no. of test cases: ";
    cin >> t;

    while(t-->0){
        int n1, a1[15], n2, a2[15];
        cout << "Enter the size of 1st array: ";
        cin >> n1;
        for(int i=0; i<n1; i++){
            cin >> a1[i];
        }
        cout << "Enter the size of 2nd array: ";
        cin >> n2;
        for(int i=0; i<n2; i++){
            cin >> a2[i];
        }

        int n=1+ max(n1,n2), arr[15]={0};
        sumof2arr(a1,n1,a2,n2,arr);
        for(int i=0; i<n; i++)
        {
            cout << arr[i] << ' ';
        }
    }
}
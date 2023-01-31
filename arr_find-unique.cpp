#include<iostream>
using namespace std;

int findunique(int a[], int size){
    int ans=a[0];
    for(int i=1; i<size; i++){
        ans=ans^a[i];
    }
    return ans;

    /*
    bool flag;
    int ans=0;
    for(int i=0; i<size; i++){
        flag = false;
        ans=arr[i];
        for(int j=0; j<size; j++){
            if(i==j){
                flag=true;
                continue;
            }
            if(ans==arr[j]){
                flag=false;
                break;
            }
            if(ans!=arr[j]){
                flag=true;
            }
        }
        if(flag){
        return ans;
        }
    }
    */
}

int main(){
    int t;
    cout << "Enter the no. of test cases: ";
    cin >> t;

    while(t-->0){
        int n, arr[15];
        cout << "Enter the size of an array: ";
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        cout << findunique(arr,n) << endl;
    }
}
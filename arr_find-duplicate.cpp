#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int NoOfduplicates(int arr[], int size){
    int ans=0;
    for(int i=0; i<size; i++){
        ans=ans+arr[i];
    }
    return ans-(((size-2)*(size-1))/2);

    /*
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(arr[i]==arr[j]){
                return arr[i];
            }
        }
    }
    */
    
    /*
    bool flag;
    int ans=0;
    for(int i=0; i<size; i++){
        flag = false;
        ans=arr[i];
        for(int j=0; j<size; j++){
            if(i==j){
                continue;
            }
            if(ans==arr[j]){
                flag=true;
                break;
            }
        }
        if(flag){
        return ans;
        }
    }*/
}

vector<int> duplicateNumbers(int *a, int n){
    vector<int> v;
    unordered_map<int, int> um;
    for(int i=0; i<n; i++){
        if(um.count(a[i])==1) continue;
        um[a[i]]=1;
        v.push_back(a[i]);
    }
    return v;
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
        cout << "No. of duplicate no. is " << NoOfduplicates(arr,n) << endl;
        vector<int> v=duplicateNumbers(arr,n);
        for(int i=0; i<v.size(); i++){
            cout << v[i] <<' ';
        }
    }
}
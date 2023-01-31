#include <iostream>
using namespace std;

int linearSearch(int a[], int n, int val){
    bool ifno=true;
    int ans;
    for(int i=0; i<n; i++){
        if(val==a[i]){
            ans= i;
            ifno=false;
            break;
        }
    }
    if(ifno){
        ans = -1;
    }
    return ans;
}

int main(){
    int t;
    cout << "Enter the no. of search: ";
    cin >> t;
    while(t>0){
        int n;
        cout << "Enter the no. of elements: ";
        cin >> n;
        int arr[20];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        int x;
        cout << "Enter the no. to be searched: ";
        cin >> x;
        cout <<"Index is: " << linearSearch(arr, n, x) << endl ;
        t--;
    }
}
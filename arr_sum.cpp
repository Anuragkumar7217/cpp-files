#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the size of an array: ";
    cin >> n;

    int arr[10];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        //cout << arr[i] << endl;
        ans += arr[i];
    }
    cout << "Sum is: " << ans;
}
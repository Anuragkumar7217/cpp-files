#include<bits/stdc++.h>
using namespace std;

int linearSearch(int *arr, int index, int size, int target){
    if(size==index){
        return -1;
    }
    if(arr[index]==target){
        return index;
    }
    return linearSearch(arr, index+1, size, target);
}

int main(){
    int size, arr[100], target;
    cout << "Enter the size of the array: ";
    cin >> size;
    cout << "Enter the elements of the array: ";
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }
    cout << "Enter the target element: ";
    cin >> target;
    int val=linearSearch(arr, 0, size, target);
    if(val==-1) cout << "Element not found.";
    else cout << "Element found at index: " << val;
    return 0;
}
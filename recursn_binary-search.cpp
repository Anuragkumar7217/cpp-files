#include<bits/stdc++.h>
using namespace std;

int helper(int *input, int s, int e, int element){
    if(s>e) return -1;
    int mid=(s+e)/2;
    if(input[mid]==element){
        return mid;
    }else if(input[mid]>element){
        e=mid-1;
    }else{
        s=mid+1;
    }
    return helper(input,s,e,element);
}

int binarySearch(int input[], int size, int element) {
	if(size==0) return -1;
    return helper(input,0,size-1,element);
}

int main(){
    int n,element;
    cin >> n;
    int *input=new int[n];
    for(int i=0; i<n; i++){
        cin >> input[i];
    }
    cin >> element;
    cout << binarySearch(input,n,element);
    delete [] input;
}
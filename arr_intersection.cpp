#include<iostream>
using namespace std;

void sort(int a[], int si, int mid, int ei){
    int copy[ei-si+1];
    int i=si, j=mid+1, k=0;
    while(i<=mid && j<=ei){
        if(a[i]<a[j]){
            copy[k]=a[i];
            k++;
            i++;
        }else{
            copy[k]=a[j];
            k++;
            j++;
        }
    }
    while(i<=mid){
        copy[k]=a[i];
        k++;
        i++;
    }
    while(j<=ei){
        copy[k]=a[j];
        k++;
        j++;
    }
    for(int i=si, k=0; k<(ei-si+1); k++){
        a[i]=copy[k];
        i++;
    }
}

void helper(int a[], int si, int ei){
    if(si>=ei) return;
    int mid=(si+ei)/2;
    helper(a,si,mid);
    helper(a,mid+1,ei);
    sort(a,si,mid,ei);
}

void intersection(int a1[], int n1, int a2[], int n2){
    helper(a1,0,n1-1);
    helper(a2,0,n2-1);
    int i=0, j=0;
    while(i<n1 && j<n2){
        if(a1[i]==a2[j]){
            cout <<a1[i] <<endl;
            i++;
            j++;
        }else if(a1[i]>a2[j]){
            j++;
        }else{
            i++;
        }
    }
}

/*
void intersection(int a1[], int n1, int a2[], int n2){
    for(int i=0; i<n1; i++){
        for(int j=0; j<n2; j++){
            if(a1[i]==a2[j]){
                cout << a1[i] <<endl;
                a2[j]=-999999;
                break;
            }
        }
    }
}
*/

int main(){
    int t;
    cout << "Enter the no. of test cases: ";
    cin >> t;

    while(t-->0){
        int a1[15], a2[15],n1,n2;
        cout << "Enter the size of an arr1: ";
        cin >> n1;
        for(int i=0; i<n1; i++){
            cin >> a1[i];
        }

        cout << "Enter the size of an arr2: ";
        cin >>n2;
        for(int j=0; j<n2; j++){
            cin >> a2[j];
        }

        intersection(a1,n1,a2,n2);
    }
}
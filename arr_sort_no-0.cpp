#include<iostream>
using namespace std;

void push0end(int a[], int n){
    /*int i=0, k=0;
    int temp[100000]={0};
    while(i<n){
        if(a[i]!=0){
            temp[k]=a[i];
            k++;
    }
    i++;
    }
    for(int i=0; i<n; i++){
        a[i]=temp[i];
    }*/

    int j=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=0)
        {
            int temp=a[j];
            a[j]=a[i];
            a[i]=temp;
            j++;
        }
    }

}

int main(){
    int a[15],n;
    cout << "Enter the size of an array: ";
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    push0end(a,n);
    for(int i=0; i<n; i++){
        cout << a[i] << ' ';
    }
}
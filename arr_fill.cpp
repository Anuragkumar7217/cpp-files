#include<iostream>
using namespace std;

void arrange(int a[], int n){
    
    int odd=1,i, k=(n-1)/2;
    for(i=0; i<=k; i++){
            a[i]=odd;
            odd=odd+2;
        }
    int even=n;
    for(i=k+1; i<n; i++){
            if(n%2==0){
                a[i]=even;
                even=even-2;
            }else{
                a[i]=even-1;
                even=even-2;
            }
        }

    /*int k=0;
    int x=n-1;
    for(int i=1;i<=n;i++)                                                                                                                                                                 
    {
        if(i%2!=0)
        {
            a[k]=i;
            k++;
        }
        else
        {
            a[x]=i;
            x--;
        }
    }*/
}

int main(){
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;
    while(t>0){
        int n;
        cout << "Enter the size of an array: ";
        cin >> n;
        int arr[15];
        
        arrange(arr, n);
        for(int i=0; i<n; i++){
            cout << arr[i] << ' ';
        }
        cout << endl;
        t--;
    }
}
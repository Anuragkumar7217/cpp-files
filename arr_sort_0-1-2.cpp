#include<iostream>
using namespace std;

void sort_012(int a[], int n)
{
    /*int i=0, j=n-1, z=0, t=n-1;
    int temp[n];
    while(i<n)
    {
        if(a[i]==0){
            temp[z]=a[i];
            i++;
            z++;
        }else if(a[i]==2){
            temp[t]=a[i];
            i++;
            t--;;
        }else{
            i++;
        }
    }

    while(z<=t)
    {
        temp[z]=1;
        z++;
    }

    for(int i=0; i<n; i++)
    {
        a[i]=temp[i];
    }*/

    int i=0,j=n-1,k=0;
    while(k<=j)
    {
        if(a[k]==0)
        {
            int swap=a[i];
            a[i]=a[k];
            a[k]=swap;
            i++;
            k++;
        }else if(a[k]==2)
        {
            int swap=a[j];
            a[j]=a[k];
            a[k]=swap;
            j--;
        }else
        {
            k++;
        }
        
    }
}

int main()
{
    int t;
    cout << "Enter the no. of test cases: ";
    cin >> t;

    while(t-->0)
    {
        int n, a[15];
        cout << "Enter the size of an array: ";
        cin >> n;
        for(int i=0; i<n; i++)
        {
            cin >> a[i];
        }

        sort_012(a,n);
        for(int i=0; i<n; i++)
        {
            cout << a[i] << ' ';
        }
        cout << endl;
    }
}
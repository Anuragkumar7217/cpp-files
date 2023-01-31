#include<iostream>
using namespace std;
#include<climits>

int _2largest(int a[], int n)
{
    int l=INT_MIN;
    int s=INT_MIN;
    for(int i=0; i<n; i++)
    {
        if(a[i]>s)
        {
            if(a[i]>l)
            {
                s=l;
                l=a[i];
            }else if(a[i]!=l)
            {
                s=a[i];
            }
        }
    }
    return s;
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

        cout << _2largest(a,n) << endl;
    }
}
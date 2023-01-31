#include<iostream>
using namespace std;
int main()
{
    int on;
    cout << "Enter the no. :";
    cin >> on;

    int nn=0, rem=0, temp=on;
    while(on>0)
    {
        rem= on%10;
        nn= (nn*10) +rem;
        on/=10;
    }

    if(temp==nn)
    {
        cout << "It is a Palindrome no.";
    }else
    {
        cout << "It is not a Palindrome no.";
    }
    
}
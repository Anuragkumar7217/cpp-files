#include<iostream>
using namespace std;

bool palindrome(char str[])
{
    int i=0, j=100;
    int copy[j];
    while(str[i]!='\0')
    {
        copy[j]=str[i];
        j--;
        i++;
    }

    i=0;
    for(j=j+1; j<=100; j++)
    {
        if(copy[j]==str[i])
        {
            i++;
        }else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char str[10];
    cout << "Enter input :";
    cin >> str;

    if(palindrome(str))
    {
        cout << "It is palindrome.";
    }else
    {
        cout << "It is not palindrome.";
    }
}
#include<iostream>
using namespace std;

void replace(char str[], char c1, char c2)
{
    for(int i=0; str[i]!='\0'; i++)
    {
        if(str[i]==c1)
        {
            str[i]=c2;
        }
    }
}

int main()
{
    char str[10];
    cout << "Enter input :";
    cin >> str;
    char c1,c2;
    cout << "Enter c1 and c2 for swap :";
    cin >> c1 >> c2;
    replace(str,c1,c2);
    cout << str;
}
#include<bits/stdc++.h>
using namespace std;

int stringToNumber(char input[]){
    int l=strlen(input);
    if(l==1) return input[0]-48;      //-'0';
    return (input[0]-48)*pow(10,l-1) + stringToNumber(input+1);
}

int main(){
    char input[20];
    cin >> input;
    cout << stringToNumber(input);
}
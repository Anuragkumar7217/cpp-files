#include<bits/stdc++.h>
using namespace std;

bool helper(char input[], int s, int e){
    if(s>=e) return true;
    if(input[s]!=input[e]) return false;
    return helper(input,s+1,e-1);
}

bool checkPalindrome(char input[]){
    int s=0, e= strlen(input) -1;
    if(e==0 || e==1) return true;
    return helper(input,s,e);
}

int main(){
    char input[50];
    cin >> input;
    (checkPalindrome(input)) ? cout << "true" : cout << "false";
}
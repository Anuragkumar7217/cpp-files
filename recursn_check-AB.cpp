#include<bits/stdc++.h>
using namespace std;

bool helper(char input[]){
    if(strlen(input)==0) return true;
    if(input[0]=='b' && input[1]!='b') return false;
    if(input[0]=='b' && input[1]=='b') input+=1;
    return helper(input+1);
}

bool checkAB(char input[]){
    if(strlen(input)==0) return true;
    if(input[0]=='b') return false;
    return helper(input+1);
}

int main(){
    char input[50];
    cin >> input;
    (checkAB(input)) ? cout << "true" : cout << "false";
}
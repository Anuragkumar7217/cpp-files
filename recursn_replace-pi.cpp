#include<bits/stdc++.h>
using namespace std;

void replacePi(char input[]){
    int l=strlen(input);
    if(l<=1) return;
    if(input[0]=='p' && input[1]=='i'){
        for(int i=l+1; i>1; i--){
            input[i+2]=input[i];
        }
        input[0]='3';
        input[1]='.';
        input[2]='1';
        input[3]='4';
    }
    return replacePi(input+1);
}

int main(){
    char input[20];
    cin.getline(input,20);
    replacePi(input);
    cout << input;
}
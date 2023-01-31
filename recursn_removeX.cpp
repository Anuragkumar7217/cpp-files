#include<bits/stdc++.h>
using namespace std;

void removeX(char input[]){
    int l =strlen(input);
    if(l==0) return;
    if(input[0]=='x'){
        for(int i=0; i<l; i++){
            input[i]=input[i+1];
        }
        removeX(input);
    }
    return removeX(input+1);
}

int main(){
    char input[20];
    cin.getline(input,20);
    removeX(input);
    cout << input;
}
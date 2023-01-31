#include<bits/stdc++.h>
using namespace std;

void pairStar(char input[]){
    int l=strlen(input);
    if(l==1 || l==0) return;
    if(input[0]==input[1]){
        for(int i=l+1; i>1; i--){
            input[i]=input[i-1];
        }
        input[1]='*';
        pairStar(input);
    }
    return pairStar(input+1);
}

int main(){
    char input[20];
    cin.getline(input,20);
    pairStar(input);
    cout << input;
}
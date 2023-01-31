#include<bits/stdc++.h>
using namespace std;

bool checksequenece(char large[], char small[]){
    if(strlen(small)==0) return true;
    if(strlen(large)==0) return false;
    bool ans;
    if(large[0]==small[0]){
        ans=checksequenece(large+1,small+1);
    }else{
        ans=checksequenece(large+1,small);
    }
    return ans;
}

int main(){
    char large[20], small[20];
    cin >>large >>small;
    (checksequenece(large,small)) ? cout <<"true" : cout <<"false";
}
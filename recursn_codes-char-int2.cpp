#include<bits/stdc++.h>
using namespace std;

void helper(string input, string output){
    if(input.size()==0){
        cout << output <<endl;
        return;
    }
    int first=input[0]-'0';
    char firstchar=first+'a'-1;
    helper(input.substr(1),output+firstchar);
    if(input[1]!='\0'){
        int second=first*10 + input[1]-'0';
        if(second>=10 && second<=26){
            char secondchar=second+'a'-1;
            helper(input.substr(2),output+secondchar);
        }
    }
}

void printAllPossibleCodes(string input){
    string output="";
    helper(input,output);
}

int main(){
    string input;
    cin >>input;

    printAllPossibleCodes(input);
    return 0;
}
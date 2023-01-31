#include<bits/stdc++.h>
using namespace std;

void helper(string input, string output){
    if(input.size()==1){
        cout << output+input[0] <<endl;
        return;
    }
    for(int i=0; i<input.size(); i++){
        helper(input.substr(0,i)+input.substr(i+1),output+input[i]);
    }
}

void printPermutations(string input){
    string output;
    helper(input,output);
}

int main(){
    string input;
    cin >>input;

    printPermutations(input);
}
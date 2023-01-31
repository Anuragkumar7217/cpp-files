#include<bits/stdc++.h>
using namespace std;

int countBracketReversals(string input){
    if(input.size()%2!=0) return -1;
    stack<int> s;
    for(int i=0; i<input.size(); i++){
        if(input[i]=='{'){
            s.push(input[i]);
        }else{
            if(s.empty()){
                s.push(input[i]);
            }else if(s.top()=='{'){
                s.pop();
            }else{
                s.push(input[i]);
            } 
        }
    }
    int count=0;
    while(!s.empty()){
        char c1=s.top();
        s.pop();
        char c2=s.top();
        s.pop();
        if(c1==c2){
            count++;
        }else{
            count+=2;
        }
    }
    return count;
}

int main(){
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}
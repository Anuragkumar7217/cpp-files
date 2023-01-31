#include<bits/stdc++.h>
using namespace std;

bool isBalanced(string input){
    stack<char> s;
    for(int i=0; i<input.size(); i++){
        if(input[i]=='(' || input[i]=='{' || input[i]=='['){
            s.push(input[i]);
        }else if(input[i]==')' || input[i]=='}' || input[i]==']'){
            if(s.size()>0){
                if(input[i]==')'){
                    if(s.top()!='(') return false;
                        s.pop();
                }else if(input[i]=='}'){
                    if(s.top()!='{') return false;
                        s.pop();
                }else if(input[i]==']'){
                    if(s.top()!='[') return false;
                        s.pop();
                }
            }else{
                return false;
            }
        }
    }
    return (s.size()==0);
}

int main(){
    string input;
    cin >> input;
    cout << isBalanced(input)?"true":"false";
}
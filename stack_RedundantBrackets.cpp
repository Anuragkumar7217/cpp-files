#include <bits/stdc++.h>
using namespace std;

bool checkRedundantBrackets(string input){
    stack<char> s;
    for(int i=0; i<input.size(); i++){
        if(input[i]!=')'){
            s.push(input[i]);
        }else if(input[i]==')'){
            int count=0;
            while(s.top()!='('){
                count++;
                s.pop();
            }
            s.pop();
            if(count==0 || count==1) return true;
        }
    }
    return false;
}

int main(){
    string input;
    cin >> input;
    cout << checkRedundantBrackets(input)?"true":"false";
}
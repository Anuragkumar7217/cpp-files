#include<bits/stdc++.h>
using namespace std;

string uniqueChar(string str){
    unordered_map<char,int> m;
    string output;
    for(int i=0; i<str.size(); i++){
        if(m[str[i]]==0){
            m[str[i]]++;
            output+=str[i];
        }
    }
    return output;
}

int main(){
    string input;
    cin >> input;
    cout << uniqueChar(input);
}
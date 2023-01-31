#include<iostream>
using namespace std;
#include<string>

string compress(string str){
    string ans;
    int i=0, count=1;
    char val=str[0];
    i=1;
    while(i < str.size()){
        if(val==str[i]){
            count++;
        }else if(val!=str[i] && count!=1){
            ans+=val;
            ans+=char(count+48);
            val=str[i];
            count=1;
        }else{
            ans+=val;
            val=str[i];
        }
        i++;
    }
    ans+=val;
    if(count!=1){
        ans+=char(count+48);
    }
    return ans;
}

int main(){
    string inp;
    cout << "Enter the input :";
    cin >> inp;

    cout << compress(inp);
}
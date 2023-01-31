#include<bits/stdc++.h>
using namespace std;

string m[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","xyz"};
void helper(int num,string output){
    if(num==0){
        cout << output << endl;
        return;
    }
    string count=m[num%10];
    for(int i=0; i<count.size(); i++){
        helper(num/10,count[i]+output);   
    }
}

void printKeypad(int num){
    string output="";
    helper(num,output);
}

int main(){
    int num;
    cin >> num;

    printKeypad(num);
}
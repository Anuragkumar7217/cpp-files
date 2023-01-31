#include<iostream>
#include<string>
#include<math.h>
using namespace std;

int subs(string s, string output[]){
    if(s.size()==0){
        output[0]="";
        return 1;
    }
    int size=subs(s.substr(1),output);
    for(int i=0; i<size; i++){
        output[i+size]=s[0]+output[i];
    }
    return 2*size;
}

int main(){
    string s;
    cin >> s;
    int n= pow(2,s.size());
    string *output=new string[n];
    int size = subs(s,output);
    for(int i=0; i<size; i++){
        cout << output[i] << endl;
    }
    delete [] output;
}
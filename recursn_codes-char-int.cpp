#include<bits/stdc++.h>
using namespace std;

int getcodes(string input, string output[]){
    if(input.size()==0){
        output[0]="";
        return 1;
    }
    int first=input[0]-'0';
    char firstchar=first+'a'-1;
    string output1[50],output2[50];
    int size1=getcodes(input.substr(1),output1);
    int size2=0;
    char secondchar='\0';
    if(input[1]!='\0'){
        int second=first*10+input[1]-'0';
        if(second>=10 && second<=26){
            secondchar=second+'a'-1;
            size2=getcodes(input.substr(2),output2);
        }
    }
    for(int i=0; i<size1; i++){
        output[i]=firstchar+output1[i];
    }
    for(int i=0; i<size2; i++){
        output[i+size1]=secondchar+output2[i];
    }
    return size1+size2;
}

int main(){
    string input;
    cin >>input;

    string output[50];
    int size=getcodes(input,output);
    for(int i=0; i<size; i++){
        cout <<output[i] <<endl;
    }
}
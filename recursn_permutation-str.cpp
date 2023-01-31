#include<bits/stdc++.h>
using namespace std;

int returnPermutations(string input, string output[]){
    if(input.size()==1){
        output[0]=input;
        return 1;
    }
    int size;
    for(int i=0; i<input.size(); i++){
        string smalloutput[50];
    	size=returnPermutations(input.substr(0,i) +input.substr(i+1) ,smalloutput);
        for(int k=0; k<size; k++){
            output[size*i+k]=input[i]+smalloutput[k];
        }
    }
    return input.size()*size;
}

int main(){
    string input;
    cin >>input;

    string output[50];
    int size=returnPermutations(input,output);
    for(int i=0; i<size; i++){
        cout <<output[i] <<endl;
    }
}
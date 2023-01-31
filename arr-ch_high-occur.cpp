#include<iostream>
using namespace std;

char high_occurance(char inp[]){
    /*int l=-1;
    char ans;
    for(int i=0; inp[i]!='\0'; i++){
        int s=0;
        char val=inp[i];
        for(int j=i+1; inp[j]!='\0'; j++){
            if(val==inp[j]){
                s++;
            }
        }
        if(l<s){
            l=s;
            ans=val;
        }
    }
    return ans;*/

    int freq[256]={0};
    for(int i=0; inp[i]!='\0'; i++){
        freq[inp[i]]++;
    }

    int max=-1;
    char ch;
    for(int i=0; inp[i]!='\0' ; i++){
        if(max<freq[inp[i]]){
            max=freq[inp[i]];
            ch = inp[i];
        }
    }
    return ch;
}

int main(){
    char inp[20];
    cout << "Enter the input :";
    cin.getline(inp,20);

    cout << high_occurance(inp);
}
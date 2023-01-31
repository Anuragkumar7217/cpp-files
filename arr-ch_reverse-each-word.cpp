#include<iostream>
using namespace std;
#include<cstring>

void word_reverse(char inp[]){
    int len=strlen(inp);
    int e=0;
    for(int i=0, s=0; i<=len; i++){
        if(inp[i]==' ' || inp[i]=='\0'){
            e=i-1;
            while(s<e){
                int swap=inp[s];
                inp[s]=inp[e];
                inp[e]=swap;
                s++;
                e--;
            }
            s=i+1;
        }
    }
}

int main(){
    char inp[50];
    cout << "Enter the input :";
    cin.getline(inp,50);
    cout << inp << endl;

    word_reverse(inp);
    cout << inp;
}
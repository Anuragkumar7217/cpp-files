#include<iostream>
using namespace std;

int len;
void length(char input[]){
    int i=0;
    while(input[i]!='\0'){
        i++;
    }
    len=i;
}

void reverse(char input[]){
    length(input);
    int i=0, j=len-1;
    while(i<j){
        char swap=input[i];
        input[i]=input[j];
        input[j]=swap;
        i++;
        j--;
    }
}

void sentence_reverse(char input[]){
    reverse(input);
    for(int i=0, s=0; i<=len; i++){
        if(input[i]==' ' || input[i]=='\0'){
            int e= i-1;
            while(s<e){
                int swap=input[s];
                input[s]=input[e];
                input[e]=swap;
                s++;
                e--;
            }
            s=i+1;
        }
    }
}

int main(){
    char input[30];
    cout << "Enter the input :";
    cin.getline(input,30);

    sentence_reverse(input);
    cout << input;
}
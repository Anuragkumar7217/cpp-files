#include<iostream>
using namespace std;

int length(char input[]){
    int i=0;
    while(input[i]!='\0'){
        i++;
    }
    return i;
}

void reverse(char input[]){
    int len= length(input);
    int i=0, j=len-1;
    while(i<j){
        char swap=input[i];
        input[i]=input[j];
        input[j]=swap;
        i++;
        j--;
    }
}

int main(){
    char input[20];
    cout << "Enter the input :";
    cin.getline(input,20);

    reverse(input);
    cout << input;
}
#include<iostream>
using namespace std;

void trimspaces(char input[]){
    int i=0, j=0;
    while(input[i]!='\0'){
        if(input[i]!=' '){
            input[j]=input[i];
            j++;
        }
        i++;
    }
    input[j]='\0';
}

int main(){
    char input[15];
    cout << "Enter input :";
    cin.getline(input,15);

    trimspaces(input);
    cout << input;
}
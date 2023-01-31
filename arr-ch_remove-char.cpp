#include<iostream>
using namespace std;

void remove_char(char inp[],char c){
    int j=0;
    for(int i=0; inp[i]!='\0'; i++){
        if(inp[i]!=c){
            inp[j]=inp[i];
            j++;
        }
    }
    inp[j]='\0';
}

int main(){
    char inp[25], c;
    cout << "Enter the input :";
    cin.getline(inp,50);
    cout << inp << endl;
    cin >> c;

    remove_char(inp,c);
    cout << inp;
}
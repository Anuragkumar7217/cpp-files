#include<iostream>
using namespace std;
#include<cstring>

void remove_duplicates(char inp[]){
    int len=strlen(inp);
    char copy;
    int j=0, i=0;
    copy=inp[i];
    i++;
    while(i<=len){
        if(copy != inp[i] || inp[i]=='\0'){
            inp[j]=copy;
            j++;
            copy=inp[i];
            i++;
        }else{
            i++;
        }
    }
    inp[j]='\0';
}

int main(){
    char inp[20];
    cout << "Enter the input :";
    cin.getline(inp,20);

    remove_duplicates(inp);
    cout << inp;
}
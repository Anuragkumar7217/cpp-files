#include<iostream>
using namespace std;
#include<cstring>

int word_func(char inp[]){
    int no=1;
    for(int i=0; inp[i]!='\0'; i++){
        if(inp[i]==' '){
            no++;
        }
    }
    return no;
}

void min_len(char inp[], char op[]){
    int len=strlen(inp);
    int word= word_func(inp);

    int l=1000, ind=0, i=0;
    while(word-->0){
        int count=0;
        while(inp[i]!=' '){
            count++;
            i++;
        }
        if(count<l){
            l=count;
            ind=i;
        }
        i++;
    }

    int j=0;
    for(int r=ind-l; r<ind; r++){
        op[j]=inp[r];
        j++;
    }
    op[j]='\0';
}

int main(){
    char inp[20], op[20];
    cout << "Enter the input :";
    cin.getline(inp,20);
    cout << inp << endl;

    min_len(inp, op);
    cout << op;
}
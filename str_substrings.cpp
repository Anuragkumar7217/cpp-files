#include<iostream>
using namespace std;
#include<cstring>

void substrings(char inp[]){
    int len=strlen(inp);
    int temp=len;
    int x=0;
    while(temp>0){
        for(int i=0; i<temp; i++){
            int val=x;
            for(int j=0; j<=i; j++){    
                cout << inp[val++];
            }
            cout << endl;
        }
        x++;
        temp--;
    }
}

int main(){
    char inp[20];
    cout << "Enter input :";
    cin.getline(inp,20);

    substrings(inp);
}
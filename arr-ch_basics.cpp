#include<iostream>
using namespace std;
#include<cstring>

int main(){
    char inp1[20], inp2[20];
    cout << "Enter the input :";
    cin.getline(inp1,20);
    cin.getline(inp2,20);

    int len= strlen(inp1);
    cout << "Length :" << len << ' ' << strlen(inp2) << endl;

    if(strcmp(inp1,inp2)==0){
        cout << "compare is True" << endl;
    }else{
        cout << "compare is False" << endl;
    }

    cout << "BEFORE :";
    cout << inp1 << ' ' << inp2 << endl;
    strcpy(inp1,inp2);
    cout << "AFTER :";
    cout << inp1 << ' ' << inp2 << endl;
}
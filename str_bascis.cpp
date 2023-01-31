#include<iostream>
using namespace std;
#include<string.h>

int main(){
    string s;
    getline(cin,s);
    cout << s << endl;
    cout << "Length is:" << s.size() << endl;

    cout << "SubString is :" << s.substr(2,2) << endl;      //s.substr(1) optional
    cout << s.find("ma") << endl;

    string *sp=new string;      //DMA
    *sp="anurag";
    cout << *sp << endl;

    string add;
    add= s+ *sp;
    cout << add << endl;
}
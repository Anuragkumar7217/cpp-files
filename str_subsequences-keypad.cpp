#include<iostream>
using namespace std;
#include<string>

string m[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
int keypad(int num, string output[]){
    string smalloutput[50];
    if(num==0){
        output[0]="";
        return 1;
    }
    int n=num%10;
    int size=keypad(num/10,smalloutput);
    int count=m[n].size();
    int k=0;
    for(int i=0; i<count; i++){
        for(int j=0;j<size;j++){
            output[k++]=smalloutput[j]+m[n][i];
        }
    }
    return k;
}

int main(){
    int num;
    cin >> num;
    string output[100];
    int size=keypad(num,output);
    for(int i=0; i<size; i++){
        cout << output[i] << endl;
    }
}
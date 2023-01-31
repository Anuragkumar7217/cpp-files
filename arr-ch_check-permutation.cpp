#include<iostream>
using namespace std;
#include<cstring>

bool ispermutation(char inp1[], char inp2[]){
    int len1= strlen(inp1);
    int len2= strlen(inp2);
    bool check=true;
    if(len1 == len2){
        for(int i=0; i<len1; i++){
            for(int j=0; j<len2; j++){
                if(inp1[i] == inp2[j]){
                    inp2[j]=0;
                    check=true;
                    break;
                }else{
                    check=false;
                }
            }
            if(!check){
                return false;
            }
        }
    }else{
        return false;
    }
    if(check){
        return true;
    }
}

int main(){
    char inp1[20], inp2[20];
    cout << "Entre the input :";
    cin.getline(inp1,20);
    cin.getline(inp2,20);

    if(ispermutation(inp1, inp2) == 1){
        cout << "True";
    }else{
        cout << "False";
    }
}
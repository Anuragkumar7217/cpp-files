#include<iostream>
using namespace std;

void fah_cel(int s, int e, int w){
    while(s<=e){
        int var=0;
        var=((s-32)*5)/9;
        cout << s << " " << var << endl;
        s+=w;
    }
}

int main(){
    int s,e,w;
    cout << "Enter numbers: ";
    cin >> s >> e >> w;
    fah_cel(s,e,w);
}
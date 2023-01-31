#include<bits/stdc++.h>
using namespace std;

int* stockSpan(int *input, int n){
    int *output=new int[n];
    output[0]=1;
    if(n<=1) return output;
    stack<int> s;
    s.push(0);
    for(int i=1; i<n; i++){
        if(input[i]>input[s.top()]){
            s.pop();
            while(!s.empty()){
                if(input[i]>input[s.top()]){
                    s.pop();
                }else{
                    output[i]=i-s.top();
                    s.push(i);
                    break;
                }
            }
            if(s.empty()){
                output[i]=i+1;
                s.push(i);
            }
        }else{
            output[i]=i-s.top();
            s.push(i);
        }
    }
    return output;
}

int main(){
    int n;
    cin >> n;
    int *input=new int[n];
    for(int i=0; i<n; i++){
        cin >> input[i];
    }
    int *output=stockSpan(input,n);
    for(int i=0; i<n; i++){
        cout << output[i] << ' ';
    }
    delete [] input;
    delete [] output;
}
#include<bits/stdc++.h>
using namespace std;

void reverseStack(stack<int> &input, stack<int> extra){
    if(input.size()==0 || input.size()==1) return;
    int x=input.top();
    input.pop();
    reverseStack(input,extra);
    
    while(!input.empty()){
        extra.push(input.top());
        input.pop();
    }
    input.push(x);
    while(!extra.empty()){
        input.push(extra.top());
        extra.pop();
    }
}

int main(){
    stack<int> input, extra;
    int n, val;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> val;
        input.push(val);
    }
    reverseStack(input,extra);
    while(!input.empty()){
        cout << input.top() << ' ';
        input.pop();
    }
}
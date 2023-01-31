#include<bits/stdc++.h>
using namespace std;

void reverseQueue(queue<int> &input){
    if(input.size()==0 || input.size()==1) return;
    int x=input.front();
    input.pop();
    reverseQueue(input);

    input.push(x);
}

int main(){
    queue<int> input;
    int n, val;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> val;
        input.push(val);
    }
    reverseQueue(input);
    while(!input.empty()){
        cout << input.front() << ' ';
        input.pop();
    }
}
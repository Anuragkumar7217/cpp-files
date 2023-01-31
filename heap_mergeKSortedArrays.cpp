#include<bits/stdc++.h>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>*> v){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i]->size(); j++){
            pq.push(v[i]->at(j));
        }
    }
    vector<int> output;
    while(!pq.empty()){
        output.push_back(pq.top());
        pq.pop();
    }
    return output;
}

int main(){
    int k;
    cin >> k;
    vector<vector<int>*> input;
    for(int i=0; i<k; i++){
        int n;
        cin >> n;
        vector<int> *v=new vector<int>;
        for(int i=0; i<n; i++){
            int val;
            cin >> val;
            v->push_back(val);
        }
        input.push_back(v);
    }
    vector<int> output=mergeKSortedArrays(input);
    for(int i=0; i<output.size(); i++){
        cout << output[i] << ' ';
    }
}
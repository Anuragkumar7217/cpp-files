#include<iostream>
using namespace std;
#include<vector>

int main(){
    vector<int> v;
    int val;
    cout << "Capacity Size" << endl;
    for(int i=0; i<5; i++){
        cin >> val;
        v.push_back(val);
        cout << v.capacity() <<' ';
        cout << v.size() << endl;
    }
    
    v.pop_back();
    for(int i=0; i<v.size(); i++){
        cout << v.at(i) <<' ';
    }
}
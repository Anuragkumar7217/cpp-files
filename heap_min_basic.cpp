#include<bits/stdc++.h>
using namespace std;

class PriprityQueue{
    vector<int> pq;

    public:
    bool isEmpty(){
        return pq.size()==0;
    }
    
    int getSize(){
        return pq.size();
    }

    int getMin(){
        if(isEmpty()) return 0;
        return pq[0];
    }

    void insert(int d){
        pq.push_back(d);
        int ci=pq.size()-1;
        while(ci>0){
            int pi=(ci-1)/2;
            if(pq[ci]<pq[pi]){
                int swap=pq[pi];
                pq[pi]=pq[ci];
                pq[ci]=swap;
            }else{
                break;
            }
            ci=pi;
        }
    }

    int removeMin(){
        int ans=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        int pi=0;
        int lci=1;
        int rci=2;
        while(lci<pq.size()){
            int i=pi;
            if(pq[i]>pq[lci]) i=lci;
            if(pq[i]>pq[rci] && rci<pq.size()) i=rci;
            if(i==pi) break;
            int swap=pq[pi];
            pq[pi]=pq[i];
            pq[i]=swap;
            pi=i;
            lci=2*pi+1;
            rci=2*pi+2;
        }
        return ans;
    }
};

int main(){
    PriprityQueue p;
    p.insert(10);
    p.insert(20);
    p.insert(30);
    p.insert(40);
    cout << p.removeMin();
    cout << p.removeMin();
}
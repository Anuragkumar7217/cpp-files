#include<bits/stdc++.h>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *a, int n){
    unordered_map<int,bool> m;
    unordered_map<int,int> m2;
    for(int i=0; i<n; i++){
        m[a[i]]=true;
        m2[a[i]]=i;
    }
    int start, max=0, mainIndex=0;
    for(int i=0; i<n; i++){
        int l=0;
        int temp;
        int index;
        if(m[a[i]]){
            m[a[i]]=false;
            int num=a[i]+1;
            while(m[num] && m.count(num)==1){
                m[num]=false;
                num++;
                l++;
            }
            num=a[i]-1;
            index=i;
            while(m[num]){
                m[num]=false;
                temp=num;
                num--;
                l++;
            }
            if(num==a[i]-1 && l!=0){
                start=a[i];
                max=l;
            }else if(l>max){
                max=l;
            }
        }
    }
    vector<int> v;
    v.push_back(start);
    v.push_back(max+start);
    return v;
}

int main(){
    int n;
    cin >> n;
    int *a=new int[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    vector<int> v=longestConsecutiveIncreasingSequence(a,n);
    cout << v[0] << ' ' << v[1];
}
#include<bits/stdc++.h>
using namespace std;

template <typename V>
class MapNode{
    public:
    string key;
    V value;
    MapNode* next;

    MapNode(string k, V v){
        key=k;
        value=v;
        next=NULL;
    }
    ~MapNode(){
        delete next;
    }
};

template <typename V>
class ourmap{
    MapNode<V>** buckets;
    int count;
    int numBuckets;

    public:
    ourmap(){
        count=0;
        numBuckets=5;
        buckets=new MapNode<V>*[numBuckets];
        for(int i=0; i<numBuckets; i++){
            buckets[i]=NULL;
        }
    }
    ~ourmap(){
        for(int i=0; i<numBuckets; i++){
            delete buckets[i];
        }
        delete [] buckets;
    }

    int size(){
        return count;
    }

    V getvalue(string k){
        int bucketIndex=getBucketIndex(k);
        MapNode<V> *head=buckets[bucketIndex];
        while(head!=NULL){
            if(head->key=k){
                return head->value;
            }
        }
        return 0;
    }

    private:
    int getBucketIndex(string k){
        int hashCode=0;
        int currentCoeff=1;
        for(int i=k.length()-1; i>=0; i--){
            hashCode+=k[i]*currentCoeff;
            hashCode%=numBuckets;
            currentCoeff*=37;
            currentCoeff%=numBuckets;
        }
        return hashCode%numBuckets;
    }

    void rehash(){
        MapNode<V>** temp=buckets;
        buckets=new MapNode<V>*[2*numBuckets];
        for(int i=0; i<2*numBuckets; i++){
            buckets[i]=NULL;
        }
        numBuckets*=2;
        count=0;
        for(int i=0; i<numBuckets/2; i++){
            MapNode<V>* head=temp[i];
            while(head!=NULL){
                insert(head->key,head->value);
                head=head->next;
            }
        }
        for(int i=0; i<numBuckets/2; i++){
            MapNode<V>* head=temp[i];
            delete head;
        }
        delete [] temp;
    }

    public:
    void insert(string k, V v){
        int bucketIndex=getBucketIndex(k);
        MapNode<V> *head=buckets[bucketIndex];
        while(head!=NULL){
            if(head->key==k){
                head->value=v;
                return;
            }
            head=head->next;
        }
        MapNode<V>* n=new MapNode<V>(k,v);
        head=buckets[bucketIndex];
        n->next=head;
        buckets[bucketIndex]=n;
        count++;
        double loadfactor=(1.0*count)/numBuckets;
        if(loadfactor>0.7){
            rehash();
        }
    }

    V remove(string k){
        int bucketIndex=getBucketIndex(k);
        MapNode<V> *head=buckets[bucketIndex];
        MapNode<V> *prev=NULL;
        while(head!=NULL){
            if(head->key==k){
                if(prev==NULL){
                    buckets[bucketIndex]=head->next;
                }else{
                prev->next=head->next;
                }
                V temp=head->value;
                head->next=NULL;
                delete head;
                count--;
                return temp;
            }
            prev=head;
            head=head->next;
        }
        return 0;
    }
};

int main(){
    ourmap<int> m;
    for(int i=0; i<10; i++){
        char c='0'+i;
        string k="abc";
        k=k+c;
        int v=i+1;
        m.insert(k,v);
    }
    cout << m.size() << endl;
}
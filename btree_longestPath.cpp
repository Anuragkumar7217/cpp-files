#include<bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(T d){
        data=d;
        left=NULL;
        right=NULL;
    }
    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};

BinaryTreeNode<int>* takeInputLevelWise(){
    cout << "Enter root data : ";
    int data;
    cin >> data;
    if(data==-1) return NULL;
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(data);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BinaryTreeNode<int>* front=pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left child of " << front->data << ": ";
        int ldata;
        cin >> ldata;
        if(ldata!=-1){
            BinaryTreeNode<int>* leftNode=new BinaryTreeNode<int>(ldata);
            front->left=leftNode;
            pendingNodes.push(leftNode);
        }
        cout << "Enter right child of " << front->data << ": ";
        int rdata;
        cin >> rdata;
        if(rdata!=-1){
            BinaryTreeNode<int>* rightNode=new BinaryTreeNode<int>(rdata);
            front->right=rightNode;
            pendingNodes.push(rightNode);
        }
    }
    return root;
}

void printLevelWise(BinaryTreeNode<int>* root){
    if(root==NULL) return;
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BinaryTreeNode<int>* front=pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":L:";
        if(front->left!=NULL){
            cout << front->left->data;
            pendingNodes.push(front->left);
        }else{
            cout <<"-1";
        }
        cout << ",R:";
        if(front->right!=NULL){
            cout << front->right->data;
            pendingNodes.push(front->right);
        }else{
            cout <<"-1";
        }
        cout << endl;
    }
}

vector<int>* longestPath(BinaryTreeNode<int>* root){
    if(!root) return NULL;
    if(!root->left && !root->right){
        vector<int> *v=new vector<int>;
        v->push_back(root->data);
        return v;
    }
    vector<int> *l=longestPath(root->left);
    vector<int> *r=longestPath(root->right);
    if(!l){
        r->push_back(root->data);
        return r;
    }else if(!r){
        l->push_back(root->data);
        return l;
    }else{
        if(l->size()<r->size()){
            r->push_back(root->data);
            delete l;
            return r;
        }else{
            l->push_back(root->data);
            delete r;
            return l;
        }
    }
}

int main(){
    BinaryTreeNode<int>* root=takeInputLevelWise();
    printLevelWise(root);
    vector<int>* v=longestPath(root);
    for(int i=0; i<v->size(); i++){
        cout << v->at(i) <<' ';
    }
    delete root;
}
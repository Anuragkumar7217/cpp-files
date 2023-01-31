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

/*
int minimum(BinaryTreeNode<int>* root){
    if(root==NULL) return INT_MAX;
    return min(root->data,min(minimum(root->left),minimum(root->right)));
}

int maximum(BinaryTreeNode<int>* root){
    if(root==NULL) return INT_MIN;
    return max(root->data,max(maximum(root->left),maximum(root->right));
}
*/

/*
pair<int,int> helper(BinaryTreeNode<int>* root){
    if(root==NULL){
        pair<int,int> p;
        p.first=INT_MAX;
        p.second=INT_MIN;
        return p;
    }
    pair<int,int> l=helper(root->left);
    pair<int,int> r=helper(root->right);
    l.first=min(root->data,min(l.first,r.first));
    l.second=max(root->data,max(l.second,r.second));
    return l;
}

bool isBST(BinaryTreeNode<int>* root){
    if(root==NULL) return true;
    pair<int,int> l=helper(root->left);
    pair<int,int> r=helper(root->right);
    if((l.second<root->data && root->data<r.first) && (isBST(root->left) && isBST(root->right))) return true;
    return false;
}
*/

bool isBST(BinaryTreeNode<int>* root, int min=INT_MIN, int max=INT_MAX){
    if(root==NULL) return true;
    if(root->data<min || root->data>max) return false;
    bool l=isBST(root->left,min,root->data-1);
    bool r=isBST(root->right,root->data,max);
    return l&&r;
}

int main(){
    BinaryTreeNode<int>* root=takeInputLevelWise();
    printLevelWise(root);
    cout << isBST(root);
    delete root;
}
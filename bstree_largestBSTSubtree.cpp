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

class ansval{
    public:
    int min;
    int max;
    bool isornot;
    int height;
};

ansval isBST(BinaryTreeNode<int>* root){
    if(root==NULL){
        ansval temp;
        temp.min=INT_MAX;
        temp.max=INT_MIN;
        temp.isornot=true;
        temp.height=0;
        return temp;
    }
    ansval l=isBST(root->left);
    ansval r=isBST(root->right);
    ansval ans;
    if(!l.isornot || !r.isornot || root->data<l.max || root->data>r.min){
        if(l.height>r.height){
            l.isornot=false;
            return l;
        }else{
			r.isornot=false;
            return r;
        }
    }
    ans.min=min(root->data,min(l.min,r.min));
    ans.max=max(root->data,max(l.max,r.max));
    ans.isornot=true;
    ans.height=max(l.height,r.height)+1;
    return ans;
}

int largestBSTSubtree(BinaryTreeNode<int>* root){
    return isBST(root).height;
}

int main(){
    BinaryTreeNode<int>* root=takeInputLevelWise();
    printLevelWise(root);
    cout << largestBSTSubtree(root);
    delete root;
}
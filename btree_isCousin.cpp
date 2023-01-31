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

int depth(BinaryTreeNode<int> *root, int node){
    if(root == NULL) return -1;
    if(node == root->data) return 0;
    int left = depth(root->left, node);
    if(left != -1) return left + 1;
    else{
        int right = depth(root->right, node);
        if(right != -1) return right + 1;
        else return -1;
    }
}

bool isSibling(BinaryTreeNode<int>* root, int p, int q){
    if(root==NULL) return false;
    if(root->left && root->right){
        if(root->left->data==p){
            if(root->right->data==q) return true;
            else return false;
        }else if(root->left->data==q){
            if(root->right->data==p) return true;
            else return false;
        }
    }
    if(root->right) return isSibling(root->right,p,q);
    else return isSibling(root->left,p,q);
}

bool isCousin(BinaryTreeNode<int> *root, int p, int q){
    if(root==NULL) return false;
    return ((depth(root, p) == depth(root, q)) && (!isSibling(root, p, q)));
}

int main(){
    BinaryTreeNode<int>* root=takeInputLevelWise();
    printLevelWise(root);
    int p,q;
    cin >> p >> q;
    cout << isCousin(root,p,q);
    delete root;
}
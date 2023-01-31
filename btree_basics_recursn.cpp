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

BinaryTreeNode<int>* takeInput(){
    cout << "Enter data : ";
    int data;
    cin >> data;
    if(data==-1) return NULL;
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(data);
    root->left=takeInput();
    root->right=takeInput();
    return root;
}

void print(BinaryTreeNode<int>* root){
    if(root==NULL) return;
    cout << root->data << ":L:";
    if(root->left!=NULL) cout << root->left->data;
        else cout << "-1";
    cout << ",R:";
    if(root->right!=NULL) cout << root->right->data;
        else cout << "-1";
    cout << endl;
    print(root->left);
    print(root->right);
}

int main(){
    BinaryTreeNode<int>* root=takeInput();
    print(root);
    delete root;
}
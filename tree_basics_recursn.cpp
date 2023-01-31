#include<bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(int d){
        data=d;
    }

    ~TreeNode(){
        for(int i=0; i<children.size(); i++){
            delete children[i];
        }
    }
};

TreeNode<int>* takeInput(){
    int data;
    cout << "Enter Data :";
    cin >> data;
    TreeNode<int>* root=new TreeNode<int>(data);
    int n;
    cout << "Enter no. of childrens :";
    cin >> n;
    for(int i=0; i<n; i++){
        TreeNode<int>* child=takeInput();
        root->children.push_back(child);
    }
    return root;
}

void printTree(TreeNode<int>* root){
    if(root==NULL) return;
    cout << root->data << ':';
    for(int i=0; i<root->children.size(); i++){
        cout << root->children[i]->data;
        if(i<root->children.size()-1){
            cout << ',';
        }
    }
    cout << endl;
    for(int i=0; i<root->children.size(); i++){
        printTree(root->children[i]);
    }
}

int main(){
    TreeNode<int>* root=takeInput();
    printTree(root);
    delete root;
}
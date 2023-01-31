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

void zigZagOrder(BinaryTreeNode<int>* root){
    if(root==NULL) return;
    stack<BinaryTreeNode<int>*> s1;
    stack<BinaryTreeNode<int>*> s2;
    s1.push(root);
    bool flag=true;
    while(!s1.empty() || !s2.empty()){
        if(flag){
            BinaryTreeNode<int>* node=s1.top();
            s1.pop();
            cout << node->data << ' ';
            if(node->left!=NULL) s2.push(node->left);
            if(node->right!=NULL) s2.push(node->right);
            if(s1.empty()){
                cout << endl;
                flag=false;;
            }
        }else{
            BinaryTreeNode<int>* node=s2.top();
            s2.pop();
            cout << node->data << ' ';
            if(node->right!=NULL) s1.push(node->right);
            if(node->left!=NULL) s1.push(node->left);
            if(s2.empty()){
                cout << endl;
                flag=true;;
            }
        }
    }
}

int main(){
    BinaryTreeNode<int>* root=takeInputLevelWise();
    printLevelWise(root);
    zigZagOrder(root);
    delete root;
}
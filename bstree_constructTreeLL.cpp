#include<bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;
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

template <typename T>
class node{
    public:
    T data;
    node<T> *next;
    node(T d){
        data=d;
        next=NULL;
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

void print(node<int> *head){
    while(head!=NULL){
        cout << head->data <<' ';
        head=head->next;
    }
    cout << endl;
}

pair<node<int>*,node<int>*> helper(BinaryTreeNode<int>* root){
    if(root==NULL){
        pair<node<int>*,node<int>*> p;
        p.first=NULL;
        p.second=NULL;
        return p;
    }
    pair<node<int>*,node<int>*> l=helper(root->left);
    pair<node<int>*,node<int>*> r=helper(root->right);
    node<int> *head=new node<int>(root->data);
    if(l.first==NULL){
        l.first=head;
        l.first->next=r.first;
        if(r.first==NULL) l.second=head;
        else l.second=r.second;
    }else{
        if(r.first!=NULL){
            head->next=r.first;
            l.second->next=head;
            l.second=r.second;
        }else{
            l.second->next=head;
            l.second=head;
        }
    }
    return l;
}

node<int>* constructTree(BinaryTreeNode<int>* root){
    if(root==NULL) return NULL;
    pair<node<int>*,node<int>*> p=helper(root);
    return p.first;
}

int main(){
    BinaryTreeNode<int>* root=takeInputLevelWise();
    printLevelWise(root);
    node<int> *head=constructTree(root);
    print(head);
    delete root;
}
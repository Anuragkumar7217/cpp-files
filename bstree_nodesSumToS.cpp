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

void nodesSumToS(BinaryTreeNode<int>* root, int s){
    if(root==NULL) return;
    vector<int> v;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode<int>* front=q.front();
        q.pop();
        v.push_back(front->data);
        if(front->left!=NULL) q.push(front->left);
        if(front->right!=NULL) q.push(front->right);
    }
    sort(v.begin(),v.end());
    int i=0, j=v.size()-1;
    while(i<j){
        if(v.at(i)+v.at(j)>s){
            j--;
        }else if(v.at(i)+v.at(j)<s){
            i++;
        }else{
            cout << v.at(i) << ' ' << v.at(j) << endl;
            i++;
            j--;
        }
    }
}

int main(){
    BinaryTreeNode<int>* root=takeInputLevelWise();
    printLevelWise(root);
    int s;
    cin >> s;
    nodesSumToS(root,s);
    delete root;
}
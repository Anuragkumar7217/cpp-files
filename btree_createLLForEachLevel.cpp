#include<bits/stdc++.h>
using namespace std;

template <typename T>
class node{
    public:
    T data;
    node *next;
    node(T d){
        data=d;
        next=NULL;
    }
};

void print(node<int> *head){
    while(head!=NULL){
        cout << head->data <<' ';
        head=head->next;
    }
    cout << endl;
}

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

vector<node<int>*> createLLForEachLevel(BinaryTreeNode<int>* root){
    vector<node<int>*> v;
    //if(root==NULL) return v;
    queue<BinaryTreeNode<int>*> q;
    node<int>* head=NULL;
    node<int>* tail=NULL;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        BinaryTreeNode<int>* front=q.front();
        q.pop();
        if(front!=NULL){
            if(front->left!=NULL) q.push(front->left);
            if(front->right!=NULL) q.push(front->right);
            node<int>* n=new node<int>(front->data);
            if(head==NULL){
                head=n;
                tail=n;
                v.push_back(head);
            }else{
                tail->next=n;
                tail=n;
            }
        }else{
            if(!q.empty()){
                q.push(NULL);
                head=NULL;
                tail=NULL;
            }
        }
    }
    return v;
}

int main(){
    BinaryTreeNode<int>* root=takeInputLevelWise();
    printLevelWise(root);
    vector<node<int>*> ans=createLLForEachLevel(root);
    for(int i=0; i<ans.size(); i++){
        print(ans[i]);
    }
    delete root;
}
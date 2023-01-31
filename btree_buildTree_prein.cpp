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

BinaryTreeNode<int>* helper(int *pre, int preS, int preE, int *in, int inS, int inE){
    if(inS>inE) return NULL;
    int rootdata=pre[preS];
    int rootindex=-1;
    for(int i=inS; i<=inE; i++){
        if(in[i]==rootdata){
            rootindex=i;
            break;
        }
    }
    int linS=inS;
    int linE=rootindex-1;
    int rinS=rootindex+1;
    int rinE=inE;
    int lpreS=preS+1;
    int lpreE=linE-linS+lpreS;
    int rpreS=lpreE+1;
    int rpreE=preE;
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootdata);
    root->left=helper(pre,lpreS,lpreE,in,linS,linE);
    root->right=helper(pre,rpreS,rpreE,in,rinS, rinE);
    return root;
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength){
    return helper(preorder,0,preLength-1,inorder,0,inLength-1);
}

int main(){
    int n;
    cin >> n;
    int *preorder=new int[n];
    int *inorder=new int[n];
    for(int i=0; i<n; i++){
        cin >> preorder[i];
    }
    for(int i=0; i<n ;i++){
        cin >> inorder[i];
    }
    BinaryTreeNode<int>* root=buildTree(preorder,n,inorder,n);
    printLevelWise(root);
    delete root;
}
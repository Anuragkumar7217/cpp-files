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

#include<vector>
void Getelementstored(BinaryTreeNode<int> *root,vector<int> &v){          //NOTE
  if(root==NULL) return;
   Getelementstored(root->left,v);
   v.push_back(root->data);
   Getelementstored(root->right,v);   
}

void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    if(root==NULL) return;
	vector<int> arr;
    Getelementstored(root,arr);
    int i=0, j=arr.size()-1;
    while(i<j){
	    if(arr[i]+arr[j]==s){
	        cout << arr[i] << " " << arr[j] << endl;
            i++;
            j--;
        }
        else if(arr[i]+arr[j]>s){
            j--;
        }
        else{
            i++;
        }
    }
}

int main(){
    BinaryTreeNode<int>* root=takeInputLevelWise();
    printLevelWise(root);
    int s;
    cin >> s;
    printNodesSumToS(root,s);
    delete root;
}
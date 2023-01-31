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

TreeNode<int>* takeInputLevelWise(){
    int data;
    cout << "Enter Data :";
    cin >> data;
    TreeNode<int>* root=new TreeNode<int>(data);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        TreeNode<int>* front=pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter the no. of children of " << front->data << ':';
        int n;
        cin >> n;
        for(int i=0; i<n; i++){
            int childData;
            cout << "Enter the data of " << i << "th childern of " << front->data << ':';
            cin >> childData;
            TreeNode<int>* child=new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

void printLevelWise(TreeNode<int>* root){
    if(root==NULL) return;
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        TreeNode<int>* front=pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ':';
        for(int i=0; i<front->children.size(); i++){
            cout << front->children[i]->data;
            if(i<front->children.size()-1){
                cout << ',';
            }
            pendingNodes.push(front->children[i]);
        }
        cout << endl;
    }
}

TreeNode<int>* nextLargerElement(TreeNode<int>* root, int n){
    if(root==NULL) return root;
    TreeNode<int>* ans=NULL;
    if(root->data>n){
        ans=root;
    }
    for(int i=0; i<root->children.size(); i++){
        TreeNode<int>* temp=nextLargerElement(root->children[i],n);
        if(temp!=NULL){
            if(ans!=NULL){
                if(ans->data>temp->data){
                    ans=temp;
                }
            }else{
                ans=temp;
            }
        }
    }
    return ans;
}

int main(){
    TreeNode<int>* root=takeInputLevelWise();
    printLevelWise(root);
    int n;
    cin >> n;
    cout << nextLargerElement(root,n)->data;
    delete root;
}
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

class pairmax{
    public:
    TreeNode<int>* max;
    TreeNode<int>* max2nd;
    pairmax(TreeNode<int>* root){
        max=root;
        max2nd=NULL;
    }
};

pairmax helper(TreeNode<int>* root){
    pairmax p(root);
    for(int i=0; i<root->children.size(); i++){
        pairmax temp=helper(root->children[i]);
        if(p.max->data<temp.max->data){
            if(temp.max2nd==NULL){
                p.max2nd=p.max;
            }else{
                if(temp.max2nd->data<p.max->data){
                    p.max2nd=p.max;
                }else{
                    p.max2nd=temp.max2nd;
                }
            }
            p.max=temp.max;
        }else{
            if(p.max2nd==NULL){
                p.max2nd=temp.max;
            }else{
                if(p.max2nd->data<temp.max->data){
                    p.max2nd=temp.max;
                }
            }
        }
    }
    return p;
}

TreeNode<int>* secondLargest(TreeNode<int>* root){
    if(root==NULL) return root;
    pairmax ans= helper(root);
    if((ans.max!=NULL && ans.max2nd!=NULL) && (ans.max->data==ans.max2nd->data)) return NULL;
    return ans.max2nd;
}

int main(){
    TreeNode<int>* root=takeInputLevelWise();
    printLevelWise(root);
    cout << secondLargest(root)->data;
    delete root;
}
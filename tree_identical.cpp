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

bool isIdentical(TreeNode<int>* root1, TreeNode<int>* root2){
    if(root1==NULL && root2==NULL) return true;
    if(root1==NULL || root2==NULL) return false;
    if(root1->data==root2->data){
        if(root1->children.size()==root2->children.size()){
            for(int i=0; i<root1->children.size(); i++){
                bool ans=isIdentical(root1->children[i],root2->children[i]);
                if(!ans) return ans;
            }
        }else{
            return false;
        }
    }else{
        return false;
    }
    return true;
}

int main(){
    TreeNode<int>* root1=takeInputLevelWise();
    printLevelWise(root1);
    TreeNode<int>* root2=takeInputLevelWise();
    printLevelWise(root2);
    cout << isIdentical(root1,root2);
    delete root1;
    delete root2;
}
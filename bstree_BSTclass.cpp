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

class BST{
    public:
    BinaryTreeNode<int>* root;

    BST(){
        root=NULL;
    }
    ~BST(){
        delete root;
    }

    private:
    BinaryTreeNode<int>* insert(BinaryTreeNode<int>* node, int d){
        if(node==NULL){
            BinaryTreeNode<int> *temp=new BinaryTreeNode<int>(d);
            return temp;
        }
        if(d<node->data){
            node->left=insert(node->left,d);
        }else{
            node->right=insert(node->right,d);
        }
        return node;
    }

    BinaryTreeNode<int>* deleteData(BinaryTreeNode<int>* node, int d){
        if(node==NULL) return NULL;
        if(node->data==d){
            if(node->left==NULL && node->right==NULL){
                delete node;
                return NULL;
            }else if(node->left!=NULL && node->right==NULL){
                BinaryTreeNode<int>* temp=node->left;
                node->left=NULL;
                delete node;
                return temp;
            }else if(node->left==NULL && node->right!=NULL){
                BinaryTreeNode<int>* temp=node->right;
                node->right=NULL;
                delete node;
                return temp;
            }else{
                BinaryTreeNode<int>* min=root->right;
                while(min->left!=NULL){
                    min=min->left;
                }
                int minRight=min->data;
                node->data=minRight;
                node->right=deleteData(node->right,minRight);
                return node;
            }
        }else if(d<node->data){
            node->left=deleteData(node->left,d);
        }else{
            node->right=deleteData(node->right,d);
        }
        return node;
    }

    bool hasData(BinaryTreeNode<int>* node,int d){
        if(node==NULL) return false;
        if(node->data==d) return true;
        if(d<node->data){
            return hasData(node->left,d);
        }else{
            return hasData(node->right,d);
        }
    }

    void printTree(BinaryTreeNode<int>* root){
        if(root==NULL) return;
        cout << root->data << ":";
        if(root->left!=NULL) cout << "L:" << root->left->data << ",";
        if(root->right!=NULL) cout << "R:" << root->right->data;
        cout  << endl;
        printTree(root->left);
        printTree(root->right);
    }

    public:

    void insert(int d){
        root=insert(root,d);
    }

    void deleteData(int d){
        root=deleteData(root,d);
    }

    bool hasData(int d){
        return hasData(root,d);
    }

    void printTree(){
        printTree(root);
    }
};

int main(){
    BST tree;
    tree.insert(8);
    tree.insert(5);
    tree.insert(10);
    tree.insert(2);
    tree.insert(6);
    tree.insert(12);
    tree.printTree();
    cout << tree.hasData(4) << endl;
    tree.deleteData(4);
    tree.deleteData(5);
    tree.printTree();

    /*
    int t;
    cin >> t;
    while(t-->0){
        int d,choice;
        cin >> choice;
        switch(choice){

            case 1:
            cin >> d;
            tree.insert(d);
            break;

            case 2:
            cin >> d;
            tree.deleteData(d);
            break;

            case 3:
            cin >> d;
            cout << tree.hasData(d) << endl;
            break;

            case 4:
            tree.printTree();
            break;

            default:
            break;
        }
    }
    */
}
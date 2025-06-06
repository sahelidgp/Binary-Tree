#include<iostream>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

int findCeil(TreeNode* root,int key){
    int ceil = -1;
    while(root != nullptr){
        if(root->data == key)return key;
        else if(key<root->data) {
            ceil = root ->data;
            root = root->left;
        }
        else {
           
            root= root->right;
        }
    }
    return ceil;
}
int main(){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(6);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(4);
    root->right->left = new TreeNode(11);
    root->right->right  = new TreeNode(14);

    cout<<findCeil(root,8);
}

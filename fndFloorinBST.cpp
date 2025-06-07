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

    int floor(TreeNode* root, int x) {
        // Code here
        int floori = -1;
    while(root != nullptr){
        if(root->data == x)return x;
        else if(x > root->data) {
            floori = root ->data;
            root = root->right;
        }
        else {
           
            root= root->left;
        }
    }
    return floori;
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

    cout<<floor(root,8);
}

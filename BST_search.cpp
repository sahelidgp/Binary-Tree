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
bool search(TreeNode* root,int target){
    
    while(root != nullptr){
        if(root->data == target)return true;
        root = (target < root->data)?root->left:root->right;
    }
    return false;
}
int main(){
    /*
            7
          /  \
         2    8
        / \  /  \
       1   3 6   9
    */

    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left  = new TreeNode(6);
    root->right->right = new TreeNode(9);

    cout<<search(root,1);

}
//https://leetcode.com/problems/diameter-of-binary-tree/
#include<stdio.h>
#include<iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;

    //constructor
    TreeNode(int data){
        this->val = data;
        this->left = nullptr;
        this->right = nullptr;

    }
};
int ans = 0;
int height(TreeNode* root){ //O(n)
    if(root == nullptr)return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int maxHt = leftHeight+rightHeight;
    ans = max(maxHt,ans);
    return max(leftHeight,rightHeight)+1;
}
   
   
    int main(){
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(4);
        root->left->left->left = new TreeNode(9);
        height(root);
        cout<<"The diameter of the tree = > "<<ans<<endl;

    }


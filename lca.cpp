#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<queue>
#include<map>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        this->val = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr){
            return nullptr;
        }
        if(root ->val == p->val || root->val == q->val){
            return root;
        }
        TreeNode* leftLCA = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right,p,q);

        if(leftLCA && rightLCA){
            return root;
        }else if(leftLCA != nullptr){
            return leftLCA;
        }else {
            return rightLCA;
        }
    }
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(9);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    TreeNode* lca =lowestCommonAncestor(root,root->left,root->left->left );
    cout<<lca->val;
}
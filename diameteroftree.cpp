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

    int calcHeight(TreeNode* root){
        if(root == nullptr) return 0;
        int leftHeight = calcHeight(root->left);
        int rightHeight = calcHeight(root->right);

        return max(leftHeight,rightHeight)+1;
    }

    int calcDiam(TreeNode* root){ //O(n^2)
        if(root == nullptr){
            return 0;
        }
        // 2 possible ways 
        //1> the diameter will pass through root
        int rootdiam = calcHeight(root->left)+calcHeight(root->right);

        //2> The diameter will be Either in left or right subtree of the tree
        int leftDiam = calcDiam(root->left);
        int rightDiam = calcDiam(root->right);
        return max(rootdiam,max(leftDiam,rightDiam));
    }
    int main(){
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(4);
        root->left->left->left = new TreeNode(9);

        cout<<"The diameter of the tree = > "<<calcDiam(root)<<endl;

    }


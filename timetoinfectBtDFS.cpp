//https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/
//https://www.geeksforgeeks.org/problems/burning-tree/1
//one pass solution
//tc: O(n)
//sc: O(n)
#include<iostream>
using namespace std;
#include<queue>
#include <unordered_map>
#include <unordered_set>

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
    int result = INT_MIN;
    int solve(TreeNode* root,int start){
        if(root == nullptr)return 0;

        int LH = solve(root->left,start);
        int RH = solve(root->right,start);

        if(root->val == start){
            result = max(result,max(LH,RH));
            return -1;
        }
        else if(LH >=0 && RH >= 0){
            return max(LH,RH)+1;
        }
        else{
            int d = abs(LH)+abs(RH);
            result = max(result,d);
            return min(LH,RH)-1;

        }
        return 0;
    }
    
    int amountOfTime(TreeNode* root, int start) {
        solve(root,start);
        return result;
    }

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(5);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(9);
    root->left->right->right = new TreeNode(2);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(6);

    int start = 3;
    cout<<amountOfTime(root,start);
}
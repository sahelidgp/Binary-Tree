//https://leetcode.com/problems/binary-tree-right-side-view/?source=submission-ac
#include<iostream>
using namespace std;
#include<queue>
#include <map>


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
vector<int> rightSideView(TreeNode* root) {
         vector<int>v;
        if(!root)return v;
        queue<TreeNode*>q;
        q.push(root);
        
        map<int,int>mp;

        int level = 0;
        
        while(!q.empty()){
            int n = q.size();
            while(n--){
            TreeNode* curr = q.front();

            mp[level] = curr->val;
            
            q.pop();
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
            }
            level++;
        }
        for(auto &[key,val]: mp){
            v.push_back(val);
        }
    return v;
    }
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    //root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    //root->right->right = new TreeNode(4);
    vector<int>v = rightSideView(root);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}
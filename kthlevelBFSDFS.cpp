//https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
//combination of bfs and dfs
#include<stdio.h>
#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include<queue>
#include<unordered_set>
#include<bits/stdc++.h>

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
unordered_map<TreeNode* ,TreeNode*>parents;
TreeNode* target_node;
void parent_finder(TreeNode* root,TreeNode* parent){
    if(!root){
        return;
    }
    parents[root] = parent;
    parent_finder(root->left,root);
    parent_finder(root->right,root);
}

void find(TreeNode* root,int target, bool &status){
    if(!root){
        return;
    }
    if(root->val == target and status == false){
        target_node = root;
        status = true;
        return;
    }
    find(root->left,target,status);
    find(root->right,target,status);
}
 vector<int> kDistanceNodes(TreeNode* root,int target,int k){
    parent_finder(root,nullptr);
    queue<pair<TreeNode*,int>>q;
    bool status = false;
    //for finding target node
    find(root,target,status);
    q.push({target_node,k});
    unordered_map<TreeNode*, bool>visited;
    
    vector<int>ans;
    visited[target_node] = true;
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            TreeNode* present = q.front().first;
            int position = q.front().second;
            q.pop();
            if(position == 0){
                ans.push_back(present->val);
            }
            if(present->left && position>0 && !visited[present->left]){
                q.push({present->left,position-1});
                visited[present->left] = true;
            }
            if(present->right && position > 0 && !visited[present->right]){
                q.push({present->right,position-1});
                visited[present->right] = true;
            }
            if(parents[present] && position > 0 && !visited[parents[present]]){
                q.push({parents[present],position-1});
                visited[parents[present]] = true;
            }

        }
    }
    sort(ans.begin(),ans.end());
    return ans;
 }
     int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    vector<int>v = kDistanceNodes(root,2,1);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}
/*
        1
       / \
      2   3
    /  \   \
   7   5    4
    
    */

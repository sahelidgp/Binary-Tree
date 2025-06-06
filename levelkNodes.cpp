//https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/submissions/1651054127/

//MY Approach :)

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
void makeGraph(TreeNode* root,TreeNode* parent,TreeNode* currNode,unordered_map<int ,vector<int>>&adj){
        if(root == nullptr)return;
        if(currNode == nullptr)return;
        if(parent != nullptr){// it is not the root node
            adj[currNode->val].push_back(parent->val);

        }
        if(currNode->left){
            adj[currNode->val].push_back(currNode->left->val);
        }
        if(currNode->right){
            adj[currNode->val].push_back(currNode->right->val);
        }
        makeGraph(root,currNode,currNode->left,adj);
        makeGraph(root,currNode,currNode->right,adj);

    }
    void levelOrder(TreeNode* target,unordered_map<int ,vector<int>>&adj,int k,vector<int>&v,unordered_set<int>vis){
        queue<int>q;
        q.push(target->val);
        vis.insert(target->val);
        int level = 0;
        while(!q.empty()){
            if(level == k)break;
            int n = q.size();
            while(n--){
                int curr = q.front();
                q.pop();
                for(auto it: adj[curr]){
                    if(vis.find(it) == vis.end()){
                    q.push(it);
                    vis.insert(it);
                    }
                }
            }
            level++;
        }

        while(!q.empty()){
            int val = q.front();
            q.pop();
            v.push_back(val);
        }        

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int ,vector<int>>adj;

        makeGraph(root,nullptr,root,adj);
        vector<int>v;
        unordered_set<int>vis;
        levelOrder(target,adj,k,v,vis);
        return v;
    }

    int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    vector<int>v = distanceK(root,root,2);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}
//https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
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
// ordered map find function  tc = o(logn)
// queue => O(n)
//total tc= O(nlogn)
void topView(TreeNode* root){

    queue<pair<TreeNode*,int>>q;
    q.push({root,0});
    

    map<int,TreeNode*>mp;
    mp.insert({0,root});
    while(q.size()){
        TreeNode* curr = q.front().first;
        int d = q.front().second;
        auto key = mp.find(d);
        if(key == mp.end()){
            mp.insert({d,curr});
        }
        q.pop();
        if(curr->left != nullptr){
            q.push({curr->left,d-1});
        }
        if(curr->right != nullptr){
            q.push({curr->right,d+1});
        }
    }

    

    for(auto &[key,value] :mp){
        cout<<mp[key]->val<<" ";
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
    topView(root);
}
//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/submissions/1650042184/

#include<iostream>
using namespace std;
#include<queue>
#include<map>
#include<bits/stdc++.h>
#include<vector>

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
//tc: O(nlogn)     logn for multiset
//sc: O(n)+O(n)      
 vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>>q;
        map<int,map<int,multiset<int>>>mp;
        q.push({root,{0,0}});
        while(q.size()){
            TreeNode* currNode = q.front().first;
            int hd = q.front().second.first;
            int level = q.front().second.second;
            mp[hd][level].insert(currNode->val);
            q.pop();
            if(currNode->left != nullptr){
                q.push({currNode->left,{hd-1,level+1}});
            }
            if(currNode->right != nullptr){
                q.push({currNode->right,{hd+1,level+1}});
            }
            
        }
        vector<vector<int>>ans;

        for(auto p : mp){
            vector<int>col;
            for(auto t: p.second){
                col.insert(col.end(),t.second.begin(),t.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->left->left = new TreeNode(11);
    root->left->left->right = new TreeNode(12);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
     
    vector<vector<int>> v = verticalTraversal(root);

    for(const auto&row : v){
        for(auto val:row){
            cout<<val<<" ";
        }
        cout<<endl;
    }

}


//https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
#include<stdio.h>
#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include<queue>
#include<unordered_set>
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
  unordered_map<TreeNode*, TreeNode*> parent;

    void inOrder(TreeNode* root){
        if(!root) return;

        if(root->left != nullptr){
            parent[root->left] = root;
        }
        inOrder(root->left);
        if(root->right != nullptr){
            parent[root->right] = root;
        }
        inOrder(root->right);
    }

    void BFS(TreeNode* target,int k,vector<int>& result){
        queue<TreeNode*>q;
        q.push(target);

        unordered_set<int> visited;
        visited.insert(target->val);

        while(!q.empty()){
            int n = q.size();

            if(k == 0) break;
            while(n--){
                TreeNode* curr = q.front();
                q.pop();

                //left
                if(curr->left && !visited.count(curr->left->val)){
                    q.push(curr->left);
                    visited.insert(curr->left->val);
                }
                //right
                if(curr->right && !visited.count(curr->right->val)){
                    q.push(curr->right);
                    visited.insert(curr->right->val);
                }
                //parent
                if(parent.count(curr) && !visited.count(parent[curr]->val)){
                    q.push(parent[curr]);
                    visited.insert(parent[curr]->val);
                }
            }
            k--;
        }
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            result.push_back(temp->val);
        }
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        //O(n)
        inOrder(root);
        //O(n)
        BFS(target,k,result);

        return result;
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

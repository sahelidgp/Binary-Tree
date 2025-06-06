//https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/
//https://www.geeksforgeeks.org/problems/burning-tree/1
//Two pass Solution by BFS

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
//O(n)
void makeGraph(unordered_map<int,vector<int>>&adj,int parent,TreeNode* currNode){
    if(currNode == nullptr) return;

    if(parent != -1){
        adj[currNode->val].push_back(parent);
    }
    if(currNode->left){
        adj[currNode->val].push_back(currNode->left->val);
    }
    if(currNode->right){
        adj[currNode->val].push_back(currNode->right->val);
    }
    
    makeGraph(adj,currNode->val,currNode->left);
    makeGraph(adj,currNode->val,currNode->right);
}

int amountOfTime(TreeNode* root, int start){

    unordered_map<int,vector<int>>adj;

    makeGraph(adj,-1,root);
//O(n)
    unordered_set<int>visited;
    queue<int>q;
    q.push(start);
    visited.insert(start);
    int minutes = -1;
    while(!q.empty()){
        int n = q.size();
        while(n--){
            int curr = q.front();
            q.pop();
             for(int &ngbr : adj[curr]){
                    if(visited.find(ngbr) == visited.end()){
                        q.push(ngbr);
                        visited.insert(ngbr);
                    }
                }
        }
        minutes++;
    }
    return minutes;

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
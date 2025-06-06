//https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<queue>
#include<map>

struct Node{
    int val;
    Node* left;
    Node* right;

    Node(int data){
        this->val = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};
// ordered map find function  tc = o(logn)
// queue => O(n)
//total tc= O(nlogn)
//read this https://chatgpt.com/c/683c0fba-00f8-800c-b57f-ec5bb293f178
vector<int> bottomView(Node *root) {
        // Your Code Here
         queue<pair<Node*,int>>q;
        map<int,Node*>mp;
        vector<int>ans;
        
        q.push({root,0});
        
        while(q.size()){
            Node* currNode = q.front().first;
            int hd = q.front().second;
            mp[hd]=currNode;
            q.pop();
            if(currNode->left != nullptr){
                q.push({currNode->left,hd-1});
            }
            if(currNode->right != nullptr){
                q.push({currNode->right,hd+1});
            }
            
        }
         for (auto it : mp) {
        ans.push_back(it.second->val);
    }
        return ans;
    }
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(6);
    root->left->right = new Node(9);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    vector<int>v;
    v = bottomView(root);
    for(auto it : v){
        cout<<it<<" ";
    }
}
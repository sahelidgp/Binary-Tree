#include<stdio.h>
#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include<queue>
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
TreeNode* build(vector<int>& preorder,vector<int>& inorder,int& preIdx,int left ,int right,unordered_map<int,int>&mp){
        if(left>right)return nullptr;
        TreeNode* root = new TreeNode(preorder[preIdx]);
        preIdx++;
        int idx = mp[root->val];
        root->left = build(preorder,inorder,preIdx,left,idx-1,mp);
        root->right = build(preorder,inorder,preIdx,idx+1,right,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        int n = preorder.size();
        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){
            mp.insert({inorder[i],i});
        }
        TreeNode* root = build(preorder,inorder,preIdx,0,n-1,mp);
        return root;
    }

 int main(){
       vector<int>preorder = {3,9,20,15,7};
       vector<int> inorder = {9,3,15,20,7};
       TreeNode* root = buildTree(preorder,inorder);
       queue<TreeNode*>q;
       q.push(root);
        while(!q.empty()){
            int n = q.size();
            while(n--){
            TreeNode* curr = q.front();
             q.pop();
            
            cout<<curr->val<<" ";
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
           
        }
         cout<<endl;
    }
    
    }
//another approach of bfs using null pointer marker
// q.push(root);
// q.push(nullptr); // end-of-level marker
// while (!q.empty()) {
//     TreeNode* curr = q.front();
//     q.pop();
//     if (curr == nullptr) {
//         cout << endl;
//         if (!q.empty()) q.push(nullptr);
//     } else {
//         cout << curr->val << " ";
//         if (curr->left) q.push(curr->left);
//         if (curr->right) q.push(curr->right);
//     }
// }

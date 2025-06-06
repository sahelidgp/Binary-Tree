#include<iostream>
using namespace std;
#include<queue>
#include<string>
#include <sstream> 
//https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
//tc : O(n)
//sc : O(n)
struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};
    string serialize(TreeNode* root) {
        if (!root)
        return "";
        
        queue<TreeNode*>q;
        q.push(root);
        string ans = "";
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr == nullptr) ans.append("#,");
            else {
                ans.append(to_string(curr->data)+',');
            
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return ans;
        
    }
     TreeNode* deserialize(string data) {
        if(data.size() == 0)return nullptr;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            getline(s,str,',');
            if(str == "#"){
                node->left = nullptr;
            }else{
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }
            getline(s,str,',');
            if(str == "#"){
                node->right == nullptr;
            }else{
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
            
        }
        return root;

    }
    int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    cout<<serialize(root)<<endl;

    root = deserialize(serialize(root));
    queue<TreeNode*>q;
       q.push(root);
        while(!q.empty()){
            int n = q.size();
            while(n--){
            TreeNode* curr = q.front();
             q.pop();
            
            cout<<curr->data<<" ";
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
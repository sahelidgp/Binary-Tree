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
vector<int> morrisInorder(TreeNode* root){
    vector<int>ans;
    while(root){
        if(!root->left){
            //if the left subtree does not exist
            ans.push_back(root->val);
            root = root->right;
        }
        else{
            //if the left subtree exist
            // 2 possible cases

            // find the IP -> Inorder predecessor -> the node which comes the rightmost of the left subtree of the root node
            TreeNode* IP = root ->left;
            while(IP->right != nullptr && IP ->right != root){
                IP = IP->right;
            }
            //now check which case is this

            // if the left subtree is not traversed
            if(IP->right == nullptr){
                //create the thread
                IP->right = root;
                //go to the left subtree
                root = root->left;
            }else {
                // the thread is already exists
                // the left subtree is traversed
                //remove the link
                IP->right = nullptr;
                //push back the root data as the left subtree is already traversed
                ans.push_back(root->val);
                // go to the right
                root = root->right;
            }
        }

    }
    return ans;
}


vector<int>morrisPreorder(TreeNode* root){
    vector<int>ans;
    while(root != nullptr){
      
            if(root->left == nullptr){
                ans.push_back(root->val);

                root = root->right;
            }else{
                TreeNode* IP = root->left;
                while(IP->right != nullptr && IP->right != root){
                    IP = IP->right;
                }
                if(IP->right == nullptr){
                    ans.push_back(root->val);
                    IP->right = root;
                    root = root->left;
                }else{
                    IP->right = nullptr;
                    root = root->right;
                }
            
        }
    }
    return ans;
    
}

// post order means [left->right->node]
// so we will do in reverse [node->right->left] just like preOrder
// after that we will return the reverse vector


vector<int> morrisPostorder(TreeNode* root){
    // ans vector to return
    vector<int>ans;
     while(root != nullptr){
      
            // if the right subtree does not exist
            if(root->right == nullptr){
                //add the node value
                ans.push_back(root->val);
                //go to left
                root = root->left;
            }else{
                //find the inorder successor
                TreeNode* IS = root->right;
                while(IS->left != nullptr && IS->left != root){
                    IS = IS->left;
                }
                //here 2 cases are possible 

                //if the right part is not visited
                if(IS->left == nullptr){
                    //push the node's value 
                    ans.push_back(root->val);
                    //create the thread
                    IS->left = root;
                    //move to right
                    root = root->right;
                }else{// if the right subtree is already visited
                    // remove the thread
                    IS->right = nullptr;
                    //as right subtree done so go to the left
                    root = root->left;
                }
            
        }
    }
    // now reverse the ans 
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(8);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(9);
    root->right->right = new TreeNode(6);

    /*
                        1
                      /   \
                    2      3
                   / \      \
                  4   5      6
                 / \   \
                7  8   9
    */
    vector<int>v = morrisPostorder(root);
    for(auto it: v){
        cout<<it<<" ";
    }
}
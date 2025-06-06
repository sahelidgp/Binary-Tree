#include<iostream>
using namespace std;
#include<queue>
#include <unordered_map>
#include <unordered_set>

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
void path(TreeNode* r,vector<int>& v1,vector<vector<int>>& v2){
         if(r!=NULL){
            v1.push_back(r->data);
            if(r->left==NULL&&r->right==NULL){
                v2.push_back(v1);
            }
            path(r->left,v1,v2);
            path(r->right,v1,v2);
            v1.pop_back();
        }
    }
    vector<vector<int>> Paths(TreeNode* root) {
        // code here
        vector<int> v1;
        vector<vector<int>> v2;
        path(root,v1,v2);
        return v2;
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
    vector<vector<int>>ans = Paths(root);
    cout<<"["<<endl;
    for(auto & row: ans){
        cout<<"[";
        for(auto& col:row){
            cout<<col<<" ";

        }
        cout<<"]";
        cout<<endl;
    }
    cout<<"]";
}
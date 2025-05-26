#include<bits/stdc++.h>
#include<vector>
#include<iostream>
using namespace std;
//Height of a Binary tree

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
static int idx = -1;
Node* buildTree(vector<int> preorder){
    idx++;
    if(preorder[idx] == -1){
        return nullptr;
    }

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);  //LEFT
    root->right = buildTree(preorder); //RIGHT

    return root;
}

int height(Node* root){
    if(root == nullptr) return 0;
    return max(height(root->left),height(root->right))+1;
}
int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
        Node* root = buildTree(preorder);
        cout << "Height of the binary tree: " << height(root) << endl;
}
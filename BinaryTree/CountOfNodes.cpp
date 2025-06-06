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

int count(Node* root){
    if(root == nullptr) return 0;
    return (count(root->left)+count(root->right))+1;
}

//sum of tree
int sum(Node* root){
    if(root == nullptr){
        return 0;
    }
    return sum(root->left)+sum(root->right)+root->data;
}
int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
        Node* root = buildTree(preorder);
        cout << "Sum of nodes of the binary tree: " << sum(root) << endl;
}
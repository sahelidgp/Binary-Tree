// Problem statement
// You have been given a Binary Tree of 'N'

// nodes, where the nodes have integer values.



// Your task is to return the ln-Order, Pre-Order, and Post-Order traversals of the given binary tree.



// For example :
// For the given binary tree:

// The Inorder traversal will be [5, 3, 2, 1, 7, 4, 6].
// The Preorder traversal will be [1, 3, 5, 2, 4, 7, 6].
// The Postorder traversal will be [5, 2, 3, 7, 6, 4, 1].
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1 :
// 1 2 3 -1 -1 -1  6 -1 -1
// Sample Output 1 :
// 2 1 3 6 
// 1 2 3 6 
// 2 6 3 1
// Explanation of Sample Output 1 :
//  The given binary tree is shown below:

// Inorder traversal of given tree = [2, 1, 3, 6]
// Preorder traversal of given tree = [1, 2, 3, 6]
// Postorder traversal of given tree = [2, 6, 3, 1]
// Sample Input 2 :
// 1 2 4 5 3 -1 -1 -1 -1 -1 -1
// Sample Output 2 :
// 5 2 3 1 4 
// 1 2 5 3 4 
// 5 3 2 4 1
// Explanation of Sample Output 2 :
// The given binary tree is shown below:

// Inorder traversal of given tree = [5, 2, 3, 1, 4]
// Preorder traversal of given tree = [1, 2, 5, 3, 4]
// Postorder traversal of given tree = [5, 3, 2, 4, 1]
// Constraints :
// 1 <= 'N' <= 10^5
// 0 <= 'data' <= 10^5     

// where 'N' is the number of nodes and 'data' denotes the node value of the binary tree nodes.

// Time limit: 1 sec



// sol


   // Following is Binary Tree Node structure:
   #include<bits/stdc++.h>
   using namespace std;
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
void getInorder(TreeNode * root,vector<int>&inorder){

    if(root == NULL)
    {
        return;
    }
    getInorder(root->left,inorder);
    inorder.push_back(root->data);
    getInorder(root->right,inorder);
}
void getPreorder(TreeNode * root,vector<int>&preorder){

    if(root == NULL)
        return;
    
    preorder.push_back(root->data);
    getPreorder(root->left,preorder);
    getPreorder(root->right,preorder);
}
void getPostorder(TreeNode * root,vector<int>&postorder){

    if(root == NULL)
    {
        return;
    }
    getPostorder(root->left,postorder);
    getPostorder(root->right,postorder);
    postorder.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<vector<int>>ans;
    vector<int>inorder;
    vector<int>preorder;
    vector<int>postorder;
    getInorder(root,inorder);
    getPreorder(root,preorder);
    getPostorder(root,postorder);
    ans.push_back(inorder);
    ans.push_back(preorder);
    ans.push_back(postorder);
    return ans;
}

    int main(){
// Build main tree (root)
    TreeNode* root = new TreeNode(3);  // using constructor 
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
        vector<vector<int>> an = getTreeTraversal(root);
        for(int i=0;i<an.size();i++){
            for(int j=0;j<an[i].size();j++){
                cout<<an[i][j]<<" ";
            }
            cout<<endl;
            
        }        
    return 0;
}

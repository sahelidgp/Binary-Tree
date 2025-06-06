#include <iostream>
#include <cstdlib> // for malloc c style 
using namespace std;

// Define TreeNode structure
struct TreeNode {
    
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode(int data){
        val = data;
        left = nullptr;
        right = nullptr;
    }
};

// Function to create a new node
TreeNode* newNode(int data) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    // cout<<sizeof(TreeNode)<<endl;
    node->val = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

// Solution class with isSubtree and isSameTree methods
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr || q == nullptr) {
            return p == q;
        }
        return (p->val == q->val) &&
               isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) return subRoot == nullptr;
        if (isSameTree(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    
};

int main() {
    // Build main tree (root)
    TreeNode* root = new TreeNode(3);  // using constructor 
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    // Build subtree (subRoot)
    TreeNode* subRoot = newNode(4); // using newNode function
    subRoot->left = newNode(1);
    subRoot->right = newNode(2);

    // Create Solution object and call isSubtree
    Solution sol;
    if (sol.isSubtree(root, subRoot)) {
        std::cout << "subRoot is a subtree of root." << std::endl;
    } else {
        std::cout << "subRoot is NOT a subtree of root." << std::endl;
    }

    return 0;
}

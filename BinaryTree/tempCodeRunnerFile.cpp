TreeNode* newNode(int data) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->val = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

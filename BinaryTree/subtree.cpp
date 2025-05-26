class Solution{
    public:
        bool isSameTree(TreeNode* p,TreeNode* q){
            if(p == nullptr || q == nullptr){
                return p == q;
            }
            bool isLeftSame = isSameTree(p->left, q->left);
            bool isRightSame = isSameTree(p->right, q->right);

            return isLeftSame && isRightSame && p->val == q->val; 
        }

        bool isSubtree(TreeNode* root,TreeNode* subroot){
            if(root == nullptr || subroot == nullptr){
                return root  == subroot;
            }
            if(root->val == subroot->val && isSameTree(root,subroot)){
                return true;
            }
            return isSubtree(root->left,subroot) || isSubtree(root->right,subroot);
        }
};
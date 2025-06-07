# Number of Nodes Complete Binary Tree 🔥
# (づ｡◕‿‿◕｡)づ ❤️

## problem link :
 [click here](https://leetcode.com/problems/count-complete-tree-nodes/)
## explanation
## 🔥 What's actually happening in the code?
We're not building a heap or an actual array.
We're using i to simulate the array index of the last node in a complete binary tree using index math:

In a complete binary tree, if we think of the tree as being stored in an array (heap-style), then:

The last node's index gives us the total number of nodes → i + 1.

🔍 The Core Insight:
In a complete binary tree:

If height(left) == height(right) → the left subtree is perfect and completely filled.

So the last node must be in the right subtree.

The number of nodes in the left subtree is 2^h - 1 (where h = height).

So root index i, right child is at 2*i + 2, hence we update i = 2*i + 2 and go right.

Else → the right subtree is perfect, but of smaller height.

So the last node is in the left subtree.

Hence we update i = 2*i + 1 and go left.

✅ Rewriting with Correct Intuition:
cpp
Copy
Edit
class Solution {
public:
    int ht(TreeNode* r){
        int i = 0;
        while(r){
            i++;
            r = r->left;
        }
        return i;
    }

    void check(TreeNode* r, int& i){
        if(r->left){
            if(ht(r->left) == ht(r->right)){
                // Left is perfect → go to right
                i = 2*i + 2;
                check(r->right, i);
            } else {
                // Right is perfect but smaller → go to left
                i = 2*i + 1;
                check(r->left, i);
            }
        }
    }

    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        int i = 0;
        check(root, i);
        return i + 1;  // final node index + 1 = total count
    }
};
🌳 Example:
For this tree:


        1
       / \
      2   3
     / \  /
    4  5 6
Let’s simulate:

root = 1, i = 0

ht(2) == ht(3) → go right, i = 2*0 + 2 = 2

root = 3, i = 2

ht(6) ≠ ht(null) → go left, i = 2*2 + 1 = 5

root = 6 → done

Final i = 5 ⇒ total nodes = 5 + 1 = 6

🧠 Summary:
We don’t need to build an array — i simulates the index of the last node.

Each i value mimics the index the node would occupy if stored in a heap-like array.

This lets us efficiently determine the node count in O(log² N) time.

Thanks for pointing that out. You're clearly understanding the d

# CODE
 ```c++
 struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val = val;
        this->left = nullptr;
        this->right  = nullptr;
    }
 }
class Solution {
public:
    int ht(TreeNode* r){
        int i=0;
        while(r!=NULL){
            i++;
            r=r->left;
        }
        return i;
    }
    void check(TreeNode* r,int& i){
        if(r->left!=NULL){
            if(ht(r->left)==ht(r->right)){
                i=2*i+2;
                check(r->right,i);
            }else{
                i=2*i+1;
                check(r->left,i);
            }
        }
    }
    int countNodes(TreeNode* root) {
        int i=0;
        if(root==NULL) return 0;
        check(root,i);
        return i+1;
    }
};

```
# Another method O(log^2 N)
# CODE
```c++
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr)return 0;

        int lh = findHeightLeft(root);
        int rh = findHeightRight(root);

        if(lh == rh) return (1<<lh)-1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    int findHeightLeft(TreeNode* node){
        int height = 0;
        while(node){
            height++;
            node = node->left;
        }
        return height;
    }
    int findHeightRight(TreeNode* node){
        int height = 0;
        while(node){
            height++;
            node = node->right;
        }
        return height;
    }
};
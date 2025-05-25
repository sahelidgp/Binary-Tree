#include<iostream>
#include<vector>
using namespace std;
#include<queue>
class Node{
    public:
        int data;
        Node*left;
        Node*right;

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
//Pre Order Traversal  O(n)
void preOrder(Node* root){
    if(root == nullptr){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

//inorder tarversal  //O(n)
void inOrder(Node* root){
    if(root == nullptr){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

//postorder traversal -  O(n)
void postOrder(Node* root){
    if(root == nullptr){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

//level order traversal
void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(nullptr);
    while(q.size()>0){
        Node* curr = q.front();
        q.pop();

        if(curr == nullptr){
            if(!q.empty()){
            cout<<endl;
            q.push(nullptr);
            continue;
        }else {
            break;
        }
     }
     cout<<curr->data<<" ";
        if(curr->left != nullptr){
            q.push(curr->left);
        }
        if(curr->right != nullptr){
            q.push(curr->right);
        }
    }

    cout<<endl;
}
int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root = buildTree(preorder);
    cout<<root->data<<endl;
    cout<<root->left->data<<endl;
    cout<<root->right->data<<endl;

    preOrder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    levelOrder(root);
    return 0;
}

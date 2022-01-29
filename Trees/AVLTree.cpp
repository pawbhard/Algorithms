#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    int height;
    TreeNode() : val(0), left(nullptr), right(nullptr) , height(0) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr), height(0) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) , height(0) {}
};

int getHeight(TreeNode *root) {
    if (root) return root->height;
    return -1;
}

void setHeight(TreeNode *root, int height) {
    if (root)
        root->height = height;
}

void updateHeight(TreeNode *node) {
    setHeight(node, 1 + max(getHeight(node->left), getHeight(node->right)));
}

TreeNode* leftRotate (TreeNode *x) {
    if(!x->right) return x; //not possible

    TreeNode* y = x->right;
    x->right = y->left;
    y->left = x;

    updateHeight(x);
    updateHeight(y); 

    return y;
}

TreeNode* rightRotate(TreeNode *x) {
    if(!x->left) return x; //not possible

    TreeNode* y = x->left;
    x->left = y->right;
    y->right = x;
    
    updateHeight(x);
    updateHeight(y); 
    return y;
}

TreeNode* insertNode(TreeNode *root, TreeNode* n) {
    if (!root) return n;
    if (!n) return root;
    if (root->val < n->val) {
        root->right = insertNode(root->right, n);
    } else if (root->val > n->val) {
        root->left = insertNode(root->left, n);
    } else {
        return root;
    }

    updateHeight(root);

    int balance = getHeight(root->left) - getHeight(root->right);

    //Already balanced
    if (abs(balance) <= 1) return root;

    if (balance < -1) {
        //Right heavy
        
        if (n->val > root->right->val) {
            //Right-Right case
            return leftRotate(root);
        } else {
            //RIGHT- left case
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

    } else if (balance > 1) {
        //left heavy
        if(n->val > root->left->val) {
            //Left right case
            return rightRotate(root);
        } else {
            //left left case
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }

    return root;
}
void inorder(TreeNode * root) {
    if (!root) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

int main() {
    srand(time(0));
    TreeNode *root = NULL;
    int sz = 20;
    for(int i = 0; i < 1<<sz; i++) {
        int val = rand();
        TreeNode *n = new TreeNode(val);
        root = insertNode(root, n);
    }
    cout<<"Inorder : ";
    inorder(root);
    cout<<"\n";

    cout<<"Height of root node "<<root->height<<"\n";
    
    return 0;
}
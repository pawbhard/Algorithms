//
//https://leetcode.com/problems/house-robber-iii/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

pair<int,int> rob1(TreeNode* root) {
    if (root == nullptr) return {0, 0};

    pair<int, int> ans_left, ans_right, ans;
    ans_left = rob1(root->left);
    ans_right = rob1(root->right);

    //with root
    ans.first = root->val + ans_left.second +  ans_right.second;
    ans.second = max(ans_left.first, ans_left.second) + max(ans_right.second, ans_right.first);

    return ans;
}

int  rob(TreeNode *root) {
    pair<int,int> ans = rob1(root);
    return max(ans.first, ans.second);
}

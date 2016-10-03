//
// Binary Tree Inorder Traversal
// Created by Rayn on 2016/10/3.
//
#include <map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void inorderDfs(TreeNode* root, vector<int>& ret) {
        if (root->left) inorderDfs(root->left, ret);
        ret.push_back(root->val);
        if (root->right) inorderDfs(root->right, ret);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (root == NULL) return ret;
        inorderDfs(root, ret);
        return ret;
    }
};

int main() {
    Solution solution;
    return 0;
}


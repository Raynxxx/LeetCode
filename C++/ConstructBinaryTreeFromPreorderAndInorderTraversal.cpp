//
// Created by Rayn on 16/9/26.
//
#include <map>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef pair<TreeNode*, int> Node;

class Solution {
public:
    template <typename Iter>
    TreeNode* parse(Iter begin1, Iter end1, Iter begin2, Iter end2) {
        if (begin1 == end1 || begin2 == end2) return nullptr;
        int root_val = *begin1;
        Iter inorder_root = find(begin2, end2, root_val);
        TreeNode* root = new TreeNode(root_val);
        int left_size = inorder_root - begin2;
        root->left = parse(begin1 + 1, begin1 + 1 + left_size, begin2, inorder_root);
        root->right = parse(begin1 + 1 + left_size, end1, inorder_root + 1, end2);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return nullptr;
        return parse(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
};

int main() {
    Solution solution;
    return 0;
}
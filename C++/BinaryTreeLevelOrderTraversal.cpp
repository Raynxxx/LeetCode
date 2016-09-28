//
// Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == NULL) return ret;
        queue<Node> tree_queue;
        tree_queue.push(make_pair(root, 0));
        while (!tree_queue.empty()) {
            Node cur = tree_queue.front();
            tree_queue.pop();

            TreeNode* cur_node = cur.first;
            int level = cur.second;

            if (cur_node->left) {
                tree_queue.push(make_pair(cur_node->left, level + 1));
            }
            if (cur_node->right) {
                tree_queue.push(make_pair(cur_node->right, level + 1));
            }
            if (ret.size() <= level) {
                ret.push_back(vector<int>());
            }
            ret[level].push_back(cur_node->val);
        }
        return ret;
    }
};


int main() {
    Solution solution;
    return 0;
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <unordered_map>

class Solution {
public:
    unordered_map<TreeNode *, int> depths;

    int depth(TreeNode * root) {
        if (!root) {
            return 0;
        }

        if (depths.contains(root)) {
            return depths[root];
        }
        depths[root] = 1 + std::max(depth(root->left), depth(root->right));
        return depths[root];
    }

    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }

        int lDepth = depth(root->left);
        int rDepth = depth(root->right);
        return std::abs(lDepth - rDepth) < 2 && isBalanced(root->left) && isBalanced(root->right);    
    }
};
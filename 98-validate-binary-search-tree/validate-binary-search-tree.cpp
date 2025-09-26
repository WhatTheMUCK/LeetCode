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

#include <limits>

class Solution {
public:
    bool isValidBST(TreeNode * root, long long minValue, long long maxValue) {
        if (!root) {
            return true;
        }

        if (minValue >= root->val || root->val >= maxValue) {
            return false;
        }

        return isValidBST(root->left, minValue, root->val) && isValidBST(root->right, root->val, maxValue);
    }

    bool isValidBST(TreeNode* root) {
        return isValidBST(root, std::numeric_limits<long long>::min(), std::numeric_limits<long long>::max());
    }
};
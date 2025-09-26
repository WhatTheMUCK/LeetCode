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
class Solution {
public:
    bool isSymmetric(TreeNode * lhs, TreeNode * rhs) {
        if (!lhs && !rhs) {
            return true;
        }

        if (!lhs || !rhs || lhs->val != rhs->val) {
            return false;
        }

        return isSymmetric(lhs->left, rhs->right) && isSymmetric(lhs->right, rhs->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        
        return isSymmetric(root->left, root->right);
    }
};
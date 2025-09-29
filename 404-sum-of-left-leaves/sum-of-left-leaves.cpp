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
    int sumOfCorrectLeaves(TreeNode * root, bool isLeft) {
        if (!root) {
            return 0;
        }

        if (!root->left && !root->right && isLeft) {
            return root->val;
        }

        return sumOfCorrectLeaves(root->left, true) + sumOfCorrectLeaves(root->right, false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return sumOfCorrectLeaves(root, false);
    }
};
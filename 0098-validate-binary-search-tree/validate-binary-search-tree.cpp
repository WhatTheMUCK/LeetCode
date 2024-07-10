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
    bool isValidBST(TreeNode* root, long long maximum = 1e11, long long minimum = -1e11){
        if (!root)
            return true;
        if (root->val >= maximum || root->val <= minimum)
            return false;
        return isValidBST(root->left, root->val, minimum) && isValidBST(root->right, maximum, root->val);
    }
};
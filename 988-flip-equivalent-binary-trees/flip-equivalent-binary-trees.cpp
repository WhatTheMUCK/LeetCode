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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2)
            return true;
        if (!(root1 && root2) || root1->val != root2->val)
            return false;
        TreeNode *root1L = root1->left, *root1R = root1->right;
        TreeNode *root2L = root2->left, *root2R = root2->right;
        if (root1L && root2L && root2L->val == root1L->val || !root1L && !root2L)
            return flipEquiv(root1L, root2L) && flipEquiv(root1R, root2R);
        else
            return flipEquiv(root1L, root2R) && flipEquiv(root1R, root2L);
    }
};
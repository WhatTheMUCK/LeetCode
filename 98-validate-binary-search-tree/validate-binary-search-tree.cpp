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
    bool dfs(TreeNode* root, long long maximum, long long minimum){
        if (root == nullptr){
            return true;
        }
        if ((long long)root->val >= maximum || (long long)root->val <= minimum){
            return false;
        }

        return dfs(root->left, root->val, minimum) && dfs(root->right, maximum, root->val);
    }

    bool isValidBST(TreeNode* root) {
        return dfs(root, (long long)INT_MAX + 1, (long long)INT_MIN - 1);
    }
};
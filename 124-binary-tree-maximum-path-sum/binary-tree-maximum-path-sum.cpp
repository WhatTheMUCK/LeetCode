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
    int dfs(TreeNode *root, int &ans){
        if (!root) return 0;
        int lmax = max(dfs(root->left, ans), 0);
        int rmax = max(dfs(root->right, ans), 0);
        ans = max(ans, lmax + rmax + root->val);
        return max(lmax, rmax) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        dfs(root, ans);
        return ans;
        
    }
};
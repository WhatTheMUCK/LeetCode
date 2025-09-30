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
    unordered_map<TreeNode *, int> mp;
    int sum(TreeNode * root) {
        if (!root) {
            mp[root] = 0;
            return mp[root];
        }

        if (mp.contains(root)) {
            return mp[root];
        }

        mp[root] = root->val + sum(root->left) + sum(root->right);
        return mp[root];
    }

    int tilt(TreeNode * root) {
        if (!root) {
            return 0;
        }

        return abs(mp[root->left] - mp[root->right]) + tilt(root->left) + tilt(root->right);
    }

    int findTilt(TreeNode* root) {
        sum(root);
        return tilt(root);
    }
};
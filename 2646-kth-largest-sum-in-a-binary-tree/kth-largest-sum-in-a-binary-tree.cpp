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
    vector<long long> levelSums;
    void dfs(TreeNode* root, int height){
        if (!root)
            return;
        int n = levelSums.size();
        if (height == n)
            levelSums.push_back(root->val);
        else
            levelSums[height] += root->val;
        dfs(root->left, height + 1);
        dfs(root->right, height + 1);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        dfs(root, 0);
        int n = levelSums.size();
        if (n < k)
            return -1;
        sort(levelSums.begin(), levelSums.end(), greater<long long>());
        return levelSums[k - 1];
    }
};
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
    void dfs(TreeNode* root, int level){
        if (!root)
            return;
        TreeNode *rightBrother = root->right, *leftBrother = root->left;
        int right = 0;
        if (rightBrother){
            right = rightBrother->val;
            rightBrother->val = levelSums[level + 1] - (right + (leftBrother ? leftBrother->val : 0));
            dfs(rightBrother, level + 1);
        }
        if (leftBrother){
            leftBrother->val = levelSums[level + 1] - (leftBrother->val + right);
            dfs(leftBrother, level + 1);
        }
        return;

    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> tree;
        tree.push({root, 0});
        while (!tree.empty()){
            TreeNode* curNode;
            int curLevel;
            tie(curNode, curLevel) = tree.front();
            tree.pop();
            int n = levelSums.size();
            if (curLevel == n)
                levelSums.push_back(curNode->val);
            else
                levelSums[curLevel] += curNode->val;
            if (curNode->left)
                tree.push({curNode->left, curLevel + 1});
            if (curNode->right)
                tree.push({curNode->right, curLevel + 1});
        }

        root->val = 0;
        dfs(root, 0);
        return root;
    }
};
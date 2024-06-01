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
    int helper(TreeNode* root, int &answer){
        if (!root)
            return 0;
        int lmax = -1, rmax = -1;
        if (root->left)
            lmax = helper(root->left, answer);
        if (root->right)
            rmax = helper(root->right, answer);
        answer = max(answer, lmax + 1 + rmax + 1);
        return max(lmax, rmax) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root, int answer = 0) {
        helper(root, answer);
        return answer;
    }
};
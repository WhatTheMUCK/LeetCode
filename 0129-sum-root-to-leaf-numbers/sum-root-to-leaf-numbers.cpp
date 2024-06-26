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

   int helper(TreeNode* root, int sum) {
        if (root == nullptr){
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr){
            return sum * 10 + root->val;
        }
        return helper(root->left, sum * 10 + root->val) + helper(root->right, sum * 10 + root->val);
    }
    
    int sumNumbers(TreeNode* root){
        int sum = 0;
        return helper(root, sum);
     }
};
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
    void leftLeaf(TreeNode* root, int &sum){
        if (root == nullptr){
            return;
        }
        TreeNode *left = root->left;
        if (left == nullptr){
            leftLeaf(root->right, sum);
            return;
        }
        TreeNode *right = root->right;
        if (left->left == nullptr && left->right == nullptr){
            sum += left->val;
        }
        leftLeaf(root->left, sum);
        leftLeaf(root->right, sum);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int answer = 0;
        leftLeaf(root, answer);
        return answer;
    }
};
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
    void DFS(TreeNode* root, vector<int> &leafs){
        if (!root)
            return;
        if (!root->right && !root->left){
            leafs.push_back(root->val);
            return;
        }
        DFS(root->left, leafs), DFS(root->right, leafs);
        return;
            
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> first, second;
        DFS(root1, first), DFS(root2, second);
        return first == second;
    }
};
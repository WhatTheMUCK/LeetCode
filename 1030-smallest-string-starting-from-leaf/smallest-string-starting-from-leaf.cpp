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
    void helper(TreeNode* root, string temp, string &answer){
        temp.push_back(root->val + 'a');
        if (root->left == nullptr && root->right == nullptr){
            reverse(temp.begin(), temp.end());
            if (answer.empty() || temp < answer){
                answer = temp;
            }
            reverse(temp.begin(), temp.end());
        } else {
            if (root->left != nullptr)
                helper(root->left, temp, answer);
            if (root->right != nullptr)
                helper(root->right, temp, answer);
        }
    }
    
    string smallestFromLeaf(TreeNode* root) {
        string answer = "", temp = "";
        helper(root, temp, answer);
        return answer;
    }
};
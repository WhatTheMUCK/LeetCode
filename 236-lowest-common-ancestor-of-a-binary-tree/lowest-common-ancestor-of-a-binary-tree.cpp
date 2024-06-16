/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int search(TreeNode* cur, TreeNode* p, TreeNode* q, TreeNode* &answer){
    int result = 0;
    if (!cur)
        return 0;
    if (cur == p)
        result = 1;
    if (cur == q)
        result = 2;
    result = result ^ search(cur->left, p, q, answer) ^ search(cur->right, p, q, answer);
    if (result == 3){
        answer = cur;
        result = 0;
    }
    return result;
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* answer;
        search(root, p, q, answer);
        return answer;
    }
};
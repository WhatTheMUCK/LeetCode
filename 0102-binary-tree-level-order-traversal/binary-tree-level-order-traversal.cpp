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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*, int>> bfs;
        vector<vector<int>> answer;
        if (root)
            bfs.push({root, 1});
        while (!bfs.empty()){
            auto [cur, level] = bfs.front();
            bfs.pop();
            if (level > answer.size()){
                answer.push_back({});
            }
            answer[level - 1].push_back(cur->val);
            if (cur->left)
                bfs.push({cur->left, level + 1});
            if (cur->right)
                bfs.push({cur->right, level + 1});
        }
        return answer;

    }
};
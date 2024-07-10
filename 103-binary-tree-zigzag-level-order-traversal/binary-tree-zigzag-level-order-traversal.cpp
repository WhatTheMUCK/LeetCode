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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        queue<pair<TreeNode*, int>> bfs;
        if (root)
            bfs.push({root, 1});
        while (!bfs.empty()){
            auto [cur, level] = bfs.front();
            bfs.pop();
            if (!cur)
                continue;
            if (level > answer.size())
                answer.push_back({});
            answer[level - 1].push_back(cur->val);
            bfs.push({cur->left, level + 1});
            bfs.push({cur->right, level + 1}); 
        }
        for (int i = 1; i < answer.size(); i += 2){
            reverse(answer[i].begin(), answer[i].end());
        }
        return answer;
    }
};
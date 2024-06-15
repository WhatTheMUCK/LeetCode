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
        if (!root)
            return {};
        queue<pair<int, TreeNode*>> bfs;
        vector<vector<int>> answer;
        bfs.push({1, root});
        while (!bfs.empty()){
            auto [ind, cur] = bfs.front();
            bfs.pop();
            if (!cur)
                continue;
            if (answer.size() < ind){
                answer.push_back({});
            }
            answer.back().push_back(cur->val);
            bfs.push({ind + 1, cur->left});
            bfs.push({ind + 1, cur->right});
        }
        return answer;
    }
};
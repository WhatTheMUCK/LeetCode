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
        std::vector<std::vector<int>> answer;
        std::queue<std::pair<TreeNode *, int>> nodes;
        int curLvl = 0;
        nodes.push({root, curLvl});
        while (!nodes.empty()) {
            auto [node, lvl] = nodes.front();
            nodes.pop();
            if (node == nullptr) {
                continue;
            }
            if (lvl == answer.size()) {
                answer.push_back({node->val});
            } else {
                answer[lvl].push_back(node->val);
            }
            ++lvl;
            nodes.push({node->left, lvl});
            nodes.push({node->right, lvl});
        }
        return answer;
    }
};
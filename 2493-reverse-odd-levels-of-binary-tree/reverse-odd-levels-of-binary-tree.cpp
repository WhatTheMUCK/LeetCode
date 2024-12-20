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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<pair<TreeNode*, int>> bfs;
        bfs.push({root, 0});
        vector<TreeNode*> oddLevel;
        while (!bfs.empty()){
            auto [vertex, level] = bfs.front();
            bfs.pop();
            int n = oddLevel.size();
            if (level % 2 == 0 && n > 0){
                for (int i = 0; i < n / 2; i++){
                    swap(oddLevel[i]->val, oddLevel[n - (i + 1)]-> val);
                }
                oddLevel = {};
            }
            if (!vertex){
                break;
            }
            if (level % 2 == 1){
                oddLevel.push_back(vertex);
            }
            bfs.push({vertex->left, level + 1});
            bfs.push({vertex->right, level + 1});
        }
        return root;
    }
};
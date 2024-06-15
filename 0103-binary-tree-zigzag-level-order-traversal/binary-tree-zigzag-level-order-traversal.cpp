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
typedef struct{
    TreeNode* node;
    int level;
}custom;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<deque<int>> temp;
        queue<custom> bfs;
        bfs.push({root, 0});
        while (!bfs.empty()){
            auto [cur, level] = bfs.front();
            bfs.pop();
            if (!cur)
                continue;
            if (level == temp.size()){
                temp.push_back(deque<int>());
            }
            if (level % 2 == 0)
                temp[level].push_back(cur->val);
            else
                temp[level].push_front(cur->val);
            bfs.push({cur->left, level + 1});
            bfs.push({cur->right, level + 1});
        }
        vector<vector<int>> answer;
        for (deque<int> &deq : temp){
            answer.push_back(vector<int>(deq.begin(), deq.end()));
        }
        return answer;
    }
};